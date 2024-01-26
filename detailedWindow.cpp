// detailedWindow.cpp
#include "detailedWindow.hpp"
#include "ui_detailedWindow.h"
#include <QPushButton>

DetailedWindow::DetailedWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::DetailedWindow)
{
    ui->setupUi(this);

    // Trouver le bouton "Ok" dans le QDialogButtonBox s'il est cliqué, fermer la fenêtre
    QPushButton *okButton = ui->DialogOkButton->button(QDialogButtonBox::Ok);
    connect(okButton, &QPushButton::clicked, this, &DetailedWindow::closeDetailedWindow);
}

DetailedWindow::~DetailedWindow()
{
    delete ui;
}

void DetailedWindow::setDetails(const QString &details)
{
    ui->textBrowser->setHtml(details);
}

void DetailedWindow::closeDetailedWindow()
{
    this->close();
}
