#include <QApplication>
#include "mainWindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowIcon(QIcon(":/images/icon.png"));
    mainWindow.show();

    // // Marche que si listEvents et listRestaurants sont publics dans mainWindow.hpp
    // // Test de la méthode display() de la classe Event et Restaurant
    // mainWindow.listEvents[0].display();
    // mainWindow.listRestaurants[0].display();
    // // Test de la méthode display() de la classe Location
    // Location location(1, "LocationName", "LocationAddress", "LocationDescription", "LocationImagePath", QVector<QString>{"Transport1", "Transport2"});
    // location.display();

    return app.exec();
}
