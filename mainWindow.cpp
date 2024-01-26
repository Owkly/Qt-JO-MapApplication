// mainWindow.cpp
#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include "detailedWindow.hpp"
#include "dataManager.hpp"
#include "event.hpp"

// Constructeur
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), dataManager("lieux.json")
{
    // Configuration de base : configuration de l'interface utilisateur et affichage en plein écran
    this->setWindowTitle("JO 2024");
    this->showFullScreen();
    ui->setupUi(this);

    scrollAreaLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    ui->scrollArea->setStyleSheet("QWidget { background-color: #fffbeb; }");

    // Connexion des signaux pour les boutons de navigation, et de la barre de recherche
    connect(ui->openInfoMainButton, SIGNAL(clicked()), this, SLOT(openInfoMain()));
    connect(ui->openMapMainButton, SIGNAL(clicked()), this, SLOT(openMapMain()));
    connect(ui->openHomeMainButton, SIGNAL(clicked()), this, SLOT(openHomeMain()));
    connect(ui->quitMainButton, SIGNAL(clicked()), this, SLOT(closeMain()));

    connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(searchItem()));
    connect(ui->inputArea, SIGNAL(returnPressed()), this, SLOT(searchItem()));
    connect(ui->filterComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(searchItem()));
}

// Destructeur
MainWindow::~MainWindow()
{
    delete ui;
}

// Méthode pour ouvrir la page d'accueil (ouvre le 1er stackedWidget)
void MainWindow::openHomeMain()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// Méthode pour fermer la fenêtre
void MainWindow::closeMain()
{
    this->close();
}

// Méthode pour ouvrir la page d'information (ouvre le 2ème stackedWidget et affiche les épreuves et restaurants)
void MainWindow::openInfoMain()
{
    ui->stackedWidget->setCurrentIndex(1);
    setupItemsScrollArea(dataManager.getListEvents());
    setupItemsScrollArea(dataManager.getListRestaurants());
    addVerticalSpacerToEnd();
}

// Méthode pour ouvrir la page de la carte (ouvre le 3ème stackedWidget et charge les données depuis le fichier QML)
void MainWindow::openMapMain()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->mapViewWidget->setSource(QUrl(QStringLiteral("qrc:/Map.qml")));
    ui->mapViewWidget->show();
}

// Ajout des infos (nom, adresse, horaire) au Layout (3)
void MainWindow::addEventLabels(QVBoxLayout *nameAdressTimeLayout, const Event &event)
{
    QLabel *nomLabel = new QLabel(event.getName());
    QLabel *adresseLabel = new QLabel(event.getAddress());
    QDateTime horaireDebut = event.getStartTime();
    QString horaireDebutTexte = horaireDebut.toString("dd/MM/yyyy - hh:mm:ss"); // UNIQUEMENT POUR LES ÉPREUVES
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
    QLabel *plageHoraireLabel = new QLabel(restaurant.getOpeningHours()); // UNIQUEMENT POUR LES RESTAURANTS
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
                         "background-color: #D7C379; " // Couleur jaune marron
                         "border: 1px solid #CCCCCC; " // Bordure subtile
                         "}");
}

// Méthode pour ajouter un espaceur vertical
void MainWindow::addVerticalSpacerToEnd()
{
    scrollAreaLayout->addStretch(1);
}

// Méthode pour supprimer le contenu de la scrollAreaLayout
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
    // Récupération du texte de recherche et du filtre et suppression du contenu de la scrollAreaLayout
    QString searchText = ui->inputArea->text().trimmed();
    QString selectedFilter = ui->filterComboBox->currentText();
    clearScrollArea();

    // Ajout des épreuves et restaurants correspondant à la recherche dans la scrollAreaLayout
    QVector<Event> filteredEvents = dataManager.searchEvents(searchText, selectedFilter);
    for (const Event &event : filteredEvents)
    {
        addItemToScrollArea(event);
    }
    QVector<Restaurant> filteredRestaurants = dataManager.searchRestaurants(searchText, selectedFilter);
    for (const Restaurant &restaurant : filteredRestaurants)
    {
        addItemToScrollArea(restaurant);
    }

    addVerticalSpacerToEnd();
}

// Méthode pour afficher dans un dialogue les détails de l'item sélectionné
void MainWindow::showDetails(const QString &details)
{
    DetailedWindow detailedWindow(this);
    detailedWindow.setModal(true);  // Bloque l'interaction avec la fenêtre principale tant que la fenêtre détaillée est ouverte
    detailedWindow.setDetails(details);
    detailedWindow.exec();
}
