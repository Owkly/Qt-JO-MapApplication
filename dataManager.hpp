// dataManager.hpp
#pragma once

#include "epreuve.hpp"
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
    QVector<Epreuve> toListEpreuves();
    QVector<Restaurant> toListRestaurants();
	
    // Méthode pour lire le fichier JSON  et convertir en QJsonArray
    QJsonArray readJsonArray(const QString &key);

    // Algorithme pour convertir les données du fichier JSON sous forme de QJsonArray en liste d'objets Epreuve ou Restaurant
    QVector<Epreuve> toListEpreuvesAlgo(const QJsonArray &jsonArray);
    QVector<Restaurant> toListRestaurantsAlgo(const QJsonArray &jsonArray);

private:
    QString jsonFilePath;
};
