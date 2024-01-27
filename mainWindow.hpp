// mainWindow.hpp
#pragma once
#include <QMainWindow>
#include <QScrollArea>
#include <QLabel>
#include <QVBoxLayout>
#include <QDialog>

#include "ui_mainWindow.h"
#include "event.hpp"
#include "restaurant.hpp"
#include "dataManager.hpp"
#include "detailedDialog.hpp"
#include "scrollAreaManager.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructeur et destructeur
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Méthodes de slot pour interagir avec l'interface utilisateur
    void openHomeMain();
    void openInfoMain();
    void openMapMain();
    void closeMain();
    void updateSearchResult();
    void openDetailedDialog(const QString &codeHTML);

private:
    // Méthode
    void setupConnections();

    // Attributs
    Ui::MainWindow *ui;
    DataManager dataManager;
    ScrollAreaManager *scrollAreaManager;
};