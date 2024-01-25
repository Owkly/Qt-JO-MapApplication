#pragma once

#include "ui_mainWindow.h"
#include "detailedWindow.hpp"
#include "dataManager.hpp"
#include "epreuve.hpp"
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

//    template <typename T>
//    void addItemToScrollArea(const T &item)
//    {
//        // scrollAreaLayout->setSpacing(0);
//        // scrollAreaLayout->setContentsMargins(0, 0, 0, 0);

//        QWidget *itemWidget = new QWidget();
//        QVBoxLayout *itemLayout = new QVBoxLayout(itemWidget);
//        // itemLayout->setSpacing(0);
//        // itemLayout->setContentsMargins(0, 0, 0, 0);
//        itemWidget->setStyleSheet("background-color: #7FFFD4;");

//        QWidget *infoWidget = new QWidget();
//        QHBoxLayout *infoLayout = new QHBoxLayout(infoWidget);
//        infoWidget->setStyleSheet("background-color: #FFA07A;");
//        // infoLayout->setSpacing(0);
//        // infoLayout->setContentsMargins(0, 0, 0, 0);

//        QWidget *nameAdressTimeWidget = new QWidget();
//        QVBoxLayout *nameAdressTimeLayout = new QVBoxLayout(nameAdressTimeWidget);
//        nameAdressTimeWidget->setStyleSheet("background-color: #FFFF00;");
//        // nameAdressTimeLayout->setSpacing(0);
//        // nameAdressTimeLayout->setContentsMargins(0, 0, 0, 0);
//        addInfoLabels(nameAdressTimeLayout, item);

//        QLabel *imageLabel = new QLabel();
//        imageLabel->setPixmap(QPixmap(":/images/basket.jpg").scaled(150, 150));
//        infoLayout->addWidget(imageLabel);
//        nameAdressTimeLayout->addStretch(1);
//        infoLayout->addWidget(nameAdressTimeWidget);

//        itemLayout->addWidget(infoWidget);
//        scrollAreaLayout->addWidget(itemWidget);
//    }

//--------------------------------------------------------------------------------------------------
//    template <typename T>
//    void addItemToScrollArea(const T &item)
//    {
//        // Créez un widget ClickableWidget
//        ClickableWidget *itemWidget = new ClickableWidget();
//        QString briefInfo = item.getNom() + " - " + item.getAdresse();
//        QString details = constructDetailsString(item);

//        QLabel *infoLabel = new QLabel(briefInfo);
//        configureLabel(infoLabel);

//        QVBoxLayout *itemLayout = new QVBoxLayout();
//        itemLayout->addWidget(infoLabel);
//        itemWidget->setLayout(itemLayout);

//        itemWidget->setDetails(details);

//        // Connectez le clic sur l'élément à l'ouverture de la fenêtre de dialogue détaillée
//        connect(itemWidget, &ClickableWidget::clicked, [this, details]() {
//            // Créez et affichez la fenêtre de dialogue détaillée
//            DetailedWindow dialog(details);
//            dialog.exec();
//        });

//        scrollAreaLayout->addWidget(itemWidget);
//    }
//----------------------------------------------------------------------------------------

//    template <typename T>
//    void addItemToScrollArea(const T &item)
//    {
//        ClickableWidget *itemWidget = new ClickableWidget();
//        QString briefInfo = item.getNom() + " - " + item.getAdresse();
//        QString details = constructDetailsString(item);

//        QLabel *infoLabel = new QLabel(briefInfo);
//        configureLabel(infoLabel);

//        QVBoxLayout *itemLayout = new QVBoxLayout();
//        itemLayout->addWidget(infoLabel);
//        itemWidget->setLayout(itemLayout);

//        itemWidget->setDetails(details);
//        connect(itemWidget, &ClickableWidget::clicked, this, &MainWindow::showDetails);

//        scrollAreaLayout->addWidget(itemWidget);
//    }

//-----------------------------Truc redondant----------------------------------------------
//    template <typename T>
//    void addItemToScrollArea(const T &item)
//    {
//        // Utilisation de ClickableWidget pour la gestion des clics
//        ClickableWidget *itemWidget = new ClickableWidget();
//        QVBoxLayout *itemLayout = new QVBoxLayout(itemWidget);
//        itemWidget->setStyleSheet("background-color: #7FFFD4;");

//        // Création et configuration de l'infoWidget
//        QWidget *infoWidget = new QWidget();
//        QHBoxLayout *infoLayout = new QHBoxLayout(infoWidget);
//        infoWidget->setStyleSheet("background-color: #FFA07A;");

//        // Création et configuration de nameAdressTimeWidget
//        QWidget *nameAdressTimeWidget = new QWidget();
//        QVBoxLayout *nameAdressTimeLayout = new QVBoxLayout(nameAdressTimeWidget);
//        nameAdressTimeWidget->setStyleSheet("background-color: #FFFF00;");
//        addInfoLabels(nameAdressTimeLayout, item);

//        // Configuration de l'image
//        QLabel *imageLabel = new QLabel();
//        imageLabel->setPixmap(QPixmap(":/images/basket.jpg").scaled(150, 150));
//        infoLayout->addWidget(imageLabel);
//        nameAdressTimeLayout->addStretch(1);
//        infoLayout->addWidget(nameAdressTimeWidget);

//        itemLayout->addWidget(infoWidget);

//        // Ajout des détails et connexion du signal clicked
//        QString briefInfo = item.getNom() + " - " + item.getAdresse();
//        QLabel *infoLabel = new QLabel(briefInfo);
//        configureLabel(infoLabel);  // Fonction à définir pour configurer le label
//        itemLayout->addWidget(infoLabel);

//        QString details = constructDetailsString(item);  // Fonction à définir pour construire la chaîne de détails
//        itemWidget->setDetails(details);
//        connect(itemWidget, &ClickableWidget::clicked, this, &MainWindow::showDetails);

//        scrollAreaLayout->addWidget(itemWidget);
//    }
//---------------------------------------------------------------------------------------------------
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
        imageLabel->setPixmap(QPixmap(":/images/basket.jpg").scaled(150, 150));
        infoLayout->addWidget(imageLabel);
        nameAdressTimeLayout->addStretch(1);
        infoLayout->addWidget(nameAdressTimeWidget);

        itemLayout->addWidget(infoWidget);

        // Suppression de l'ajout redondant des informations
        // Suppression de la création et de l'ajout de infoLabel redondant
        // QLabel *infoLabel = new QLabel(briefInfo);
        // configureLabel(infoLabel);  // Fonction à définir pour configurer le label
        // itemLayout->addWidget(infoLabel);

        // Ajout des détails et connexion du signal clicked
        QString details = constructDetailsString(item);  // Fonction à définir pour construire la chaîne de détails
        itemWidget->setDetails(details);
        connect(itemWidget, &ClickableWidget::clicked, this, &MainWindow::showDetails);

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

template <typename T>
QString constructDetailsString(const T &item)
{
    QString details;
    if constexpr (std::is_same<T, Epreuve>::value)
    {
        details = "Nom: " + item.getNom() + "\nAdresse: " + item.getAdresse() +
                  "\nHoraire: " + item.getHoraireDebut().toString() +
                  "\nPrix Billet: " + QString::number(item.getPrixBillet()) + "\n...";
    }
    else if constexpr (std::is_same<T, Restaurant>::value)
    {
        details = "Nom: " + item.getNom() + "\nAdresse: " + item.getAdresse() +
                  "\nPlage Horaire: " + item.getPlageHoraire() + "\nSpécialité: " + item.getSpecialite() + "\n...";
    }
    return details;
}
