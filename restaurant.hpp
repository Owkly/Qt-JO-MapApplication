// Restaurant.hpp
#pragma once
#include "lieu.hpp"

class Restaurant : public Lieu {
public:
    Restaurant(int id, const QString &nom, const QString &specialite, const QString &horaire, 
	const QString &adresse, const QString &description, const QPixmap &image, const QVector<QString> &lignesMetro, const QVector<int> &proximiteEpreuves):
	Lieu(id, nom, adresse, description, image, lignesMetro), specialite(specialite), horaire(horaire), proximiteEpreuves(proximiteEpreuves) {}

    QString getSpecialite() const { return specialite; }
    QString getHoraire() const { return horaire; }
    QVector<int> getProximiteEpreuves() const { return proximiteEpreuves; }

private:
    QString specialite;
    QString horaire;
    QVector<int> proximiteEpreuves;
};
