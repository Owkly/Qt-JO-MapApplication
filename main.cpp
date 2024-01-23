#include "mainwindow.hpp"
#include "epreuve.hpp"
#include "restaurant.hpp"

#include <QApplication>
#include <QPixmap>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Créer le widget principal
    QWidget mainWidget;

    // Créer un layout vertical pour le widget principal
    QVBoxLayout *mainLayout = new QVBoxLayout(&mainWidget);

    // Créer un QScrollArea
    QScrollArea *scrollArea = new QScrollArea;

    // Créer un widget qui servira de conteneur pour les éléments de la liste
    QWidget *scrollWidget = new QWidget;
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);

        QFile file("lieux.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Impossible d'ouvrir le fichier pour la lecture.";
        return -1;
    }

    QString jsonText = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonText.toUtf8());
    QJsonObject rootObject = document.object();
    QJsonObject lieux = rootObject["lieux"].toObject();

    QVector<Epreuve> listeEpreuves;
    QVector<Restaurant> listeRestaurants;

    // Traiter les épreuves
    QJsonArray epreuves = lieux["Epreuves"].toArray();
    for (const auto &value : epreuves) {
        QJsonObject epreuveObj = value.toObject();

        QVector<int> proximiteRestaurants;
        for (const auto &idVariant : epreuveObj["proximiteRestaurant"].toArray()) {
            proximiteRestaurants.append(idVariant.toInt());
        }

        Epreuve epreuve(
            epreuveObj["id"].toInt(),
            epreuveObj["nom"].toString(),
            epreuveObj["adresse"].toString(),
            epreuveObj["description"].toString(),
            epreuveObj["image"].toString(),
            epreuveObj["transports"].toVariant().toStringList().toVector(),
            QDateTime::fromString(epreuveObj["horaireDebut"].toString(), Qt::ISODate),
            epreuveObj["prixBillet"].toDouble(),
            proximiteRestaurants
        );
        listeEpreuves.append(epreuve);
    }

    // Traiter les restaurants
    QJsonArray restaurants = lieux["Restaurants"].toArray();
    for (const auto &value : restaurants) {
        QJsonObject restaurantObj = value.toObject();

        QVector<int> proximiteEpreuves;
        for (const auto &idVariant : restaurantObj["proximiteEpreuves"].toArray()) {
            proximiteEpreuves.append(idVariant.toInt());
        }

        Restaurant restaurant(
            restaurantObj["id"].toInt(),
            restaurantObj["nom"].toString(),
            restaurantObj["adresse"].toString(),
            restaurantObj["description"].toString(),
            restaurantObj["image"].toString(),
            restaurantObj["transports"].toVariant().toStringList().toVector(),
            restaurantObj["plageHoraire"].toString(),
            restaurantObj["specialite"].toString(),
            proximiteEpreuves
        );
        listeRestaurants.append(restaurant);
    }


    // Ajouter les épreuves à la liste
    for (const Epreuve &epreuve : listeEpreuves)
    {
        // Créer un widget pour chaque épreuve
        QWidget *epreuveWidget = new QWidget;
        QHBoxLayout *epreuveLayout = new QHBoxLayout(epreuveWidget);

        // Ajouter une image à gauche
        QLabel *imageLabel = new QLabel;
        imageLabel->setPixmap(epreuve.getImage().scaled(50, 50)); // Ajustez la taille selon vos besoins
        epreuveLayout->addWidget(imageLabel);

        // Ajouter les informations à droite
        QVBoxLayout *infoLayout = new QVBoxLayout;
        QLabel *nomLabel = new QLabel(epreuve.getNom());
        QLabel *adresseLabel = new QLabel(epreuve.getAdresse());
        QLabel *descriptionLabel = new QLabel(epreuve.getDescription());
        infoLayout->addWidget(nomLabel);
        infoLayout->addWidget(adresseLabel);
        infoLayout->addWidget(descriptionLabel);
        epreuveLayout->addLayout(infoLayout);

        // Ajouter le widget de l'épreuve au layout du widget de la liste
        scrollLayout->addWidget(epreuveWidget);
    }

   // Configurer le QScrollArea
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);

    // Ajouter le QScrollArea à la moitié droite du layout principal
    mainLayout->addWidget(new QWidget); // Espace vide à gauche
    mainLayout->addWidget(scrollArea, 1); // QScrollArea prend la moitié droite

    // Configurer le widget principal
    mainWidget.setLayout(mainLayout);
    mainWidget.setWindowTitle("Liste d'Epreuves");
    mainWidget.resize(800, 600); // Ajustez la taille selon vos besoins
    mainWidget.show();
    
    return a.exec();

}



// int main() {
//     QFile file("lieux.json");
//     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         qDebug() << "Impossible d'ouvrir le fichier pour la lecture.";
//         return -1;
//     }

//     QString jsonText = file.readAll();
//     file.close();

//     QJsonDocument document = QJsonDocument::fromJson(jsonText.toUtf8());
//     QJsonObject rootObject = document.object();
//     QJsonObject lieux = rootObject["lieux"].toObject();

//     QVector<Epreuve> listeEpreuves;
//     QVector<Restaurant> listeRestaurants;

//     // Traiter les épreuves
//     QJsonArray epreuves = lieux["Epreuves"].toArray();
//     for (const auto &value : epreuves) {
//         QJsonObject epreuveObj = value.toObject();

//         QVector<int> proximiteRestaurants;
//         for (const auto &idVariant : epreuveObj["proximiteRestaurant"].toArray()) {
//             proximiteRestaurants.append(idVariant.toInt());
//         }

//         Epreuve epreuve(
//             epreuveObj["id"].toInt(),
//             epreuveObj["nom"].toString(),
//             epreuveObj["adresse"].toString(),
//             epreuveObj["description"].toString(),
//             epreuveObj["image"].toString(),
//             epreuveObj["transports"].toVariant().toStringList().toVector(),
//             QDateTime::fromString(epreuveObj["horaireDebut"].toString(), Qt::ISODate),
//             epreuveObj["prixBillet"].toDouble(),
//             proximiteRestaurants
//         );
//         listeEpreuves.append(epreuve);
//     }

//     // Traiter les restaurants
//     QJsonArray restaurants = lieux["Restaurants"].toArray();
//     for (const auto &value : restaurants) {
//         QJsonObject restaurantObj = value.toObject();

//         QVector<int> proximiteEpreuves;
//         for (const auto &idVariant : restaurantObj["proximiteEpreuves"].toArray()) {
//             proximiteEpreuves.append(idVariant.toInt());
//         }

//         Restaurant restaurant(
//             restaurantObj["id"].toInt(),
//             restaurantObj["nom"].toString(),
//             restaurantObj["adresse"].toString(),
//             restaurantObj["description"].toString(),
//             restaurantObj["image_epreuve"].toString(),
//             restaurantObj["transports"].toVariant().toStringList().toVector(),
//             restaurantObj["plageHoraire"].toString(),
//             restaurantObj["specialite"].toString(),
//             proximiteEpreuves
//         );
//         listeRestaurants.append(restaurant);
//     }

//     // Ici, vous pouvez utiliser listeEpreuves et listeRestaurants selon vos besoins...
//     // Par exemple, afficher des informations pour tester

//     for (const Epreuve &epreuve : listeEpreuves) {
//         qDebug() << "ID :" << epreuve.getNom();
//         qDebug() << "Nom:" << epreuve.getNom();
//         qDebug() << "Adresse:" << epreuve.getAdresse();
//     }

//     for (const Restaurant &restaurant : listeRestaurants) {
//         qDebug() << "ID :" << restaurant.getNom();
//         qDebug() << "Nom:" << restaurant.getNom();
//         qDebug() << "Adresse:" << restaurant.getAdresse();
//     }

//     return 0;
// }