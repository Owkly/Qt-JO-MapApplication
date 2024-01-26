// event.hpp
#pragma once
#include "location.hpp"
#include <QDateTime>

class Event : public Location
{
public:
    // Constructeur et destructeur
    Event(int id, const QString &name, const QString &address, const QString &description, const QString &locationImage, const QString &eventImage, const QVector<QString> &transportation, const QDateTime &startTime, double ticketPrice, const QVector<int> &nearbyRestaurants)
        : Location(id, name, address, description, locationImage, transportation), eventImage(eventImage), startTime(startTime), ticketPrice(ticketPrice), nearbyRestaurants(nearbyRestaurants) {}
    virtual ~Event() {}

    // Getters
    QString getEventImage() const { return eventImage; }
    QDateTime getStartTime() const { return startTime; }
    double getTicketPrice() const { return ticketPrice; }
    QVector<int> getNearbyRestaurants() const { return nearbyRestaurants; }

    // Méthodes virtual pure redéfinies
    void display() const override{
        qDebug() << "Event " << id << " : " << name;
        qDebug() << "Adresse : " << address;
        qDebug() << "Description : " << description;
        qDebug() << "Image lieu : " << locationImage;
        qDebug() << "Image épreuve : " << eventImage;
        qDebug() << "Transports : " << transportation;
        qDebug() << "Horaire de début : " << startTime.toString();
        qDebug() << "Prix du billet : " << ticketPrice << "€";
        qDebug() << "Id des Restaurants à proximité : " << nearbyRestaurants;
    }


private:
    // Attributes
    QString eventImage;
    QDateTime startTime;
    double ticketPrice;
    QVector<int> nearbyRestaurants;
};
