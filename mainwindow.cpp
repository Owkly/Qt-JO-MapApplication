#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// void MainWindow::setEpreuve(const Epreuve &epreuve) {
//     ui->Nom->setText(epreuve.getNom());
//     ui->Adresse->setText(epreuve.getAdresse());
//     ui->Horaire->setText(epreuve.getHoraire().toString("yyyy-MM-dd HH:mm:ss"));

//     if (!epreuve.getImage().isNull()) {
//         ui->Image->setPixmap(epreuve.getImage().scaled(ui->Image->size()));
//     }
//     ui->Image->setScaledContents(true);
// }

// void MainWindow::afficherEpreuves(const QList<Epreuve> &epreuves) {
//     QScrollArea *scrollArea = new QScrollArea(this); // Assurez-vous que ce widget est bien placé et redimensionné
//     QWidget *container = new QWidget();
//     QVBoxLayout *layout = new QVBoxLayout(container);

//     for (const Epreuve &epreuve : epreuves) {
//         QLabel *labelNom = new QLabel(epreuve.getNom());
//         QLabel *labelHoraire = new QLabel(epreuve.getHoraire().toString());
//         QLabel *labelImage = new QLabel();
//         labelImage->setPixmap(epreuve.getImage().scaled(ui->Image->size()));

//         // Ajoutez ces labels au layout
//         layout->addWidget(labelNom);
//         layout->addWidget(labelHoraire);
//         layout->addWidget(labelImage);
//     }

//     container->setLayout(layout);
//     scrollArea->setWidget(container);
// }



// // Dans mainwindow.cpp
// void MainWindow::afficherDetailsEpreuve(const Epreuve &epreuve)
// {
//     // Créez une nouvelle fenêtre pour afficher les détails de l'épreuve
//     QDialog *detailsDialog = new QDialog(this);
//     QVBoxLayout *layout = new QVBoxLayout(detailsDialog);

//     // Ajoutez des étiquettes pour afficher les informations de l'épreuve
//     QLabel *nomLabel = new QLabel("Nom: " + epreuve.getNom());
//     QLabel *adresseLabel = new QLabel("Adresse: " + epreuve.getAdresse());
//     QLabel *descriptionLabel = new QLabel("Description: " + epreuve.getDescription());
//     // Ajoutez d'autres étiquettes pour les autres informations...

//     // Ajoutez les étiquettes au layout
//     layout->addWidget(nomLabel);
//     layout->addWidget(adresseLabel);
//     layout->addWidget(descriptionLabel);
//     // Ajoutez les autres étiquettes...

//     // Affichez la fenêtre
//     detailsDialog->exec();
// }
