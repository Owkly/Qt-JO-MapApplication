#pragma once

#include "ui_mainWindow.h"
#include "detailedWindow.hpp"
#include "dataManager.hpp"
#include "event.hpp"
#include "restaurant.hpp"
#include "clickableWidget.hpp"

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
    void showDetails(const QString &details);

private:
    // Attributs
    Ui::MainWindow *ui;
    QVector<Event> listEvents;
    QVector<Restaurant> listRestaurants;
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
        // Utilisation de ClickableWidget pour la gestion des clics
        ClickableWidget *itemWidget = new ClickableWidget();
        QVBoxLayout *itemLayout = new QVBoxLayout(itemWidget);
        itemWidget->setStyleSheet("background-color: #7FFFD4;");

        // Création et configuration de l'infoWidget
        QWidget *infoWidget = new QWidget();
        QHBoxLayout *infoLayout = new QHBoxLayout(infoWidget);
        infoWidget->setStyleSheet("background-color: #FFA07A;");

        // Création et configuration de nameAdressTimeWidget
        QWidget *nameAdressTimeWidget = new QWidget();
        QVBoxLayout *nameAdressTimeLayout = new QVBoxLayout(nameAdressTimeWidget);
        nameAdressTimeWidget->setStyleSheet("background-color: #FFFF00;");
        addInfoLabels(nameAdressTimeLayout, item);

        // Configuration de l'image
        QLabel *imageLabel = new QLabel();
        imageLabel->setPixmap(QPixmap(getImagePathForItem(item)).scaled(150, 150));
        infoLayout->addWidget(imageLabel);
        nameAdressTimeLayout->addStretch(1);
        infoLayout->addWidget(nameAdressTimeWidget);

        itemLayout->addWidget(infoWidget);

        // Ajout des détails et connexion du signal clicked
        QString details = constructDetailsString(item); // Fonction à définir pour construire la chaîne de détails
        itemWidget->setDetails(details);
        connect(itemWidget, &ClickableWidget::clicked, this, &MainWindow::showDetails);

        scrollAreaLayout->addWidget(itemWidget);
    }

    // Méthode pour ajouter les labels spécifiques à l'épreuve ou au restaurant
    template <typename T>
    void addInfoLabels(QVBoxLayout *nameAdressTimeLayout, const T &item)
    {
        if constexpr (std::is_same<T, Event>::value)
        {
            addEventLabels(nameAdressTimeLayout, item); // nom, adresse, horaireDebut
        }
        else if constexpr (std::is_same<T, Restaurant>::value)
        {
            addRestaurantLabels(nameAdressTimeLayout, item); // nom, adresse, plageHoraire
        }
    }

    void addEventLabels(QVBoxLayout *nameAdressTimeLayout, const Event &event);
    void addRestaurantLabels(QVBoxLayout *nameAdressTimeLayout, const Restaurant &restaurant);
    void configureLabel(QLabel *label);
    void addVerticalSpacerToEnd();
    void clearScrollArea();
};

template <typename T>
QString constructDetailsString(const T &item)
{
    QString details;
    if constexpr (std::is_same<T, Event>::value)
    {
        details = "Nom: " + item.getName() + "\nAdresse: " + item.getAddress() +
                  "\nHoraire: " + item.getStartTime().toString() +
                  "\nPrix Billet: " + QString::number(item.getTicketPrice()) + "\n...";
    }
    else if constexpr (std::is_same<T, Restaurant>::value)
    {
        details = "Nom: " + item.getName() + "\nAdresse: " + item.getAddress() +
                  "\nPlage Horaire: " + item.getOpeningHours() + "\nSpécialité: " + item.getSpecialty() + "\n...";
    }
    return details;
}

template <typename T>
QString getImagePathForItem(const T &item)
{
    if constexpr (std::is_same_v<T, Restaurant>)
    {
        // Supposons que getLocationImage() pour un restaurant retourne un chemin d'image sous forme de QString
        return item.getLocationImage();
    }
    else if constexpr (std::is_same_v<T, Event>)
    {
        // Supposons que getEventImage() pour un événement retourne également un chemin d'image sous forme de QString
        return item.getEventImage();
    }
    else
    {
        // Retourner une valeur par défaut ou gérer une erreur si T n'est ni un Restaurant ni un Event
        return QString();
    }
}
