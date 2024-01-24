//mainWindow.cpp

#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include "detailedWindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_openInfoMain_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_openMapMain_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_openDetailedInfo_clicked()
{
    DetailedWindow detailedWindow(this); // Créer une instance de DetailedWindow en passant 'this' pour définir le parent de la fenêtre.
    detailedWindow.setModal(true); // Optionnel : Rendez la fenêtre modale si vous le souhaitez.
    detailedWindow.exec(); // Affichez la fenêtre de dialogue et attendez que l'utilisateur la ferme.
}

