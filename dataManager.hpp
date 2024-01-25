// dataManager.hpp
#pragma once

#include "event.hpp"
#include "restaurant.hpp"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

class DataManager
{
public:
    // Constructeurs et destructeur
    DataManager(const QString &jsonFilePath);
    ~DataManager();

    // Méthodes pour convertir les données du fichier JSON en liste d'objets Epreuve ou Restaurant
    QVector<Event> toListEvents();
    QVector<Restaurant> toListRestaurants();
	
    // Méthode pour lire le fichier JSON  et convertir en QJsonArray
    QJsonArray readJsonArray(const QString &key);

    // Algorithme pour convertir les données du fichier JSON sous forme de QJsonArray en liste d'objets Epreuve ou Restaurant
    QVector<Event> toListEventsAlgo(const QJsonArray &jsonArray);
    QVector<Restaurant> toListRestaurantsAlgo(const QJsonArray &jsonArray);

private:
    QString jsonFilePath;
};
