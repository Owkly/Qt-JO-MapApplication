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
        void searchItem();
        void showDetails(const QString &details);

    public:
        // Attributs
        Ui::MainWindow *ui;
        DataManager dataManager;
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
            // Création d'un itemWidget et de son layout (1) qui contiendra la mise en page des items ce widget sera cliquable
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

            // Configure la fenêtre détaillée associée à l'item
            QString details = constructDetailsString(item, dataManager.getListEvents(), dataManager.getListRestaurants());
            itemWidget->setDetails(details);
            connect(itemWidget, &ClickableWidget::clicked, this, &MainWindow::showDetails);

            // Ajout du layout (1) au scrollAreaLayout
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

    //Obtention du nom de la location (event ou restaurant) à partir de son Id
    template <typename T>
    QStringList getNearbyItemNames(const QVector<T>& items, const QVector<int>& nearbyIds)
    {
        QStringList itemNames;
        for (int itemId : nearbyIds) {
            for (const T& item : items) {
                if (item.getId() == itemId) {
                    itemNames.append(item.getName());
                    break;
                }
            }
        }
        return itemNames;
    }


    //Création de la fenetre détaillée
    template <typename T>
    QString constructDetailsString(const T &item, const QVector<Event>& allEvents, const QVector<Restaurant>& allRestaurants)
    {
        QString details;
        QString imagePath = item.getLocationImage();

        details = "<html><head><style>"
                "div.container { display: flex; align-items: flex-start; } "
                "div.image { width: 300px; } "
                "div.info { width: 300px; margin-left: 10px; } "
                "</style></head><body>";

        details += "<div class='container'>";

        // Ajouter l'image uniquement si le chemin n'est pas vide
        if (!imagePath.isEmpty())
        {
            details += "<div class='image'><img src=\"" + imagePath + "\" width=\"300\" height=\"300\" style=\"display: block;\" /></div>";
        }

        // Div d'information
        details += "<div class='info'>";

        if constexpr (std::is_same_v<T, Event>)
        {
            QStringList transportList = QStringList::fromVector(item.getTransportation());
            QString transports = transportList.join(", ");

            // Obtenez les noms des restaurants à proximité des épreuves
            QStringList nearbyRestaurantNames = getNearbyItemNames(allRestaurants, item.getNearbyRestaurants());
            QString nearbyRestaurantsString = nearbyRestaurantNames.join(", ");

            details += "<p><b>Nom:</b> " + item.getName() + "<br>"
                    "<b>Adresse:</b> " + item.getAddress() + "<br>"
                    "<b>Horaire:</b> " + item.getStartTime().toString("hh:mm dd-MM-yyyy") + "<br>"
                    "<b>Prix Billet:</b> " + QString::number(item.getTicketPrice()) + " €<br>"
                    "<b>Description:</b> " + item.getDescription() + "<br>"
                    "<b>Transports:</b> " + transports + "<br>"
                    "<b>Restaurants à proximité:</b> " + nearbyRestaurantsString + "</p>";
        }
        else if constexpr (std::is_same_v<T, Restaurant>)
        {
            QStringList nearbyEventNames = getNearbyItemNames(allEvents, item.getNearbyEvents());
            QString nearbyEventsString = nearbyEventNames.join(", ");

            details += "<p><b>Nom:</b> " + item.getName() + "<br>"
                    "<b>Adresse:</b> " + item.getAddress() + "<br>"
                    "<b>Plage Horaire:</b> " + item.getOpeningHours() + "<br>"
                    "<b>Spécialité:</b> " + item.getSpecialty() + "<br>"
                    "<b>Description:</b> " + item.getDescription() + "<br>"
                    "<b>Proximité Épreuve:</b> " + nearbyEventsString + "</p>";
        }

        // Fermeture du div d'information
        details += "</div>";

        // Fermeture du div conteneur
        details += "</div>";

        // Fermeture des balises HTML
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
