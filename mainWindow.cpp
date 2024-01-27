// mainWindow.cpp
#include "mainWindow.hpp"

// Constructeur
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), dataManager("lieux.json")
{
    // Configuration de base : configuration de l'interface utilisateur et affichage en plein écran
    this->setWindowTitle("JO 2024");
    this->showFullScreen();
    ui->setupUi(this);

    // Configuration de la scrollAreaLayout
    scrollAreaManager = new ScrollAreaManager(ui->scrollArea, ui->scrollAreaWidgetContents, &dataManager);

    // Connexion des signaux pour les boutons de navigation, et de la barre de recherche
    setupConnections();
}

// Destructeur
MainWindow::~MainWindow()
{
    delete ui;
}


// Méthode pour connecter les signaux et les slots c'est à dire les boutons et les méthodes
void MainWindow::setupConnections()
{   
    // Connexion des signaux pour les boutons de navigation et de fermeture
    connect(ui->openInfoMainButton, &QPushButton::clicked, this, &MainWindow::openInfoMain);
    connect(ui->openMapMainButton, &QPushButton::clicked, this, &MainWindow::openMapMain);
    connect(ui->openHomeMainButton, &QPushButton::clicked, this, &MainWindow::openHomeMain);
    connect(ui->quitMainButton, &QPushButton::clicked, this, &MainWindow::close);

    // Connexion des signaux pour la barre de recherche
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::updateSearchResult);
    connect(ui->inputArea, &QLineEdit::returnPressed, this, &MainWindow::updateSearchResult);
    connect(ui->filterComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::updateSearchResult);

    // Connexion du signal pour ouvrir la fenêtre détaillée
    connect(scrollAreaManager, &ScrollAreaManager::detailedDialogRequested, this, &MainWindow::openDetailedDialog);
}

// Méthode pour ouvrir la page d'accueil (ouvre le 1er stackedWidget)
void MainWindow::openHomeMain()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// Méthode pour fermer la fenêtre
void MainWindow::closeMain()
{
    this->close();
}

// Méthode pour ouvrir la page d'information (ouvre le 2ème stackedWidget et affiche les épreuves et restaurants)
void MainWindow::openInfoMain()
{
    ui->stackedWidget->setCurrentIndex(1);
    scrollAreaManager->setupItemsScrollArea(dataManager.getListEvents(), dataManager.getListRestaurants());
}

// Méthode pour ouvrir la page de la carte (ouvre le 3ème stackedWidget et charge les données depuis le fichier QML)
void MainWindow::openMapMain()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->mapViewWidget->setSource(QUrl(QStringLiteral("qrc:/Map.qml")));
    ui->mapViewWidget->show();
}

// Méthode pour rechercher un item (épreuve ou restaurant) dans la scrollAreaLayout
void MainWindow::updateSearchResult()
{
    // Récupération du texte de recherche et du filtre
    QString searchText = ui->inputArea->text().trimmed();
    QString selectedFilter = ui->filterComboBox->currentText();

    // Mis à jour de la scrollAreaLayout
    QVector<Event> filteredEvents = dataManager.searchEvents(searchText, selectedFilter);
    QVector<Restaurant> filteredRestaurants = dataManager.searchRestaurants(searchText, selectedFilter);
    scrollAreaManager->setupItemsScrollArea(filteredEvents, filteredRestaurants);
}

// Méthode pour afficher dans un dialogue les détails de l'item sélectionné
void MainWindow::openDetailedDialog(const QString &codeHTML)
{
    DetailedDialog detailedDialog(this);
    detailedDialog.setModal(true); // Bloque l'interaction avec la fenêtre principale tant que la fenêtre détaillée est ouverte
    detailedDialog.setDialogHTML(codeHTML);
    detailedDialog.exec();
}