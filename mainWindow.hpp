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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openInfoMain();
    void openMapMain();
    void openDetailedInfo();

private:
    Ui::MainWindow *ui;
    QVector<Epreuve> listeEpreuves;
    QVector<Restaurant> listeRestaurants;
    QVBoxLayout *scrollAreaLayout;

    // Méthodes pour configurer la scrollAreaLayout
    template <typename T>
    void setupItemsScrollArea(const QVector<T> &listeItems)
    {
        for (const T &item : listeItems)
        {
            addItemToScrollArea(item);
        }
    }
    // Méthode pour ajouter un item à la scrollAreaLayout
    template <typename T>
    void addItemToScrollArea(const T &item)
    {
        QWidget *itemWidget = new QWidget();
        QVBoxLayout *itemLayout = new QVBoxLayout();
        QHBoxLayout *scrollLayout = new QHBoxLayout();

        QLabel *imageLabel = new QLabel;
        imageLabel->setPixmap(QPixmap(":/images/basket.jpg").scaled(50, 50)); // Ou item.getImage()
        scrollLayout->addWidget(imageLabel);

        QVBoxLayout *infoLayout = new QVBoxLayout(); // Déclaration de infoLayout
        addInfoLabels(infoLayout, item);

        scrollLayout->addLayout(infoLayout);
        itemLayout->addLayout(scrollLayout);
        itemWidget->setLayout(itemLayout);
        scrollAreaLayout->addWidget(itemWidget);
    }

    // Méthode pour ajouter les labels spécifiques à l'épreuve ou au restaurant
    template <typename T>
    void addInfoLabels(QVBoxLayout *infoLayout, const T &item)
    {
        if constexpr (std::is_same<T, Epreuve>::value)
        {
            addEpreuveLabels(infoLayout, item); // nom, adresse, horaireDebut
        }
        else if constexpr (std::is_same<T, Restaurant>::value)
        {
            addRestaurantLabels(infoLayout, item); // nom, adresse, plageHoraire
        }
    }
    void addEpreuveLabels(QVBoxLayout *infoLayout, const Epreuve &epreuve);
    void addRestaurantLabels(QVBoxLayout *infoLayout, const Restaurant &restaurant);

    void configureLabel(QLabel *label);
};
