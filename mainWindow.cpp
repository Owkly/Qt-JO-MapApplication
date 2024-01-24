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
    connect(ui->openInfoMain, SIGNAL(clicked()), this, SLOT(openInfoPage()));
    connect(ui->openMapMain, SIGNAL(clicked()), this, SLOT(openMapPage()));
    connect(ui->openDetailedInfo, SIGNAL(clicked()), this, SLOT(openDetailedPage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openInfoPage()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::openMapPage()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::openDetailedPage()
{
    DetailedWindow detailedWindow(this);
    detailedWindow.setModal(true);
    detailedWindow.exec();
}
