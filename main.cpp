#include "mainwindow.hpp"

#include <QApplication>

#include <epreuve.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Initialisation d'une Epreuve
    QPixmap imageBasket("/home/weikai/Téléchargements/basket.jpg"); // Assurez-vous que le chemin est correct
    QVector<QString> lignesMetroBasket;
    lignesMetroBasket.append("1");  // Ajoute la ligne de métro "1"
    lignesMetroBasket.append("14"); // Ajoute la ligne de métro "14"
    // Créez une date et une heure pour l'épreuve
    QDateTime horaireBasket = QDateTime::fromString("2024-07-24T09:00:00", Qt::ISODate);

    Epreuve basket(1, "100m femmes", horaireBasket, 50.0,
                   "Stade de France", "Stade principal pour les épreuves d'athlétisme et de rugby",
                   imageBasket, lignesMetroBasket);

    MainWindow w;
    w.setEpreuve(basket);
    w.show();
    return a.exec();
}
