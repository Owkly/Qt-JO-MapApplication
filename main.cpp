#include <QApplication>
#include "mainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowIcon(QIcon(":/images/icon.png"));
    mainWindow.show();

    return app.exec();
}
