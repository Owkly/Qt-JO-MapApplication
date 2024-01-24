// mainWindow.cpp
#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include "detailedWindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::openMapMain()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//void MainWindow::openDetailedInfo()
//{
//    DetailedWindow detailedWindow(this);
//    detailedWindow.setModal(true);
//    detailedWindow.exec();
//}

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
