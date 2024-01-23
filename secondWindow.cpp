#include "secondWindow.hpp"

SecondWindow::SecondWindow(QWidget *parent) : QWidget(parent) {
    buttonBack = new QPushButton("Back to Main Window", this);
    connect(buttonBack, &QPushButton::clicked, this, [this]() {
        this->close(); // Ferme la fenêtre actuelle
    });
    // Configurez ici le reste du contenu de SecondWindow
    setWindowTitle("Second Window");
    resize(300, 200); // Taille de la fenêtre
}
