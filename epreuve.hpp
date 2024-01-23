// epreuve.hpp
#pragma once
#include "lieu.hpp"
#include <QDateTime>

class Epreuve : public Lieu {
public:
    // Constructeurs et destructeur
    // Epreuve() {}
    // Epreuve(const Epreuve &epreuve) : Lieu(epreuve), horaireDebut(epreuve.getHoraireDebut()), prixBillet(epreuve.getPrixBillet()), proximiteRestaurants(epreuve.getProximiteRestaurants()) {}
    Epreuve(int id, const QString &nom, const QString &adresse, const QString &description, const QString &image, const QVector<QString> &transports, const QDateTime &horaireDebut, double prixBillet, const QVector<int> &proximiteRestaurants) :
        Lieu(id, nom, adresse, description, image, transports), horaireDebut(horaireDebut), prixBillet(prixBillet), proximiteRestaurants(proximiteRestaurants) {}
    virtual ~Epreuve() {}

    // Getters
    QDateTime getHoraireDebut() const { return horaireDebut; }
    double getPrixBillet() const { return prixBillet; }
    QVector<int> getProximiteRestaurants() const { return proximiteRestaurants; }

    // Méthode virtuelle implémentée
    void afficher() const override {
        // Implémentation d'affichage pour Epreuve
        qDebug() << "Epreuve " << id << " : " << nom << " (" << adresse << ")";
        // qDebug() << "Description : " << description;
        // qDebug() << "Image : " << image;
        // qDebug() << "Transports : " << transports;
        // qDebug() << "Horaire de début : " << horaireDebut;
        // qDebug() << "Prix du billet : " << prixBillet;
        // qDebug() << "Proximité des restaurants : " << proximiteRestaurants;
    }

private:
    // Attributs
    QDateTime horaireDebut;
    double prixBillet;
    QVector<int> proximiteRestaurants;
};
