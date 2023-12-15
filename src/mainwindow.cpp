// #include "mainwindow.hpp"

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent) {
//     // Constructeur - vous pouvez ajouter votre code d'initialisation ici
// }

// MainWindow::~MainWindow() {
//     // Destructeur - le code de nettoyage ici
// }











// #include "mainwindow.hpp"
// #include <QPixmap>
// #include <QDir>

// MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
// {
//     imageLabel = new QLabel(this);
//     QString imagePath = QDir::currentPath() + "/images/image.png";
//     QString imagePath = QDir::currentPath() + "/images/france-eiffel-tower-paris.jpg";
//     QPixmap image(imagePath);
//     imageLabel->setPixmap(image);
//     imageLabel->setScaledContents(true); // L'image s'ajustera pour remplir tout le QLabel.
//     this->setCentralWidget(imageLabel);  // Définissez imageLabel comme le widget central de MainWindow.
// }






















// #include "mainwindow.hpp"
// #include <QPixmap>
// #include <QDir>
// #include <QVBoxLayout>

// MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
//     // Widgets
//     imageLabel = new QLabel(this);
//     buttonImage1 = new QPushButton("Show Image", this);
//     buttonImage2 = new QPushButton("Show Eiffel Tower", this);

//     // Layout
//     QVBoxLayout *layout = new QVBoxLayout();
//     layout->addWidget(buttonImage1);
//     layout->addWidget(buttonImage2);
//     layout->addWidget(imageLabel);

//     // Central Widget
//     QWidget *centralWidget = new QWidget(this);
//     centralWidget->setLayout(layout);
//     setCentralWidget(centralWidget);

//     // Connections
//     connect(buttonImage1, &QPushButton::clicked, this, &MainWindow::showFirstImage);
//     connect(buttonImage2, &QPushButton::clicked, this, &MainWindow::showSecondImage);
// }

// void MainWindow::showFirstImage() {
//     QPixmap image(QDir::currentPath() + "/images/image.png");
//     imageLabel->setPixmap(image);
// }

// void MainWindow::showSecondImage() {
//     QPixmap image(QDir::currentPath() + "/images/france-eiffel-tower-paris.jpg");
//     imageLabel->setPixmap(image);
// }
















#include "../headers/mainwindow.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Widgets
    imageLabel = new QLabel(this);
    buttonImage = new QPushButton("Image", this);
    buttonEiffel = new QPushButton("Eiffel", this);

    // Setup the layout for buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(buttonImage);
    buttonLayout->addWidget(buttonEiffel);

    // Setup the main layout
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(imageLabel);

    // Central Widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Connections
    connect(buttonImage, &QPushButton::clicked, this, &MainWindow::showImage);
    connect(buttonEiffel, &QPushButton::clicked, this, &MainWindow::showEiffel);

    // Initialize with first image
    showImage();
}

void MainWindow::showImage() {
    QPixmap image("/home/weikai/Documents/Projet-Jeux-Olympiques/images/image.png"); // Assurez-vous que le chemin de l'image est correct.
    imageLabel->setPixmap(image);
}

void MainWindow::showEiffel() {
    QPixmap eiffel("/home/weikai/Documents/Projet-Jeux-Olympiques/images/france-eiffel-tower-paris.jpg"); // Assurez-vous que le chemin de l'image est correct.
    imageLabel->setPixmap(eiffel);
}

