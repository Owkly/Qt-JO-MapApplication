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
    void openHomeMain();
    void openInfoMain();
    void openMapMain();
    void closeMain();
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
        // Création d'un itemWidget et de son layout (1) qui contiendra la mise en page des items
        ClickableWidget *itemWidget = new ClickableWidget();
        QVBoxLayout *itemLayout = new QVBoxLayout(itemWidget);
        itemWidget->setStyleSheet("background-color: #DCB253; " // jaune/orange
                                  "border: 3px solid #000000; "
                                  "border-radius: 6px; "
                                  "padding: 5px; "
                                  "margin: 5px;");

        // Layout (2) qui contiendra la mise en page des informations de l'item
        QWidget *infoWidget = new QWidget();
        QHBoxLayout *infoLayout = new QHBoxLayout(infoWidget);

        // layout (3) qui contiendra la mise en page des informations (nom, adresse, horaire) de l'item
        QWidget *nameAdressTimeWidget = new QWidget();
        QVBoxLayout *nameAdressTimeLayout = new QVBoxLayout(nameAdressTimeWidget);

        // Ajout des labels nom, adresse, horaire au layout (3)
        nameAdressTimeWidget->setStyleSheet("background-color: #4aa77c;"); // vert
        addInfoLabels(nameAdressTimeLayout, item);

        // Ajout de l'image et du layout (3) au layout (2)
        QLabel *imageLabel = new QLabel();
        imageLabel->setPixmap(QPixmap(getImagePathForItem(item)).scaled(150, 150));

        infoLayout->addWidget(imageLabel);
        nameAdressTimeLayout->addStretch(1);
        infoLayout->addWidget(nameAdressTimeWidget);

        // Ajout du layout (2) au layout (1)
        itemLayout->addWidget(infoWidget);

        // Ajout du layout (1) au scrollAreaLayout en le rendant cliquable
        QString details = constructDetailsString(item);
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

//template <typename T>
//QString constructDetailsString(const T &item)
//{
//    QString details;
//    if constexpr (std::is_same<T, Event>::value)
//    {
//        details = "Nom: " + item.getName() + "\nAdresse: " + item.getAddress() +
//                  "\nHoraire: " + item.getStartTime().toString() +
//                  "\nPrix Billet: " + QString::number(item.getTicketPrice()) + "\n...";
//    }
//    else if constexpr (std::is_same<T, Restaurant>::value)
//    {
//        details = "Nom: " + item.getName() + "\nAdresse: " + item.getAddress() +
//                  "\nPlage Horaire: " + item.getOpeningHours() + "\nSpécialité: " + item.getSpecialty() + "\n...";
//    }
//    return details;
//}

template <typename T>
QString constructDetailsString(const T &item)
{
    QString details;
    QString imagePath = item.getLocationImage(); // Make sure this returns the correct image path

    // Start with an HTML string for the details
    details = "<html><head><style>"
              "div.container { display: flex; align-items: flex-start; } "
              "div.image { width: 300; } "
              "div.info { width: 300; } "
              "</style></head><body>";

    details += "<div class='container'>";

    // Add the image using an HTML img tag if the path is not empty
    if (!imagePath.isEmpty())
    {
        // Ensure the image path is correct and accessible by the application
        details += "<div class='image'><img src=\"" + imagePath + "\" width=\"500\" height=\"300\" style=\"display: block;\" /></div>";
    }

    // Information div
    details += "<div class='info'>";

    if constexpr (std::is_same<T, Event>::value)
    {
        details += "<p><b>Nom:</b> " + item.getName() + "<br>"
                   "<b>Adresse:</b> " + item.getAddress() + "<br>"
                   "<b>Horaire:</b> " + item.getStartTime().toString("hh:mm dd-MM-yyyy") + "<br>"
                   "<b>Prix Billet:</b> " + QString::number(item.getTicketPrice()) + " €</p>";
    }
    else if constexpr (std::is_same<T, Restaurant>::value)
    {
        details += "<p><b>Nom:</b> " + item.getName() + "<br>"
                   "<b>Adresse:</b> " + item.getAddress() + "<br>"
                   "<b>Plage Horaire:</b> " + item.getOpeningHours() + "<br>"
                   "<b>Spécialité:</b> " + item.getSpecialty() + "</p>";
    }

    // Close the info div
    details += "</div>"; // Close div.info

    // Close the container div
    details += "</div>"; // Close div.container

    // Close the HTML tags
    details += "</body></html>";

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
