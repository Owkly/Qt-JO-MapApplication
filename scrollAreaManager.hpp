// scrollAreaManager.hpp
#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QObject>
#include <QLabel>

#include "event.hpp"
#include "restaurant.hpp"
#include "dataManager.hpp"
#include "clickableWidget.hpp"
#include "detailedDialog.hpp"

class ScrollAreaManager : public QObject
{
    Q_OBJECT

public:
    // Constructeur et destructeur
    ScrollAreaManager(QScrollArea *scrollArea, QWidget *scrollAreaContentWidget, DataManager *dataManager);
    ~ScrollAreaManager();

    // Méthodes
    void clearScrollArea();
    void setupItemsScrollArea(const QVector<Event> &events, const QVector<Restaurant> &restaurants);
    void addEventToScrollArea(const Event &event);
    void addRestaurantToScrollArea(const Restaurant &restaurant);

signals:
    // Signal pour ouvrir le dialogue détaillé
    void detailedDialogRequested(const QString &details);

private:
    // Méthodes
    ClickableWidget *createMainWidget();

    void addEventTextInfo(QVBoxLayout *layout, const Event &event);
    void addRestaurantTextInfo(QVBoxLayout *layout, const Restaurant &restaurant);

    QLabel *createTextLabel(const QString &text);
    QLabel *createImageLabel(const QString &imagePath);
    void addVerticalSpacer(QVBoxLayout *layout);

    // Attributs
    QScrollArea *scrollArea;       // Le QScrollArea a gérer
    QVBoxLayout *scrollAreaLayout; // Le layout pour organiser les widgets dans le QScrollArea
    DataManager *dataManager;      // Pour accéder aux données
};
