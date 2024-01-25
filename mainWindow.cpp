// mainWindow.cpp
#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include "detailedWindow.hpp"
#include "dataManager.hpp"
#include "event.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Configuration de l'attribut ui (User Interface)
    ui->setupUi(this);
    this->setWindowTitle("JO 2024");
    this->showMaximized();

    // Configuration des attributs listEvents et listRestaurants à partir du fichier JSON
    DataManager dataManager(":/lieux.json");
    listEvents = dataManager.toListEvents();
    listRestaurants = dataManager.toListRestaurants();

    // Configuration de l'attribut scrollAreaLayout où seront ajoutés les widgets des épreuves
    scrollAreaLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);

    // Connexion des signaux pour les boutons de navigation
    connect(ui->openInfoMainButton, SIGNAL(clicked()), this, SLOT(openInfoMain()));
    connect(ui->openMapMainButton, SIGNAL(clicked()), this, SLOT(openMapMain()));
    // Connexion des signaux pour la barre de recherche
    connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(searchItem()));
    connect(ui->inputArea, SIGNAL(returnPressed()), this, SLOT(searchItem()));
    connect(ui->filterComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(searchItem()));

    // Configuration de la couleur de fond de la scrollArea
    ui->scrollArea->setStyleSheet("QWidget { background-color: #fffae5; }");    
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Méthode pour ouvrir la page d'information
void MainWindow::openInfoMain()
{
    ui->stackedWidget->setCurrentIndex(1);
    setupItemsScrollArea(listEvents);
    setupItemsScrollArea(listRestaurants);
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
    QVector<Event> events = dataManager.toListEvents();
    if (!events.isEmpty())
    {
        Event premiereEvent = events.first();
        QString details = "Nom : " + premiereEvent.getName() + "\n"
                                                               "Adresse : " +
                          premiereEvent.getAddress() + "\n"
                                                       "Prix Billet : " +
                          premiereEvent.getTicketPrice() + "€\n"
                                                           "Description : " +
                          premiereEvent.getDescription();
        DetailedWindow detailedWindow(this);
        detailedWindow.setModal(true);
        detailedWindow.setDetails(details); // Passez les détails à la fenêtre de dialogue
        detailedWindow.exec();
    }
}

// Ajout des infos (nom, adresse, horaire) au Layout (3)
void MainWindow::addEventLabels(QVBoxLayout *nameAdressTimeLayout, const Event &event)
{
    QLabel *nomLabel = new QLabel(event.getName());
    QLabel *adresseLabel = new QLabel(event.getAddress());
    QDateTime horaireDebut = event.getStartTime();
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
    QLabel *nomLabel = new QLabel(restaurant.getName());
    QLabel *adresseLabel = new QLabel(restaurant.getAddress());
    QLabel *plageHoraireLabel = new QLabel(restaurant.getOpeningHours());
    for (auto label : {nomLabel, adresseLabel, plageHoraireLabel})
    {
        configureLabel(label);
        nameAdressTimeLayout->addWidget(label);
    }
}

// Configuration des labels du Layout (3)
void MainWindow::configureLabel(QLabel *label)
{
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    label->setStyleSheet("QLabel { "
                         "background-color: #D7C379; " // Couleur de fond plus douce
                         "border: 1px solid #CCCCCC; " // Bordure subtile
                         "}");
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
        for (const Event &event : listEvents)
        {
            if (event.getName().contains(searchText, Qt::CaseInsensitive) || event.getAddress().contains(searchText, Qt::CaseInsensitive))
            {
                addItemToScrollArea(event);
            }
        }
    }
    // Faites les restaurants dont le nom ou l'adresse contient le texte recherché peu importe la casse (majuscule/minuscule)
    if (selectedFilter == "Tout" || selectedFilter == "Restaurants")
    {
        for (const Restaurant &restaurant : listRestaurants)
        {
            if (restaurant.getName().contains(searchText, Qt::CaseInsensitive) || restaurant.getAddress().contains(searchText, Qt::CaseInsensitive))
            {
                addItemToScrollArea(restaurant);
            }
        }
    }
    addVerticalSpacerToEnd();
}

void MainWindow::showDetails(const QString &details)
{
    DetailedWindow detailedWindow(this);
    detailedWindow.setModal(true);
    detailedWindow.setDetails(details);
    detailedWindow.exec();
}
