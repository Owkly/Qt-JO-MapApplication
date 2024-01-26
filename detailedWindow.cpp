// detailedWindow.cpp
#include "detailedWindow.hpp"
#include "ui_detailedWindow.h"

DetailedWindow::DetailedWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailedWindow)
{
    ui->setupUi(this);
}

DetailedWindow::~DetailedWindow()
{
    delete ui;
}

void DetailedWindow::setDetails(const QString &details)
{
//    ui->textBrowser ->setText(details);
    ui->textBrowser ->setHtml(details);
}
