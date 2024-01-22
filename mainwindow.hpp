#pragma once
#include <QMainWindow>
#include <epreuve.hpp>

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

private:
    Ui::MainWindow *ui;
    Epreuve currentEpreuve; // Attribut pour stocker l'épreuve
};

