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
    void openInfoMain();     // Ouvre l'onglet principal d'informations
    void openMapMain();      // Ouvre l'onglet de la carte
    void openDetailedInfo(); // Ouvre une fenêtre détaillée pour plus d'informations

private:
    // Attributs
    Ui::MainWindow *ui;
    QVector<Epreuve> listeEpreuves;
    QVector<Restaurant> listeRestaurants;
    QVBoxLayout *scrollAreaLayout;

    // Ajout tout les items (épreuves/restau) à la scrollAreaLayout
    template <typename T>
    void setupItemsScrollArea(const QVector<T> &listeItems)
    {
        for (const T &item : listeItems)
        {
            addItemToScrollArea(item);
        }
    }
    // Méthode pour ajouter un item (épreuve/restau) à la scrollAreaLayout
    template <typename T>
    void addItemToScrollArea(const T &item)
    {
        QWidget *itemWidget = new QWidget();

        QVBoxLayout *itemLayout = new QVBoxLayout();           // Layout (1) vertical pour chaque item
        QHBoxLayout *infolayout = new QHBoxLayout();           // Layout (2) horizontal pour les infos (image, nom, adresse, horaire) de chaque item
        QVBoxLayout *nameAdressTimeLayout = new QVBoxLayout(); // Layout (3) vertical pour infos (nom, adresse, horaire) de chaque item

        // Ajout des infos (nom, adresse, horaire) au Layout (3)
        addInfoLabels(nameAdressTimeLayout, item);

        // Ajout du Layout (3) au Layout (2)
        infolayout->addLayout(nameAdressTimeLayout);

        // Ajout de l'image de au Layout (2)
        QLabel *imageLabel = new QLabel;
        imageLabel->setPixmap(QPixmap(":/images/basket.jpg").scaled(50, 50)); // Ou item.getImage()
        infolayout->addWidget(imageLabel);

        // Ajout du Layout (2) au Layout (1)
        itemLayout->addLayout(infolayout);

        // Ajout du Layout (1) au widget de l'item
        itemWidget->setLayout(itemLayout);

        // Ajout du widget de l'item au Layout de la scrollArea
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
};
