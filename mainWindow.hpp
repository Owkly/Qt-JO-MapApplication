// mainWindow.hpp
#pragma once

#include "ui_mainWindow.h"

#include <QMainWindow>
#include <QScrollArea>
#include <QLabel>
#include <QVBoxLayout>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructeur et destructeur
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Méthodes qui réagissant à certains événements (ici, les clics sur les boutons)
    void openInfoPage();
    void openMapPage();
    void openDetailedPage();

private:
    Ui::MainWindow *ui;
};

