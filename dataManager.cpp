// dataManager.cpp
#include "dataManager.hpp"

// Constructeurs et destructeur
DataManager::DataManager(const QString &jsonFilePath) : jsonFilePath(jsonFilePath) {}

DataManager::~DataManager() {}

// Méthodes pour convertir les données du fichier JSON en liste d'objets Epreuve ou Restaurant
QVector<Event> DataManager::toListEvents()
{
    QJsonArray jsonArray = readJsonArray("Epreuves");
    return toListEventsAlgo(jsonArray);
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
QVector<Event> DataManager::toListEventsAlgo(const QJsonArray &jsonArray)
{
    QVector<Event> listEvents;
    for (const auto &value : jsonArray)
    {
        QJsonObject eventObj = value.toObject();
        QVector<int> nearbyRestaurants;
        for (const auto &idVariant : eventObj["proximiteRestaurant"].toArray())
        {
            nearbyRestaurants.append(idVariant.toInt());
        }

        Event event(
            eventObj["id"].toInt(),
            eventObj["nom"].toString(),
            eventObj["adresse"].toString(),
            eventObj["description"].toString(),
            eventObj["image_lieu"].toString(),
            eventObj["image_epreuve"].toString(),
            eventObj["transports"].toVariant().toStringList().toVector(),
            QDateTime::fromString(eventObj["horaireDebut"].toString(), Qt::ISODate),
            eventObj["prixBillet"].toDouble(),
            nearbyRestaurants);

        listEvents.append(event);
    }
    return listEvents;
}

QVector<Restaurant> DataManager::toListRestaurantsAlgo(const QJsonArray &jsonArray)
{
    QVector<Restaurant> listRestaurants;
    for (const auto &value : jsonArray)
    {
        QJsonObject restaurantObj = value.toObject();
        QVector<int> nearbyEvents;
        for (const auto &idVariant : restaurantObj["proximiteEpreuves"].toArray())
        {
            nearbyEvents.append(idVariant.toInt());
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
            nearbyEvents);

        listRestaurants.append(restaurant);
    }
    return listRestaurants;
}
