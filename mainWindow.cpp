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

void MainWindow::openDetailedInfo()
{
    DetailedWindow detailedWindow(this);
    detailedWindow.setModal(true);
    detailedWindow.exec();
}
