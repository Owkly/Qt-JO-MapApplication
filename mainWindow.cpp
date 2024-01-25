// mainWindow.cpp
#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include "detailedWindow.hpp"
#include "dataManager.hpp"
#include "epreuve.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Configuration de l'attribut ui (User Interface)
    ui->setupUi(this);

    // Configuration des attributs listeEpreuves et listeRestaurants à partir du fichier JSON
    DataManager dataManager(":/lieux.json");
    listeEpreuves = dataManager.toListEpreuves();
    listeRestaurants = dataManager.toListRestaurants();

    // Configuration de l'attribut scrollAreaLayout où seront ajoutés les widgets des épreuves
    scrollAreaLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);

    // Connexion des signaux pour les boutons de navigation
    connect(ui->openInfoMainButton, SIGNAL(clicked()), this, SLOT(openInfoMain()));
    connect(ui->openMapMainButton, SIGNAL(clicked()), this, SLOT(openMapMain()));
    connect(ui->openDetailedInfoButton, SIGNAL(clicked()), this, SLOT(openDetailedInfo()));
    // Connexion des signaux pour la barre de recherche
    connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(searchItem()));
    connect(ui->inputArea, SIGNAL(returnPressed()), this, SLOT(searchItem()));
    connect(ui->filterComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(searchItem()));

    scrollAreaLayout->setAlignment(Qt::AlignTop);
    // À la fin de l'ajout de tous les widgets à scrollAreaLayout
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Méthode pour ouvrir la page d'information
void MainWindow::openInfoMain()
{
    ui->stackedWidget->setCurrentIndex(1);
    setupItemsScrollArea(listeEpreuves);
    setupItemsScrollArea(listeRestaurants);
    addVerticalSpacerToEnd();
}

// Méthode pour ouvrir la page de la carte
void MainWindow::openMapMain()
{
    ui->stackedWidget->setCurrentIndex(2);
}

// Méthode pour voir les détails d'une épreuve ou d'un restaurant dans la page d'information
void MainWindow::openDetailedInfo()
{
    DataManager dataManager("lieux.json");
    QVector<Epreuve> epreuves = dataManager.toListEpreuves();
    if (!epreuves.isEmpty())
    {
        Epreuve premiereEpreuve = epreuves.first();
        QString details = "Nom : " + premiereEpreuve.getNom() + "\n"
                                                                "Adresse : " +
                          premiereEpreuve.getAdresse() + "\n"
                                                         "Prix Billet : " +
                          premiereEpreuve.getPrixBillet() + "€\n"
                                                            "Description : " +
                          premiereEpreuve.getDescription();
        DetailedWindow detailedWindow(this);
        detailedWindow.setModal(true);
        detailedWindow.setDetails(details); // Passez les détails à la fenêtre de dialogue
        detailedWindow.exec();
    }
}

// Ajout des infos (nom, adresse, horaire) au Layout (3)
void MainWindow::addEpreuveLabels(QVBoxLayout *nameAdressTimeLayout, const Epreuve &epreuve)
{
    QLabel *nomLabel = new QLabel(epreuve.getNom());
    QLabel *adresseLabel = new QLabel(epreuve.getAdresse());
    QDateTime horaireDebut = epreuve.getHoraireDebut();
    QString horaireDebutTexte = horaireDebut.toString("dd/MM/yyyy - hh:mm:ss");
    QLabel *horaireLabel = new QLabel(horaireDebutTexte);
    for (auto label : {nomLabel, adresseLabel, horaireLabel})
    {
        configureLabel(label);
        nameAdressTimeLayout->addWidget(label);
    }
}

// Ajout des infos (nom, adresse, horaire) au Layout (3)
void MainWindow::addRestaurantLabels(QVBoxLayout *nameAdressTimeLayout, const Restaurant &restaurant)
{
    QLabel *nomLabel = new QLabel(restaurant.getNom());
    QLabel *adresseLabel = new QLabel(restaurant.getAdresse());
    QLabel *plageHoraireLabel = new QLabel(restaurant.getPlageHoraire());
    for (auto label : {nomLabel, adresseLabel, plageHoraireLabel})
    {
        configureLabel(label);
        nameAdressTimeLayout->addWidget(label);
    }
}

// Configuration des labels du Layout (3)
void MainWindow::configureLabel(QLabel *label)
{
    // label->setFixedWidth(1500);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    // Exemple pour définir une couleur de fond à un QLabel pour le débogage
    label->setStyleSheet("QLabel { background-color: orange; }");
}

// Méthode pour ajouter un espaceur vertical
void MainWindow::addVerticalSpacerToEnd()
{
    // L'espaceur aura une hauteur minimale et une politique extensible pour pousser les éléments vers le haut
    scrollAreaLayout->addStretch(1);
}

// Méthode pour supprimer tout les widgets de la scrollAreaLayout
void MainWindow::clearScrollArea()
{
    QLayoutItem *item;
    while ((item = scrollAreaLayout->takeAt(0)) != nullptr)
    {
        delete item->widget();
        delete item;
    }
}

// Méthode pour rechercher un item (épreuve ou restaurant) dans la scrollAreaLayout
void MainWindow::searchItem()
{
    // Récupérez le texte inséré dans la barre de recherche en supprimant les espaces puis récupérez le filtre sélectionné
    QString searchText = ui->inputArea->text().trimmed();
    QString selectedFilter = ui->filterComboBox->currentText();
    clearScrollArea();

    // Filtrer les épreuves dont le nom ou l'adresse contient le texte recherché peu importe la casse (majuscule/minuscule)
    if (selectedFilter == "Tout" || selectedFilter == "Epreuves")
    {
        for (const Epreuve &epreuve : listeEpreuves)
        {
            if (epreuve.getNom().contains(searchText, Qt::CaseInsensitive) || epreuve.getAdresse().contains(searchText, Qt::CaseInsensitive))
            {
                addItemToScrollArea(epreuve);
            }
        }
    }
    // Faites les restaurants dont le nom ou l'adresse contient le texte recherché peu importe la casse (majuscule/minuscule)
    if (selectedFilter == "Tout" || selectedFilter == "Restaurants")
    {
        for (const Restaurant &restaurant : listeRestaurants)
        {
            if (restaurant.getNom().contains(searchText, Qt::CaseInsensitive) || restaurant.getAdresse().contains(searchText, Qt::CaseInsensitive))
            {
                addItemToScrollArea(restaurant);
            }
        }
    }
    addVerticalSpacerToEnd();
}
