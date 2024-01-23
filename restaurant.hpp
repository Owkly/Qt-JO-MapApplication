// restaurant.hpp
#pragma once
#include "lieu.hpp"
#include <QDateTime>

class Restaurant : public Lieu {
public:
    // Constructeurs et destructeur
    // Restaurant() {}
    // Restaurant(const Restaurant &restaurant) : Lieu(restaurant), plageHoraire(restaurant.getPlageHoraire()), specialite(restaurant.getSpecialite()), proximiteEpreuves(restaurant.getProximiteEpreuves()) {}
    Restaurant(int id, const QString &nom, const QString &adresse, const QString &description, const QString &image, const QVector<QString> &transports, const QString &plageHoraire, const QString &specialite, const QVector<int> &proximiteEpreuves) :
        Lieu(id, nom, adresse, description, image, transports), plageHoraire(plageHoraire), specialite(specialite), proximiteEpreuves(proximiteEpreuves) {}
    virtual ~Restaurant() {}

    // Getters
    QString getPlageHoraire() const { return plageHoraire; }
    QString getSpecialite() const { return specialite; }
    QVector<int> getProximiteEpreuves() const { return proximiteEpreuves; }

    // Méthode virtuelle implémentée
    void afficher() const override {
        // Implémentation d'affichage pour Epreuve
        qDebug() << "Restaurant " << id << " : " << nom << " (" << adresse << ")";
        // qDebug() << "Description : " << description;
        // qDebug() << "Image : " << image;
        // qDebug() << "Transports : " << transports;
        // qDebug() << "Plage horaire : " << plageHoraire;
        // qDebug() << "Spécialité : " << specialite;
        // qDebug() << "Proximité des épreuves : " << proximiteEpreuves;
    }
private:
    // Attributs
    QString plageHoraire;
    QString specialite;
    QVector<int> proximiteEpreuves; 
};
