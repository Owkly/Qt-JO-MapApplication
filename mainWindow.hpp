//mainWindow.hpp
#pragma once

#include "ui_mainWindow.h"

#include <QMainWindow>
#include <QScrollArea>
#include <QLabel>
#include <QVBoxLayout>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openInfoMain_clicked();

    void on_openMapMain_clicked();

private:
    Ui::MainWindow *ui;
};



