// Epreuve.hpp
#pragma once
#include "lieu.hpp"
#include <QDateTime>

class Epreuve : public Lieu {
public:
    Epreuve() {}
    Epreuve(const Epreuve &epreuve) : Lieu(epreuve.getId(), epreuve.getNom(), epreuve.getAdresse(), epreuve.getDescription(), epreuve.getImage(), epreuve.getLignesMetro()), horaire(epreuve.getHoraire()), prixBillet(epreuve.getPrixBillet()) { }
    Epreuve(int id, const QString &nom, const QDateTime &horaire, double prixBillet,
    const QString &adresse, const QString &description, const QPixmap &image, const QVector<QString> &lignesMetro)
    : Lieu(id, nom, adresse, description, image, lignesMetro), horaire(horaire), prixBillet(prixBillet) {}

    QDateTime getHoraire() const { return horaire; }
    double getPrixBillet() const { return prixBillet; }

private:
    QDateTime horaire;
    double prixBillet;
};
