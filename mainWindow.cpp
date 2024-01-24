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

    // Connecter les signaux aux slots
    connect(ui->openInfoMainButton, SIGNAL(clicked()), this, SLOT(openInfoMain()));
    connect(ui->openMapMainButton, SIGNAL(clicked()), this, SLOT(openMapMain()));
    connect(ui->openDetailedInfoButton, SIGNAL(clicked()), this, SLOT(openDetailedInfo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openInfoMain()
{
    ui->stackedWidget->setCurrentIndex(1);
    setupItemsScrollArea(listeEpreuves);
    setupItemsScrollArea(listeRestaurants);
}

void MainWindow::openMapMain()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::openDetailedInfo()
{
    // Récupération des informations à partir de la base de données JSON
    DataManager dataManager("lieux.json");
    QVector<Epreuve> epreuves = dataManager.toListEpreuves();
    // Supposons que vous souhaitiez afficher les détails de la première épreuve
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
    QLabel *nomLabel = new QLabel(epreuve.getNom()); //
    QLabel *horaireLabel = new QLabel(epreuve.getHoraireDebut().toString());
    QLabel *adresseLabel = new QLabel(epreuve.getAdresse());
    for (auto label : {nomLabel, horaireLabel, adresseLabel})
    {
        configureLabel(label);
        nameAdressTimeLayout->addWidget(label);
    }
}

// Ajout des infos (nom, adresse, horaire) au Layout (3)
void MainWindow::addRestaurantLabels(QVBoxLayout *nameAdressTimeLayout, const Restaurant &restaurant)
{
    QLabel *nomLabel = new QLabel(restaurant.getNom());
    QLabel *plageHoraireLabel = new QLabel(restaurant.getPlageHoraire());
    QLabel *adresseLabel = new QLabel(restaurant.getAdresse());
    for (auto label : {nomLabel, plageHoraireLabel, adresseLabel})
    {
        configureLabel(label);
        nameAdressTimeLayout->addWidget(label);
    }
}

// Configuration des labels du Layout (3)
void MainWindow::configureLabel(QLabel *label)
{
    label->setFixedWidth(300);
    label->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
}
