// datasManager.cpp
#include "dataManager.hpp"

// Constructeur et Destructeur
DataManager::DataManager(const QString &jsonFilePath) : jsonFilePath(jsonFilePath) 
{
    listEvents = toListEvents();
    listRestaurants = toListRestaurants();
}

DataManager::~DataManager() {}

// Méthode pour lire le fichier JSON et convertir les données en QJsonArray
QJsonArray DataManager::readJsonArray(const QString &key)
{
    QFile file(jsonFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw std::runtime_error("Erreur readJsonArray dans dataManager.cpp : impossible d'ouvrir le fichier JSON");
    }

    QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonObject rootObject = document.object()["lieux"].toObject();
    return rootObject[key].toArray();
}

// Convertir un objet JSON en un objet Event
Event DataManager::toEvent(const QJsonObject &eventObj)
{
    QVector<int> nearbyRestaurants;
    for (const auto &idVariant : eventObj["proximiteRestaurant"].toArray())
    {
        nearbyRestaurants.append(idVariant.toInt());
    }

    return Event(
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
}

// Convertir un objet JSON en un objet Restaurant
Restaurant DataManager::toRestaurant(const QJsonObject &restaurantObj)
{
    QVector<int> nearbyEvents;
    for (const auto &idVariant : restaurantObj["proximiteEpreuves"].toArray())
    {
        nearbyEvents.append(idVariant.toInt());
    }

    return Restaurant(
        restaurantObj["id"].toInt(),
        restaurantObj["nom"].toString(),
        restaurantObj["adresse"].toString(),
        restaurantObj["description"].toString(),
        restaurantObj["image"].toString(),
        restaurantObj["transports"].toVariant().toStringList().toVector(),
        restaurantObj["plageHoraire"].toString(),
        restaurantObj["specialite"].toString(),
        nearbyEvents);
}

// Convertir les données du fichier JSON en liste d'objets Event
QVector<Event> DataManager::toListEvents()
{
    QJsonArray jsonArray = readJsonArray("Epreuves");
    QVector<Event> listEvents;
    for (const auto &value : jsonArray)
    {
        listEvents.append(toEvent(value.toObject()));
    }
    return listEvents;
}

// Convertir les données du fichier JSON en liste d'objets Restaurant
QVector<Restaurant> DataManager::toListRestaurants()
{
    QJsonArray jsonArray = readJsonArray("Restaurants");
    QVector<Restaurant> listRestaurants;
    for (const auto &value : jsonArray)
    {
        listRestaurants.append(toRestaurant(value.toObject()));
    }
    return listRestaurants;
}

// Méthode pour rechercher les Events en fonction de leur nom ou adresse et du filtre
QVector<Event> DataManager::searchEvents(const QString &searchText, const QString &filterType)
{
    QVector<Event> searchResults;
    if (filterType == "Tout" || filterType == "Epreuves") {
        for (const Event &event : listEvents) {
            if (event.getName().contains(searchText, Qt::CaseInsensitive) || 
                event.getAddress().contains(searchText, Qt::CaseInsensitive)) {
                searchResults.append(event);
            }
        }
    }
    return searchResults;
}

// Méthode pour rechercher les Restaurants en fonction de leur nom ou adresse et du filtre
QVector<Restaurant> DataManager::searchRestaurants(const QString &searchText, const QString &filterType)
{
    QVector<Restaurant> searchResults;
    if (filterType == "Tout" || filterType == "Restaurants") {
        for (const Restaurant &restaurant : listRestaurants) {
            if (restaurant.getName().contains(searchText, Qt::CaseInsensitive) || 
                restaurant.getAddress().contains(searchText, Qt::CaseInsensitive)) {
                searchResults.append(restaurant);
            }
        }
    }
    return searchResults;
}
