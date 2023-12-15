// #include "mainwindow.hpp"
// #include <QApplication>

// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);
//     MainWindow window;
//     window.show();
//     return app.exec();
// }

#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.showFullScreen(); // La fenêtre principale sera affichée en plein écran.
    return app.exec();
}

