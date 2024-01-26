// dataManager.hpp
#pragma once
#include "event.hpp"
#include "restaurant.hpp"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

#include <optional>

class DataManager
{
public:
    // Constructeurs et destructeur
    DataManager(const QString &jsonFilePath);
    ~DataManager();

    // Getters
    QVector<Event> getListEvents() const { return listEvents; }
    QVector<Restaurant> getListRestaurants() const { return listRestaurants; }

    // Méthodes
    QVector<Event> searchEvents(const QString &searchText, const QString &filterType);
    QVector<Restaurant> searchRestaurants(const QString &searchText, const QString &filterType);

private:
    // Attributs
    QString jsonFilePath;
    QVector<Event> listEvents;
    QVector<Restaurant> listRestaurants;

    // Méthodes
    QJsonArray readJsonArray(const QString &key);
    Event toEvent(const QJsonObject &eventObj);
    Restaurant toRestaurant(const QJsonObject &restaurantObj);
    QVector<Event> toListEvents();
    QVector<Restaurant> toListRestaurants();
};
