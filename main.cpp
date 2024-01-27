#include <QApplication>
#include "mainWindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.setWindowIcon(QIcon(":/images/icon.png"));
    mainWindow.show();
    return app.exec();
}

// #include <QDebug>
// #include "event.hpp"
// #include "restaurant.hpp"

// int main()
// {
//     // Test des constructeurs
//     Event event1(1, "Concert", "123 Main St", "Un grand concert", "image1.jpg", "event1.jpg", {"Bus", "Train"}, QDateTime::currentDateTime(), 50.0, {2, 3});
//     Event event2(2, "Match", "456 Side St", "Un match passionnant", "image2.jpg", "event2.jpg", {"Métro"}, QDateTime::currentDateTime(), 30.0, {1, 4});

//     Restaurant restaurant1(3, "Chez Pierre", "789 River Rd", "Cuisine française", "image3.jpg", {"Bus", "Métro"}, "08:00 - 22:00", "Française", {1});
//     Restaurant restaurant2(4, "Sushi House", "101 Ocean Dr", "Cuisine japonaise", "image4.jpg", {"Tram"}, "10:00 - 23:00", "Japonaise", {2});

//     // Test de l'opérateur ==
//     qDebug() << "=====================================================";
//     qDebug() << "Test de l'opérateur ==";
//     qDebug() << "Event1 est égal à Event1:" << (event1 == event1);
//     qDebug() << "Restaurant1 est égal à Restaurant1:" << (restaurant1 == restaurant1);
//     qDebug() << "Event1 est égal à Event2:" << (event1 == event2);
//     qDebug() << "Restaurant1 est égal à Restaurant2:" << (restaurant1 == restaurant2);

//     // Test des méthodes display()
//     qDebug() << "=====================================================";
//     qDebug() << "Test des méthodes display()";
//     event1.display();
//     qDebug() << "";
//     restaurant1.display();

//     // Test de l'opérateur d'affectation
//     qDebug() << "=====================================================";
//     qDebug() << "Test de l'opérateur d'affectation";
//     event2 = event1;
//     restaurant2 = restaurant1;

//     // Affichage des détails après affectation
//     qDebug() << "=====================================================";
//     qDebug() << "Après affectation:";
//     event2.display();
//     qDebug() << "";
//     restaurant2.display();

//     return 0;
// }
