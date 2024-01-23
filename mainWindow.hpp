// #pragma once

// #include "ui_mainWindow.h"

// #include <QMainWindow>
// #include <QScrollArea>
// #include <QLabel>
// #include <QVBoxLayout>
// #include <QDialog>

// QT_BEGIN_NAMESPACE
// namespace Ui { class MainWindow; }
// QT_END_NAMESPACE

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private:
//     Ui::MainWindow *ui;
// };

#pragma once

#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void openSecondWindow();
};




