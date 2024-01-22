// Lieu.hpp
#pragma once
#include <QString>
#include <QPixmap>
#include <QVector>

class Lieu {
public:
    Lieu() {}
    Lieu(int id, const QString &nom, const QString &adresse, const QString &description, const QPixmap &image, const QVector<QString> &lignesMetro)
    : id(id), nom(nom), adresse(adresse), description(description), image(image), lignesMetro(lignesMetro) {}
    virtual ~Lieu() {};

    int getId() const { return id; }
    QString getNom() const { return nom; }
    QString getAdresse() const { return adresse; }
    QString getDescription() const { return description; }
    QPixmap getImage() const { return image; }
    QVector<QString> getLignesMetro() const { return lignesMetro; }

protected:
    int id;
    QString nom;
    QString adresse;
    QString description;
    QPixmap image;
    QVector<QString> lignesMetro;
};
