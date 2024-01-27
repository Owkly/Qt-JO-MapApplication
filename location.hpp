// Location.hpp
#pragma once
#include "entity.hpp"
#include <QPixmap>
#include <QVector>
#include <QDebug>

class Location : public Entity
{
public:
    // Constructeur et destructeur
    Location(int id, const QString &name, const QString &address, const QString &description, const QString &locationImage, const QVector<QString> &transportation) : Entity(id), name(name), address(address), description(description), locationImage(locationImage), transportation(transportation) {}
    virtual ~Location() {}

    // Getters
    QString getName() const { return name; }
    QString getAddress() const { return address; }
    QString getDescription() const { return description; }
    QString getLocationImage() const { return locationImage; }
    QVector<QString> getTransportation() const { return transportation; }

    // Méthode virtuelle pure redéfinie
    void display() const override
    {
        qDebug() << "Location " << id << " : " << name;
        qDebug() << "Adresse : " << address;
        qDebug() << "Description : " << description;
        qDebug() << "Image lieu : " << locationImage;
        qDebug() << "Transports : " << transportation;
    }

    virtual QString getPathForItem() const { return locationImage; }

protected:
    // Attributs
    QString name;
    QString address;
    QString description;
    QString locationImage;
    QVector<QString> transportation;
};
