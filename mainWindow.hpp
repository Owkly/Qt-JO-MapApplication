#pragma once

#include "ui_mainWindow.h"
#include "detailedDialog.hpp"
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
    // Méthodes de slot pour interagir avec l'interface utilisateur
    void openHomeMain();
    void openInfoMain();
    void openMapMain();
    void closeMain();
    void searchItem();
    void openDetailedDialog(const QString &codeHTML);


private :
    // Attributs
    Ui::MainWindow *ui;
    DataManager dataManager;
    QVBoxLayout *scrollAreaLayout;

    // Méthodes Template pour afficher toutes les épreuves ou tous les restaurants au début
    template <typename T>
    void setupItemsScrollArea(const QVector<T> &listeItems)
    {
        // si c'est une épreuve
        if constexpr (std::is_same<T, Event>::value)
        {
            for (const T &item : listeItems)
            {
                addEventToScrollArea(item);
            }
        }
        // si c'est un restaurant
        else if constexpr (std::is_same<T, Restaurant>::value)
        {
            for (const T &item : listeItems)
            {
                addRestaurantToScrollArea(item);
            }
        }
        // sinon erreur
        else
        {
            throw std::runtime_error("Type non supporté");
        }

        addVerticalSpacerToEnd();
    }

    // Méthodes
    void addEventToScrollArea(const Event &event);
    void addRestaurantToScrollArea(const Restaurant &restaurant);
    void addEventLabels(QVBoxLayout *nameAdressTimeLayout, const Event &event);
    void addRestaurantLabels(QVBoxLayout *nameAdressTimeLayout, const Restaurant &restaurant);
    void configureLabel(QLabel *label);
    void addVerticalSpacerToEnd();
    void clearScrollArea();

    // QString generateCodeHtmlForEventDetails(const Event &event);
    // QString generateCodeHtmlForRestaurantDetails(const Restaurant &restaurant);

    // template <typename T>
    // void addItemToScrollArea(const T &item)
    // {
    //     // Création d'un itemWidget et de son layout (1) qui contiendra la mise en page des items ce widget sera cliquable
    //     ClickableWidget *itemWidget = new ClickableWidget();
    //     QVBoxLayout *itemLayout = new QVBoxLayout(itemWidget);
    //     itemWidget->setStyleSheet("background-color: #DCB253; " // jaune/orange
    //                               "border: 3px solid #000000; "
    //                               "border-radius: 6px; "
    //                               "padding: 5px; "
    //                               "margin: 5px;");

    //     // Layout (2) qui contiendra la mise en page des informations de l'item
    //     QWidget *infoWidget = new QWidget();
    //     QHBoxLayout *infoLayout = new QHBoxLayout(infoWidget);

    //     // layout (3) qui contiendra la mise en page des informations (nom, adresse, horaire) de l'item
    //     QWidget *nameAdressTimeWidget = new QWidget();
    //     QVBoxLayout *nameAdressTimeLayout = new QVBoxLayout(nameAdressTimeWidget);

    //     // Ajout des labels nom, adresse, horaire au layout (3)
    //     nameAdressTimeWidget->setStyleSheet("background-color: #4aa77c;"); // vert
    //     addInfoLabels(nameAdressTimeLayout, item);

    //     // Ajout de l'image et du layout (3) au layout (2)
    //     QLabel *imageLabel = new QLabel();
    //     QString imagePath = item.getPathForItem();
    //     imageLabel->setPixmap(QPixmap(imagePath).scaled(150, 150));

    //     infoLayout->addWidget(imageLabel);
    //     nameAdressTimeLayout->addStretch(1);
    //     infoLayout->addWidget(nameAdressTimeWidget);

    //     // Ajout du layout (2) au layout (1)
    //     itemLayout->addWidget(infoWidget);

    //     // Configure la fenêtre détaillée associée à l'item
    //     QString details = constructDetailsString(item);
    //     itemWidget->setDetails(details);
    //     connect(itemWidget, &ClickableWidget::clicked, this, &MainWindow::showDetails);

    //     // Ajout du layout (1) au scrollAreaLayout
    //     scrollAreaLayout->addWidget(itemWidget);
    // }

    // // Méthode pour ajouter les labels spécifiques à l'épreuve ou au restaurant
    // template <typename T>
    // void addInfoLabels(QVBoxLayout *nameAdressTimeLayout, const T &item)
    // {
    //     if constexpr (std::is_same<T, Event>::value)
    //     {
    //         addEventLabels(nameAdressTimeLayout, item); // nom, adresse, horaireDebut
    //     }
    //     else if constexpr (std::is_same<T, Restaurant>::value)
    //     {
    //         addRestaurantLabels(nameAdressTimeLayout, item); // nom, adresse, plageHoraire
    //     }
    // }

    //     // Création de la fenetre détaillée
    //     template <typename T>
    //     QString constructDetailsString(const T &item)
    //     {
    //         QString details;
    //         QString imagePath = item.getLocationImage();

    //         details = "<html><head><style>"
    //                   "div.container { display: flex; align-items: flex-start; } "
    //                   "div.image { width: 300px; } "
    //                   "div.info { width: 300px; margin-left: 10px; } "
    //                   "</style></head><body>";

    //         details += "<div class='container'>";

    //         // Ajouter l'image uniquement si le chemin n'est pas vide
    //         if (!imagePath.isEmpty())
    //         {
    //             details += "<div class='image'><img src=\"" + imagePath + "\" width=\"300\" height=\"300\" style=\"display: block;\" /></div>";
    //         }

    //         // Div d'information
    //         details += "<div class='info'>";

    //         if constexpr (std::is_same_v<T, Event>)
    //         {
    //             QStringList transportList = QStringList::fromVector(item.getTransportation());
    //             QString transports = transportList.join(", ");

    //             // Obtenez les noms des restaurants à proximité des épreuves
    //             QStringList nearbyRestaurantNames = dataManager.getNearbyRestaurantsNames(item.getNearbyRestaurants());
    //             QString nearbyRestaurantsString = nearbyRestaurantNames.join(", ");

    //             details += "<p><b>Nom:</b> " + item.getName() + "<br>"
    //                                                             "<b>Adresse:</b> " +
    //                        item.getAddress() + "<br>"
    //                                            "<b>Horaire:</b> " +
    //                        item.getStartTime().toString("hh:mm dd-MM-yyyy") + "<br>"
    //                                                                           "<b>Prix Billet:</b> " +
    //                        QString::number(item.getTicketPrice()) + " €<br>"
    //                                                                 "<b>Description:</b> " +
    //                        item.getDescription() + "<br>"
    //                                                "<b>Transports:</b> " +
    //                        transports + "<br>"
    //                                     "<b>Restaurants à proximité:</b> " +
    //                        nearbyRestaurantsString + "</p>";
    //         }
    //         else if constexpr (std::is_same_v<T, Restaurant>)
    //         {
    //             QStringList nearbyEventNames = dataManager.getNearbyEventsNames(item.getNearbyEvents());
    //             QString nearbyEventsString = nearbyEventNames.join(", ");

    //             details += "<p><b>Nom:</b> " + item.getName() + "<br>"
    //                                                             "<b>Adresse:</b> " +
    //                        item.getAddress() + "<br>"
    //                                            "<b>Plage Horaire:</b> " +
    //                        item.getOpeningHours() + "<br>"
    //                                                 "<b>Spécialité:</b> " +
    //                        item.getSpecialty() + "<br>"
    //                                              "<b>Description:</b> " +
    //                        item.getDescription() + "<br>"
    //                                                "<b>Proximité Épreuve:</b> " +
    //                        nearbyEventsString + "</p>";
    //         }

    //         // Fermeture du div d'information
    //         details += "</div>";

    //         // Fermeture du div conteneur
    //         details += "</div>";

    //         // Fermeture des balises HTML
    //         details += "</body></html>";

    //         return details;
    //     }
};
