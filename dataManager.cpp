// dataManager.cpp
#include "dataManager.hpp"

// Constructeurs et destructeur
DataManager::DataManager(const QString &jsonFilePath) : jsonFilePath(jsonFilePath) {}

DataManager::~DataManager() {}

// Méthodes pour convertir les données du fichier JSON en liste d'objets Epreuve ou Restaurant
QVector<Epreuve> DataManager::toListEpreuves()
{
    QJsonArray jsonArray = readJsonArray("Epreuves");
    return toListEpreuvesAlgo(jsonArray);
}

QVector<Restaurant> DataManager::toListRestaurants()
{
    QJsonArray jsonArray = readJsonArray("Restaurants");
    return toListRestaurantsAlgo(jsonArray);
}

// Méthode pour lire le fichier JSON  et convertir en QJsonArray
QJsonArray DataManager::readJsonArray(const QString &key)
{
    QFile file(jsonFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Impossible d'ouvrir le fichier pour la lecture.";
        return QJsonArray();
    }

    QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonObject rootObject = document.object()["lieux"].toObject();
    return rootObject[key].toArray();
}

// Algorithme pour convertir les données du fichier JSON sous forme de QJsonArray en liste d'objets Epreuve ou Restaurant
QVector<Epreuve> DataManager::toListEpreuvesAlgo(const QJsonArray &jsonArray)
{
    QVector<Epreuve> listeEpreuves;
    for (const auto &value : jsonArray)
    {
        QJsonObject epreuveObj = value.toObject();
        QVector<int> proximiteRestaurants;
        for (const auto &idVariant : epreuveObj["proximiteRestaurant"].toArray())
        {
            proximiteRestaurants.append(idVariant.toInt());
        }

        Epreuve epreuve(
            epreuveObj["id"].toInt(),
            epreuveObj["nom"].toString(),
            epreuveObj["adresse"].toString(),
            epreuveObj["description"].toString(),
            epreuveObj["image"].toString(),
            epreuveObj["transports"].toVariant().toStringList().toVector(),
            QDateTime::fromString(epreuveObj["horaireDebut"].toString(), Qt::ISODate),
            epreuveObj["prixBillet"].toDouble(),
            proximiteRestaurants);

        listeEpreuves.append(epreuve);
    }
    return listeEpreuves;
}

QVector<Restaurant> DataManager::toListRestaurantsAlgo(const QJsonArray &jsonArray)
{
    QVector<Restaurant> listeRestaurants;
    for (const auto &value : jsonArray)
    {
        QJsonObject restaurantObj = value.toObject();
        QVector<int> proximiteEpreuves;
        for (const auto &idVariant : restaurantObj["proximiteEpreuves"].toArray())
        {
            proximiteEpreuves.append(idVariant.toInt());
        }

        Restaurant restaurant(
            restaurantObj["id"].toInt(),
            restaurantObj["nom"].toString(),
            restaurantObj["adresse"].toString(),
            restaurantObj["description"].toString(),
            restaurantObj["image"].toString(),
            restaurantObj["transports"].toVariant().toStringList().toVector(),
            restaurantObj["plageHoraire"].toString(),
            restaurantObj["specialite"].toString(),
            proximiteEpreuves);

        listeRestaurants.append(restaurant);
    }
    return listeRestaurants;
}
