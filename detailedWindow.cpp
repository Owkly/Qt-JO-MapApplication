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
