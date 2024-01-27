// detailedWindow.hpp
#pragma once
#include <QDialog>
#include <QTextBrowser>
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

    // Méthodes static utilisable sans instancier la classe
    static QString generateEventDetailsHTML(const Event &event, const QStringList &nearbyRestaurantsNames);
    static QString generateRestaurantDetailsHTML(const Restaurant &restaurant, const QStringList &nearbyEventsNames);

private slots:
    // Méthode de slot pour interagir avec l'interface utilisateur
    void closeDetailedDialog();

private:
    // Attribut
    Ui::DetailedDialog *ui;
    QString codeHTML;
};
