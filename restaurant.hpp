// restaurant.hpp
#pragma once
#include <QDateTime>

#include "location.hpp"

class Restaurant : public Location
{
public:
    // Constructeur et destructeur
    Restaurant(int id, const QString &name, const QString &address, const QString &description, const QString &locationImage, const QVector<QString> &transportation, const QString &openingHours, const QString &specialty, const QVector<int> &nearbyEvents)
        : Location(id, name, address, description, locationImage, transportation), openingHours(openingHours), specialty(specialty), nearbyEvents(nearbyEvents) {}
    virtual ~Restaurant() {}

    // Getters
    QString getOpeningHours() const { return openingHours; }
    QString getSpecialty() const { return specialty; }
    QVector<int> getNearbyEvents() const { return nearbyEvents; }

    // Méthodes virtual pure à redéfinir
    void display() const override
    {
        qDebug() << "Restaurant " << id << " : " << name;
        qDebug() << "Adresse : " << address;
        qDebug() << "Description : " << description;
        qDebug() << "Image lieu : " << locationImage;
        qDebug() << "Transports : " << transportation;
        qDebug() << "Horaires d'ouverture : " << openingHours;
        qDebug() << "Spécialité : " << specialty;
        qDebug() << "Id des épreuves à proximité : " << nearbyEvents;
    }

    // Méhode virtual getPathForItem() qu'on peut redéfinir mais étant la même que celui de la classe mère, on ne la redéfinie pas

private:
    // Attributes
    QString openingHours;
    QString specialty;
    QVector<int> nearbyEvents;
};
