// #include "mainwindow.hpp"

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);
// }

// MainWindow::~MainWindow()
// {
//     delete ui;
// }


#include "mainWindow.hpp"
#include "secondWindow.hpp"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QPushButton *buttonToSecond = new QPushButton("Open Second Window", this);
    connect(buttonToSecond, &QPushButton::clicked, this, &MainWindow::openSecondWindow);
    setCentralWidget(buttonToSecond);
}

void MainWindow::openSecondWindow() {
    auto *secondWindow = new SecondWindow();
    secondWindow->show();
}





