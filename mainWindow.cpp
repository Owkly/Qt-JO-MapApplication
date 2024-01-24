//mainWindow.cpp

#include "mainWindow.hpp"
#include "ui_mainWindow.h"

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

