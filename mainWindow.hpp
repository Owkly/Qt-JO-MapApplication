#pragma once

#include "ui_mainWindow.h"
#include "detailedWindow.hpp"
#include "dataManager.hpp"
#include "epreuve.hpp"
#include "restaurant.hpp"

#include <QMainWindow>
#include <QScrollArea>
#include <QLabel>
#include <QVBoxLayout>
#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructeur et destructeur
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Méthodes de slots pour les interactions de l'interface utilisateur
    void openInfoMain();
    void openMapMain();
    void openDetailedInfo();
    void searchItem();

private:
    // Attributs
    Ui::MainWindow *ui;
    QVector<Epreuve> listeEpreuves;
    QVector<Restaurant> listeRestaurants;
    QVBoxLayout *scrollAreaLayout;

    // Méthodes
    // Méthode pour ajouter tout les items (épreuves/restau) à la scrollAreaLayout
    template <typename T>
    void setupItemsScrollArea(const QVector<T> &listeItems)
    {
        for (const T &item : listeItems)
        {
            addItemToScrollArea(item);
        }
    }

    template <typename T>
    void addItemToScrollArea(const T &item)
    {
        // scrollAreaLayout->setSpacing(0);
        // scrollAreaLayout->setContentsMargins(0, 0, 0, 0);

        QWidget *itemWidget = new QWidget();
        QVBoxLayout *itemLayout = new QVBoxLayout(itemWidget);
        // itemLayout->setSpacing(0);
        // itemLayout->setContentsMargins(0, 0, 0, 0);
        itemWidget->setStyleSheet("background-color: #7FFFD4;");

        QWidget *infoWidget = new QWidget();
        QHBoxLayout *infoLayout = new QHBoxLayout(infoWidget);
        infoWidget->setStyleSheet("background-color: #FFA07A;");
        // infoLayout->setSpacing(0);
        // infoLayout->setContentsMargins(0, 0, 0, 0);

        QWidget *nameAdressTimeWidget = new QWidget();
        QVBoxLayout *nameAdressTimeLayout = new QVBoxLayout(nameAdressTimeWidget);
        nameAdressTimeWidget->setStyleSheet("background-color: #FFFF00;");
        // nameAdressTimeLayout->setSpacing(0);
        // nameAdressTimeLayout->setContentsMargins(0, 0, 0, 0);
        addInfoLabels(nameAdressTimeLayout, item);

        QLabel *imageLabel = new QLabel();
        imageLabel->setPixmap(QPixmap(":/images/basket.jpg").scaled(150, 150));
        infoLayout->addWidget(imageLabel);
        nameAdressTimeLayout->addStretch(1);
        infoLayout->addWidget(nameAdressTimeWidget);

        itemLayout->addWidget(infoWidget);
        scrollAreaLayout->addWidget(itemWidget);
    }

    // Méthode pour ajouter les labels spécifiques à l'épreuve ou au restaurant
    template <typename T>
    void addInfoLabels(QVBoxLayout *nameAdressTimeLayout, const T &item)
    {
        if constexpr (std::is_same<T, Epreuve>::value)
        {
            addEpreuveLabels(nameAdressTimeLayout, item); // nom, adresse, horaireDebut
        }
        else if constexpr (std::is_same<T, Restaurant>::value)
        {
            addRestaurantLabels(nameAdressTimeLayout, item); // nom, adresse, plageHoraire
        }
    }

    void addEpreuveLabels(QVBoxLayout *nameAdressTimeLayout, const Epreuve &epreuve);
    void addRestaurantLabels(QVBoxLayout *nameAdressTimeLayout, const Restaurant &restaurant);
    void configureLabel(QLabel *label);
    void addVerticalSpacerToEnd();
    void clearScrollArea();
};
