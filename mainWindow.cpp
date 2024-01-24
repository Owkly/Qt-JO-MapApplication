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
    setupEpreuveScrollArea(listeEpreuves);
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
    if (!epreuves.isEmpty()) {
        Epreuve premiereEpreuve = epreuves.first();
        QString details = "Nom : " + premiereEpreuve.getNom() + "\n"
                         "Adresse : " + premiereEpreuve.getAdresse() + "\n"
                         "Prix Billet : " + premiereEpreuve.getPrixBillet() + "€\n"
                         "Description : " + premiereEpreuve.getDescription();
        DetailedWindow detailedWindow(this);
        detailedWindow.setModal(true);
        detailedWindow.setDetails(details); // Passez les détails à la fenêtre de dialogue
        detailedWindow.exec();
    }
}


void MainWindow::addEpreuveScrollArea(const Epreuve &epreuve)
{
    // Créer un widget pour chaque épreuve 
    QWidget *epreuveWidget = new QWidget();
    QVBoxLayout *epreuveLayout = new QVBoxLayout(); // épreuve
    QHBoxLayout *scrollLayout = new QHBoxLayout();  // image + nom + horaire

    // Image à gauche de epreuveLayout
    QLabel *imageLabel = new QLabel;
    imageLabel->setPixmap(QPixmap(":/images/basket.jpg").scaled(50, 50));
    scrollLayout->addWidget(imageLabel);

    // Informations à droite de epreuveLayout
    QVBoxLayout *infoLayout = new QVBoxLayout();
    QLabel *nomLabel = new QLabel(epreuve.getNom());
    QLabel *horaireLabel = new QLabel(epreuve.getHoraireDebut().toString());
    QLabel *prixBillet = new QLabel(QString::number(epreuve.getPrixBillet()) + " €");
    
        // Ajustements de la taille et de l'alignement des labels
    for (auto infoLabel : {nomLabel, horaireLabel, prixBillet})
    {
        infoLabel->setFixedWidth(300);
        infoLabel->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
        infoLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        infoLayout->addWidget(infoLabel);
    }

    // Ajoutez le QVBoxLayout (nom et horaire) à droite du QHBoxLayout
    scrollLayout->addLayout(infoLayout);

    // Ajoutez le QHBoxLayout au QVBoxLayout principal de l'épreuve
    epreuveLayout->addLayout(scrollLayout);

    // Configurez le widget de l'épreuve et ajoutez-le au layout principal de la scroll area
    epreuveWidget->setLayout(epreuveLayout);
    scrollAreaLayout->addWidget(epreuveWidget);
}



void MainWindow::setupEpreuveScrollArea(QVector<Epreuve> listeEpreuves)
{
    for (const Epreuve &epreuve : listeEpreuves)
    {
        addEpreuveScrollArea(epreuve);
    }
}
