// lieu.hpp
#pragma once
#include <QString>
#include <QPixmap>
#include <QVector>
#include <QDateTime>

class Lieu {
public:
    // Constructeurs et destructeur
    // Lieu() {}
    Lieu(int id, const QString &nom, const QString &adresse, const QString &description, const QString &image, const QVector<QString> &transports) :
        id(id), nom(nom), adresse(adresse), description(description), image(image), transports(transports) {}
    virtual ~Lieu() {}

    // Getters
    int getId() const { return id; }
    QString getNom() const { return nom; }
    QString getAdresse() const { return adresse; }
    QString getDescription() const { return description; }
    QPixmap getImage() const { return image; }
    QVector<QString> getTransports() const { return transports; }

protected:
    // Attributs
    int id;
    QString nom;
    QString adresse;
    QString description;
    QString image;
    QVector<QString> transports;
};
