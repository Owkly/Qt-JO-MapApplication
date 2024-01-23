// Lieu.hpp
#pragma once
#include "entite.hpp"
#include <QPixmap>
#include <QVector>
#include <QString>
#include <QDebug>


class Lieu : public Entite {
public:
    // Constructeurs et destructeur
    Lieu(int id, const QString &nom, const QString &adresse, const QString &description, const QString &image, const QVector<QString> &transports) :
        Entite(id), nom(nom), adresse(adresse), description(description), image(image), transports(transports) {}
    virtual ~Lieu() {}

    // Getters
    QString getNom() const { return nom; }
    QString getAdresse() const { return adresse; }
    QString getDescription() const { return description; }
    QPixmap getImage() const { return image; }
    QVector<QString> getTransports() const { return transports; }

    // Méthode virtuelle implémentée
    void afficher() const override {
        qDebug() << "Lieu " << id << " : " << nom << " (" << adresse << ")";
        // qDebug() << "Description : " << description;
        // qDebug() << "Image : " << image;
        // qDebug() << "Transports : " << transports;
    }

protected:
    // Attributs
    QString nom;
    QString adresse;
    QString description;
    QString image;
    QVector<QString> transports;
};
