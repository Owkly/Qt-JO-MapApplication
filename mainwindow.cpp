#include "mainwindow.hpp"
#include "ui_mainwindow.h"

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


void MainWindow::setEpreuve(const Epreuve &epreuve) {
    ui->Nom->setText(epreuve.getNom());
    ui->Adresse->setText(epreuve.getAdresse());
    ui->Horaire->setText(epreuve.getHoraire().toString("yyyy-MM-dd HH:mm:ss"));

    if (!epreuve.getImage().isNull()) {
        ui->Image->setPixmap(epreuve.getImage().scaled(ui->Image->size()));
    }
    ui->Image->setScaledContents(true);
}
