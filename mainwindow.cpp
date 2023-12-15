// #include "mainwindow.hpp"

// MainWindow::MainWindow(QWidget *parent) 
//     : QMainWindow(parent) {
//     // Constructeur - vous pouvez ajouter votre code d'initialisation ici
// }

// MainWindow::~MainWindow() {
//     // Destructeur - le code de nettoyage ici
// }

#include "mainwindow.hpp"
#include <QPixmap>
 
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    imageLabel = new QLabel(this);
    QPixmap image(":/home/weikai/Documents/Projet-Jeux-Olympiques/images/image.png"); // Assurez-vous que le chemin de l'image est correct.
    imageLabel->setPixmap(image);
    imageLabel->setScaledContents(true); // L'image s'ajustera pour remplir tout le QLabel.
    this->setCentralWidget(imageLabel); // Définissez imageLabel comme le widget central de MainWindow.
}
