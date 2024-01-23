// Restaurant.hpp
#pragma once
#include "lieu.hpp"

class Restaurant : public Lieu {
public:
    // Constructeurs et destructeur
    // Restaurant() {}
    // Restaurant(const Restaurant &restaurant) : Lieu(restaurant), plageHoraire(restaurant.getPlageHoraire()), specialite(restaurant.getSpecialite()), proximiteEpreuves(restaurant.getProximiteEpreuves()) {}
    Restaurant(int id, const QString &nom, const QString &adresse, const QString &description, const QString &image, const QVector<QString> &transports, const QString &plageHoraire, const QString &specialite, const QVector<int> &proximiteEpreuves) :
        Lieu(id, nom, adresse, description, image, transports), plageHoraire(plageHoraire), specialite(specialite), proximiteEpreuves(proximiteEpreuves) {}
    
    // Getters
    QString getPlageHoraire() const { return plageHoraire; }
    QString getSpecialite() const { return specialite; }
    QVector<int> getProximiteEpreuves() const { return proximiteEpreuves; }

private:
    // Attributs
    QString plageHoraire;
    QString specialite;
    QVector<int> proximiteEpreuves; 
};
