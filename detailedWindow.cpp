// detailedWindow.cpp
#include "detailedWindow.hpp"
#include "ui_detailedWindow.h"
#include <QPushButton>

// Constructeur
DetailedWindow::DetailedWindow(QWidget *parent) : QDialog(parent), ui(new Ui::DetailedWindow)
{
    ui->setupUi(this);

    // Trouver le bouton "Ok" dans le QDialogButtonBox s'il est cliqué, fermer la fenêtre
    QPushButton *okButton = ui->DialogOkButton->button(QDialogButtonBox::Ok);
    connect(okButton, &QPushButton::clicked, this, &DetailedWindow::closeDetailedWindow);
}

// Destructeur
DetailedWindow::~DetailedWindow()
{
    delete ui;
}

// Méthode pour afficher les détails d'un lieu dans une fenêtre de dialogue
void DetailedWindow::setDetails(const QString &details)
{
    ui->textBrowser->setHtml(details);
}

// Méthode pour fermer la fenêtre de dialogue
void DetailedWindow::closeDetailedWindow()
{
    this->close();
}
