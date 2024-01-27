// scrollAreaManager.cpp
#include "scrollAreaManager.hpp"

// Constructeur
ScrollAreaManager::ScrollAreaManager(QScrollArea *scrollArea, QWidget *contentWidget, DataManager *dataManager)
    : QObject(), scrollArea(scrollArea), dataManager(dataManager)
{
    scrollAreaLayout = new QVBoxLayout(contentWidget);
    scrollArea->setStyleSheet("QWidget { background-color: #fffbeb; }"); // Couleur jaune clair
}

// Destructeur
ScrollAreaManager::~ScrollAreaManager()
{
    delete scrollAreaLayout;
}

// Méthode pour supprimer tous les widgets du scrollArea
void ScrollAreaManager::clearScrollArea()
{
    QLayoutItem *item;
    while ((item = scrollAreaLayout->takeAt(0)) != nullptr)
    {
        delete item->widget();
        delete item;
    }
}

// Méthode mettre à jour le scrollArea avec les épreuves et restaurants passés en paramètre
void ScrollAreaManager::setupItemsScrollArea(const QVector<Event> &events, const QVector<Restaurant> &restaurants)
{
    clearScrollArea();
    for (const Event &event : events)
    {
        addEventToScrollArea(event);
    }
    for (const Restaurant &restaurant : restaurants)
    {
        addRestaurantToScrollArea(restaurant);
    }
    addVerticalSpacer(scrollAreaLayout);
}

// Méthode pour ajouter un événement au scrollArea
void ScrollAreaManager::addEventToScrollArea(const Event &event)
{
    // image
    QString imagePath = event.getPathForItem();
    QLabel *imageLabel = createImageLabel(imagePath);

    // text
    QWidget *nameAdressTimeWidget = new QWidget();
    QVBoxLayout *nameAdressTimeLayout = new QVBoxLayout(nameAdressTimeWidget);
    addEventTextInfo(nameAdressTimeLayout, event);

    // widget cliquable : image + text
    ClickableWidget *eventWidget = createMainWidget();
    QHBoxLayout *mainLayout = new QHBoxLayout(eventWidget);
    mainLayout->addWidget(imageLabel);
    mainLayout->addWidget(nameAdressTimeWidget);

    // connexion du signal 
    QVector<int> nearbyRestaurantsIds = event.getNearbyRestaurants();
    QString details = DetailedDialog::generateDetailsHTML(event, dataManager->getNearbyRestaurantsNames(nearbyRestaurantsIds));
    eventWidget->setDetails(details);
    connect(eventWidget, &ClickableWidget::clicked, [this, details]()
            { emit detailedDialogRequested(details); });

    // ajout au scrollArea
    scrollAreaLayout->addWidget(eventWidget);
}

// Méthode pour ajouter un restaurant au scrollArea
void ScrollAreaManager::addRestaurantToScrollArea(const Restaurant &restaurant)
{
    // image
    QString imagePath = restaurant.getPathForItem();
    QLabel *imageLabel = createImageLabel(imagePath);

    // text
    QWidget *nameAdressTimeWidget = new QWidget();
    QVBoxLayout *nameAdressTimeLayout = new QVBoxLayout(nameAdressTimeWidget);
    addRestaurantTextInfo(nameAdressTimeLayout, restaurant);

    // widget cliquable : image + text
    ClickableWidget *restaurantWidget = createMainWidget();
    QHBoxLayout *mainLayout = new QHBoxLayout(restaurantWidget);
    mainLayout->addWidget(imageLabel);
    mainLayout->addWidget(nameAdressTimeWidget);

    // connexion du signal
    QVector<int> nearbyEventsIds = restaurant.getNearbyEvents();
    QString details = DetailedDialog::generateDetailsHTML(restaurant, dataManager->getNearbyEventsNames(nearbyEventsIds));
    restaurantWidget->setDetails(details);
    connect(restaurantWidget, &ClickableWidget::clicked, [this, details]()
            { emit detailedDialogRequested(details); });

    // ajout au scrollArea
    scrollAreaLayout->addWidget(restaurantWidget);
}

// Méthode pour créer un widget cliquable avec un style d'affichage qu'on a défini
ClickableWidget *ScrollAreaManager::createMainWidget()
{
    ClickableWidget *widget = new ClickableWidget();
    widget->setStyleSheet("background-color: #DCB253; " // Couleur jaune foncé
                          "border: 3px solid #000000; " // Bordure noire
                          "border-radius: 30px; ");
    return widget;
}

// Méthode pour ajouter les infos textuelles d'une épreuve dans un layout (affichage vertical)
void ScrollAreaManager::addEventTextInfo(QVBoxLayout *layout, const Event &event)
{
    addVerticalSpacer(layout);
    layout->addWidget(createTextLabel(event.getName()));
    layout->addWidget(createTextLabel(event.getAddress()));
    layout->addWidget(createTextLabel(event.getStartTime().toString("dd/MM/yyyy - hh:mm:ss")));
    addVerticalSpacer(layout);
}

// Méthode pour ajouter les infos textuelles d'un restaurant dans un layout (affichage vertical)
void ScrollAreaManager::addRestaurantTextInfo(QVBoxLayout *layout, const Restaurant &restaurant)
{
    addVerticalSpacer(layout);
    layout->addWidget(createTextLabel(restaurant.getName()));
    layout->addWidget(createTextLabel(restaurant.getAddress()));
    layout->addWidget(createTextLabel(restaurant.getOpeningHours()));
    addVerticalSpacer(layout);
}

// Méthode pour la mise en forme des infos textuelles
QLabel *ScrollAreaManager::createTextLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    label->setStyleSheet("background-color: #D7C379; "
                         "border: 1px solid #CCCCCC; "
                         "border-radius: 10px; "
                         "font-size: 20px; "
                         "font-weight: bold; "
                         "color: #000000; "
                         "margin: 5px; "
                         "text-align: center; "
                         "text-transform: capitalize; "
                         "letter-spacing: 2px; "
                         "word-spacing: 5px; "
                         "line-height: 2; ");
    return label;
}

// Méthode pour la mise en forme des images
QLabel *ScrollAreaManager::createImageLabel(const QString &imagePath)
{
    QLabel *imageLabel = new QLabel();
    imageLabel->setPixmap(QPixmap(imagePath).scaled(150, 150));

    return imageLabel;
}

// Méthode pour ajouter un espaceur vertical dans un layout
void ScrollAreaManager::addVerticalSpacer(QVBoxLayout *layout)
{
    layout->addStretch(1);
}