// detailedDialog.cpp
#include "detailedDialog.hpp"

// Constructeur
DetailedDialog::DetailedDialog(QWidget *parent) : QDialog(parent), ui(new Ui::DetailedDialog) 
{
    ui->setupUi(this);
    this->setWindowTitle("Informations détaillées");
    this->setFixedSize(600, 630);

    // Trouver le bouton "Ok" dans le QDialogButtonBox s'il est cliqué, fermer la fenêtre
    QPushButton *okButton = ui->DialogOkButton->button(QDialogButtonBox::Ok);
    connect(okButton, &QPushButton::clicked, this, &DetailedDialog::closeDetailedDialog);
}

// Destructeur
DetailedDialog::~DetailedDialog()
{
    delete ui;
}

// Méthode pour afficher le code HTML dans une fenêtre de dialogue (dans une zone de texte)
void DetailedDialog::setDialogHTML(const QString &codeHTML)
{
    ui->textBrowser->setHtml(codeHTML);
}

// Méthode pour fermer la fenêtre de dialogue
void DetailedDialog::closeDetailedDialog()
{
    this->close();
}

// Méthode pour générer le code HTML dans lequel il y a toutes les informations d'un événement
QString DetailedDialog::generateEventDetailsHTML(const Event &event, const QStringList &nearbyRestaurantsNames)
{
    QString codeHTML;
    codeHTML += "<html><head><style>"
                "div.container { display: flex; align-items: flex-start; } "
                "div.container > div { margin: 10px; } "
                "div.image { width: 300px; } "
                "div.info { width: 300px; margin-left: 10px; } "
                "</style></head><body>"
                "<div class='container'>"
                "<div class='image'><img src='" + event.getLocationImage() + "' width='300' height='300'></div>"
                "<div class='info'>"
                "<p><b>Nom:</b> " + event.getName() + "</p>"
                "<p><b>Adresse:</b> " + event.getAddress() + "</p>"
                "<p><b>Date:</b> " + event.getStartTime().toString("dd/MM/yyyy") + "</p>"           // UNIQUEMENT POUR LES ÉPREUVES 
                "<p><b>Horaire:</b> " + event.getStartTime().toString("hh:mm") + "</p>"             // UNIQUEMENT POUR LES ÉPREUVES
                "<p><b>Prix Billet:</b> " + QString::number(event.getTicketPrice()) + " €</p>"      // UNIQUEMENT POUR LES ÉPREUVES
                "<p><b>Description:</b> " + event.getDescription() + "</p>"
                "<p><b>Transports:</b> " + QStringList::fromVector(event.getTransportation()).join(", ") + "</p>"
                "<p><b>Restaurants à proximité:</b> " + nearbyRestaurantsNames.join(", ") + "</p>"  // UNIQUEMENT POUR LES ÉPREUVES
                "</div>"
                "</div>"
                "</body></html>";
    
    return codeHTML;
}

// Méthode pour générer le code HTML dans lequel il y a toutes les informations d'un restaurant
QString DetailedDialog::generateRestaurantDetailsHTML(const Restaurant &restaurant, const QStringList &nearbyEventsNames)
{
    QString codeHTML;
    codeHTML += "<html><head><style>"
                "div.container { display: flex; align-items: flex-start; } "
                "div.container > div { margin: 10px; } "
                "div.image { width: 300px; } "
                "div.info { width: 300px; margin-left: 10px; } "
                "</style></head><body>"
                "<div class='container'>"
                "<div class='image'><img src='" + restaurant.getLocationImage() + "' width='300' height='300'></div>"
                "<div class='info'>"
                "<p><b>Nom:</b> " + restaurant.getName() + "</p>"
                "<p><b>Adresse:</b> " + restaurant.getAddress() + "</p>"
                "<p><b>Horaires:</b> " + restaurant.getOpeningHours() + "</p>"                    // UNIQUEMENT POUR LES RESTAURANTS    
                "<p><b>Spécialité:</b> " + restaurant.getSpecialty() + "</p>"                     // UNIQUEMENT POUR LES RESTAURANTS
                "<p><b>Description:</b> " + restaurant.getDescription() + "</p>"
                "<p><b>Transports:</b> " + QStringList::fromVector(restaurant.getTransportation()).join(", ") + "</p>"
                "<p><b>Épreuves à proximité:</b> " + nearbyEventsNames.join(", ") + "</p>"        // UNIQUEMENT POUR LES RESTAURANTS
                "</div>"
                "</div>"
                "</body></html>";
    return codeHTML;
}


