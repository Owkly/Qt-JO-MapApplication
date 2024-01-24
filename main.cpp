//#include "mainWindow.hpp"
//#include "epreuve.hpp"
//#include "restaurant.hpp"
//#include "dataManager.hpp"

//#include <QApplication>
//#include <QScrollArea>
//#include <QLabel>
//#include <QVBoxLayout>


//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    // Créer le widget principal
//    QWidget mainWidget;

//    // Créer un layout vertical pour le widget principal
//    QVBoxLayout *mainLayout = new QVBoxLayout(&mainWidget);

//    // Créer un QScrollArea
//    QScrollArea *scrollArea = new QScrollArea;

//    // Créer un widget qui servira de conteneur pour les éléments de la liste
//    QWidget *scrollWidget = new QWidget;
//    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);



//    DataManager dataManager(":/lieux.json");
//    QVector<Epreuve> listeEpreuves = dataManager.toListEpreuves();
//    QVector<Restaurant> listeRestaurants = dataManager.toListRestaurants();

//    // Ajouter les épreuves à la liste
//    for (const Epreuve &epreuve : listeEpreuves)
//    {
//        // Créer un widget pour chaque épreuve
//        QWidget *epreuveWidget = new QWidget;
//        QHBoxLayout *epreuveLayout = new QHBoxLayout(epreuveWidget);

//        // Ajouter une image à gauche
//        QLabel *imageLabel = new QLabel;
//        imageLabel->setPixmap(epreuve.getImage().scaled(50, 50)); // Ajustez la taille selon vos besoins
//        epreuveLayout->addWidget(imageLabel);

//        // Ajouter les informations à droite
//        QVBoxLayout *infoLayout = new QVBoxLayout;
//        QLabel *nomLabel = new QLabel(epreuve.getNom());
//        QLabel *adresseLabel = new QLabel(epreuve.getAdresse());
//        QLabel *descriptionLabel = new QLabel(epreuve.getDescription());
//        infoLayout->addWidget(nomLabel);
//        infoLayout->addWidget(adresseLabel);
//        infoLayout->addWidget(descriptionLabel);
//        epreuveLayout->addLayout(infoLayout);

//        // Ajouter le widget de l'épreuve au layout du widget de la liste
//        scrollLayout->addWidget(epreuveWidget);
//    }

//    for (const Restaurant &epreuve : listeRestaurants)
//    {
//        // Créer un widget pour chaque épreuve
//        QWidget *epreuveWidget = new QWidget;
//        QHBoxLayout *epreuveLayout = new QHBoxLayout(epreuveWidget);

//        // Ajouter une image à gauche
//        QLabel *imageLabel = new QLabel;
//        imageLabel->setPixmap(epreuve.getImage().scaled(50, 50)); // Ajustez la taille selon vos besoins
//        epreuveLayout->addWidget(imageLabel);

//        // Ajouter les informations à droite
//        QVBoxLayout *infoLayout = new QVBoxLayout;
//        QLabel *nomLabel = new QLabel(epreuve.getNom());
//        QLabel *adresseLabel = new QLabel(epreuve.getAdresse());
//        QLabel *descriptionLabel = new QLabel(epreuve.getDescription());
//        infoLayout->addWidget(nomLabel);
//        infoLayout->addWidget(adresseLabel);
//        infoLayout->addWidget(descriptionLabel);
//        epreuveLayout->addLayout(infoLayout);

//        // Ajouter le widget de l'épreuve au layout du widget de la liste
//        scrollLayout->addWidget(epreuveWidget);
//    }

//    // Configurer le QScrollArea
//    scrollArea->setWidget(scrollWidget);
//    scrollArea->setWidgetResizable(true);

//    // Ajouter le QScrollArea à la moitié droite du layout principal
//    mainLayout->addWidget(new QWidget);   // Espace vide à gauche
//    mainLayout->addWidget(scrollArea, 1); // QScrollArea prend la moitié droite

//    // Configurer le widget principal
//    mainWidget.setLayout(mainLayout);
//    mainWidget.setWindowTitle("Liste d'Epreuves");
//    mainWidget.resize(800, 600); // Ajustez la taille selon vos besoins
//    mainWidget.show();

//    return a.exec();
//}

// #include "mainWindow.hpp"
// #include <QApplication>

// int main(int argc, char *argv[]) {
//     QApplication a(argc, argv);
//     MainWindow w;
//     w.show();
//     return a.exec();
// }


// #include "entite.hpp"
// #include "lieu.hpp"
// #include "epreuve.hpp"
// #include "restaurant.hpp"
// #include <QDebug>
// #include <QDateTime>

// int main() {
//     // Création d'un lieu
//     Lieu tourEiffel(1, "Tour Eiffel", "Champ de Mars, 5 Avenue Anatole France, 75007 Paris", 
//                     "Une tour de fer puddlé de 330 mètres de hauteur", 
//                     "path/to/image/tour_eiffel.jpg", {"Bus", "Métro"});
//     tourEiffel.afficher();

//     // Création d'une épreuve
//     Epreuve natation(2, "Compétition de natation", "Piscine Olympique, Paris", 
//                      "Épreuve de natation 100m nage libre", "path/to/image/natation.jpg", 
//                      {"Bus", "Métro"}, QDateTime::currentDateTime(), 50.0, {3, 4});
//     natation.afficher();

//     // Création d'un restaurant
//     Restaurant leJulesVerne(3, "Le Jules Verne", "Tour Eiffel, Paris", 
//                             "Restaurant gastronomique français situé au deuxième étage de la Tour Eiffel", 
//                             "path/to/image/le_jules_verne.jpg", {"Bus", "Métro"}, 
//                             "12:00 - 15:00, 19:00 - 23:00", "Cuisine française", {2});
//     leJulesVerne.afficher();

//     return 0;
// }

#include <QApplication>
#include "mainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
