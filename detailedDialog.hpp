// detailedWindow.hpp
#pragma once
#include <QDialog>
#include <QTextBrowser>
#include <QPushButton>

#include "ui_detailedDialog.h"
#include "event.hpp"
#include "restaurant.hpp"

namespace Ui
{
    class DetailedDialog;
}

class DetailedDialog : public QDialog
{
    Q_OBJECT

public:
    // Constructeur et destructeur
    explicit DetailedDialog(QWidget *parent = nullptr);
    ~DetailedDialog();

    // Méthode
    void setDialogHTML(const QString &codeHTML);
    template <typename T>
    static QString generateDetailsHTML(const T &item, const QStringList &nearbyItemsNames);

private slots:
    // Méthode de slot pour interagir avec l'interface utilisateur
    void closeDetailedDialog();

private:
    // Méthodes
    static QString generateEventDetailsHTML(const Event &event, const QStringList &nearbyRestaurantsNames);
    static QString generateRestaurantDetailsHTML(const Restaurant &restaurant, const QStringList &nearbyEventsNames);
    
    // Attribut
    Ui::DetailedDialog *ui;
    QString codeHTML;
};

/**
 * Méthode template
 * Génère un code HTML pour afficher les détails d'un item selon si c'est un événement ou un restaurant
 * C'est à dire :
 *    - Event : nom, adresse, date, horaire, prix du billet, description, transports et restaurants à proximité
 *    - Restaurant : nom, adresse, horaires, spécialités, description, transports et événements à proximité
 * 
*/
template <typename T>
QString DetailedDialog::generateDetailsHTML(const T &item, const QStringList &nearbyItemsNames)
{
    if constexpr (std::is_same<T, Event>::value)
    {
        return generateEventDetailsHTML(item, nearbyItemsNames);
    }
    else if constexpr (std::is_same<T, Restaurant>::value)
    {
        return generateRestaurantDetailsHTML(item, nearbyItemsNames);
    }
}
