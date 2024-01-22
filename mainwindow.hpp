#pragma once

#include "epreuve.hpp"
#include "ui_mainwindow.h"

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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setEpreuve(const Epreuve &epreuve); // Méthode pour définir l'épreuve à afficher
    void afficherEpreuves(const QList<Epreuve> &epreuves); // Méthode pour afficher une liste d'épreuves


public slots:
    void afficherDetailsEpreuve(const Epreuve &epreuve);

private:
    Ui::MainWindow *ui;
    Epreuve currentEpreuve; // Attribut pour stocker l'épreuve
};

