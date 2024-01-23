// #include "mainwindow.hpp"
// #include "epreuve.hpp"
// #include "restaurant.hpp"
// #include "dataManager.hpp"

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);

//     // Créer le widget principal
//     QWidget mainWidget;

//     // Créer un layout vertical pour le widget principal
//     QVBoxLayout *mainLayout = new QVBoxLayout(&mainWidget);

//     // Créer un QScrollArea
//     QScrollArea *scrollArea = new QScrollArea;

//     // Créer un widget qui servira de conteneur pour les éléments de la liste
//     QWidget *scrollWidget = new QWidget;
//     QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);



//     DataManager dataManager(":/lieux.json");
//     QVector<Epreuve> listeEpreuves = dataManager.toListEpreuves();
//     QVector<Restaurant> listeRestaurants = dataManager.toListRestaurants();

//     // Ajouter les épreuves à la liste
//     for (const Epreuve &epreuve : listeEpreuves)
//     {
//         // Créer un widget pour chaque épreuve
//         QWidget *epreuveWidget = new QWidget;
//         QHBoxLayout *epreuveLayout = new QHBoxLayout(epreuveWidget);

//         // Ajouter une image à gauche
//         QLabel *imageLabel = new QLabel;
//         imageLabel->setPixmap(epreuve.getImage().scaled(50, 50)); // Ajustez la taille selon vos besoins
//         epreuveLayout->addWidget(imageLabel);

//         // Ajouter les informations à droite
//         QVBoxLayout *infoLayout = new QVBoxLayout;
//         QLabel *nomLabel = new QLabel(epreuve.getNom());
//         QLabel *adresseLabel = new QLabel(epreuve.getAdresse());
//         QLabel *descriptionLabel = new QLabel(epreuve.getDescription());
//         infoLayout->addWidget(nomLabel);
//         infoLayout->addWidget(adresseLabel);
//         infoLayout->addWidget(descriptionLabel);
//         epreuveLayout->addLayout(infoLayout);

//         // Ajouter le widget de l'épreuve au layout du widget de la liste
//         scrollLayout->addWidget(epreuveWidget);
//     }

//     for (const Restaurant &epreuve : listeRestaurants)
//     {
//         // Créer un widget pour chaque épreuve
//         QWidget *epreuveWidget = new QWidget;
//         QHBoxLayout *epreuveLayout = new QHBoxLayout(epreuveWidget);

//         // Ajouter une image à gauche
//         QLabel *imageLabel = new QLabel;
//         imageLabel->setPixmap(epreuve.getImage().scaled(50, 50)); // Ajustez la taille selon vos besoins
//         epreuveLayout->addWidget(imageLabel);

//         // Ajouter les informations à droite
//         QVBoxLayout *infoLayout = new QVBoxLayout;
//         QLabel *nomLabel = new QLabel(epreuve.getNom());
//         QLabel *adresseLabel = new QLabel(epreuve.getAdresse());
//         QLabel *descriptionLabel = new QLabel(epreuve.getDescription());
//         infoLayout->addWidget(nomLabel);
//         infoLayout->addWidget(adresseLabel);
//         infoLayout->addWidget(descriptionLabel);
//         epreuveLayout->addLayout(infoLayout);

//         // Ajouter le widget de l'épreuve au layout du widget de la liste
//         scrollLayout->addWidget(epreuveWidget);
//     }

//     // Configurer le QScrollArea
//     scrollArea->setWidget(scrollWidget);
//     scrollArea->setWidgetResizable(true);

//     // Ajouter le QScrollArea à la moitié droite du layout principal
//     mainLayout->addWidget(new QWidget);   // Espace vide à gauche
//     mainLayout->addWidget(scrollArea, 1); // QScrollArea prend la moitié droite

//     // Configurer le widget principal
//     mainWidget.setLayout(mainLayout);
//     mainWidget.setWindowTitle("Liste d'Epreuves");
//     mainWidget.resize(800, 600); // Ajustez la taille selon vos besoins
//     mainWidget.show();

//     return a.exec();
// }

#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


