#include "mainwindow.hpp"
#include "epreuve.hpp"

#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QPixmap>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     // Initialisation d'une Epreuve
//     // QPixmap imageBasket("/home/weikai/Téléchargements/basket.jpg"); // Assurez-vous que le chemin est correct
//     QPixmap imageBasket("images/basket.jpg"); // Assurez-vous que le chemin est correct
//     QVector<QString> lignesMetroBasket;
//     lignesMetroBasket.append("1");  // Ajoute la ligne de métro "1"
//     lignesMetroBasket.append("14"); // Ajoute la ligne de métro "14"
//     // Créez une date et une heure pour l'épreuve
//     QDateTime horaireBasket = QDateTime::fromString("2024-07-24T09:00:00", Qt::ISODate);

//     Epreuve basket(1, "100m femmes", horaireBasket, 50.0,
//                    "Stade de France", "Stade principal pour les épreuves d'athlétisme et de rugby",
//                    imageBasket, lignesMetroBasket);
//     Epreuve foot(2, "100m hommes", horaireBasket, 50.0,
//                  "Stade de France", "Stade principal pour les épreuves d'athlétisme et de rugby",
//                  imageBasket, lignesMetroBasket);

//     QList<Epreuve> epreuves;
//     epreuves.append(basket);
//     epreuves.append(foot);
//     epreuves.append(basket);
//     epreuves.append(foot);
//     epreuves.append(basket);
//     epreuves.append(foot);

//     MainWindow w;
//     w.setEpreuve(basket);
//     w.afficherEpreuves(epreuves);
//     w.show();
//     return a.exec();
// }

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

    // Liste d'épreuves (exemple avec des données fictives)
    QList<Epreuve> listeEpreuves;

    // Épreuve 1
    QDateTime horaire1 = QDateTime::fromString("2024-07-24T09:00:00", Qt::ISODate);
    QPixmap image1(":/images/basket.jpg");
    QVector<QString> lignesMetro1 = {"Ligne 1", "Ligne 14"};
    Epreuve epreuve1(1, "100m femmes", horaire1, 50.0,
                     "Stade de France", "Stade principal pour les épreuves d'athlétisme et de rugby",
                     image1, lignesMetro1);
    listeEpreuves.append(epreuve1);

    // Épreuve 2
    QDateTime horaire2 = QDateTime::fromString("2024-07-25T11:30:00", Qt::ISODate);
    QPixmap image2(":/images/basket.jpg");
    QVector<QString> lignesMetro2 = {"Ligne 2", "Ligne 8"};
    Epreuve epreuve2(2, "200m hommes", horaire2, 45.0,
                     "Stade Olympique", "Stade principal pour les épreuves d'athlétisme",
                     image2, lignesMetro2);
    listeEpreuves.append(epreuve2);

    // Épreuve 2
    QDateTime horaire3 = QDateTime::fromString("2024-07-25T11:30:00", Qt::ISODate);
    QPixmap image3(":/images/basket.jpg");
    QVector<QString> lignesMetro3 = {"Ligne 2", "Ligne 8"};
    Epreuve epreuve3(2, "200m hommes", horaire3, 45.0,
                     "Stade Olympique", "Stade principal pour les épreuves d'athlétisme",
                     image3, lignesMetro3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);

    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);

    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);

    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    listeEpreuves.append(epreuve3);
    // ...

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