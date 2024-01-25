// restaurant.hpp
#pragma once
#include "location.hpp"
#include <QDateTime>

class Restaurant : public Location {
public:
    // Constructeur et destructeur
Restaurant(int id, const QString &name, const QString &address, const QString &description, const QString &locationImage, const QVector<QString> &transportation, const QString &openingHours, const QString &specialty, const QVector<int> &nearbyEvents) :
        Location(id, name, address, description, locationImage, transportation), openingHours(openingHours), specialty(specialty), nearbyEvents(nearbyEvents) {}
    virtual ~Restaurant() {}

    // Getters
    QString getOpeningHours() const { return openingHours; }
    QString getSpecialty() const { return specialty; }
    QVector<int> getNearbyEvents() const { return nearbyEvents; }

    // Méthodes
    void display() const override {
        qDebug() << "Restaurant " << id << " : " << name << " (" << address << ")";
    }

private:
    // Attributes
    QString openingHours;
    QString specialty;
    QVector<int> nearbyEvents;
};
