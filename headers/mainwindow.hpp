// #ifndef MAINWINDOW_HPP
// #define MAINWINDOW_HPP

// #include <QMainWindow>

// class MainWindow : public QMainWindow {
//     Q_OBJECT

// public:
//     explicit MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();
// };

// #endif // MAINWINDOW_HPP














// #include <QMainWindow>
// #include <QLabel>

// class MainWindow : public QMainWindow {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);

// private:
//     QLabel *imageLabel;
// };















// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>
// #include <QLabel>
// #include <QPushButton>

// class MainWindow : public QMainWindow {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);

// private slots:
//     void showFirstImage();
//     void showSecondImage();

// private:
//     QLabel *imageLabel;
//     QPushButton *buttonImage1;
//     QPushButton *buttonImage2;
// };

// #endif // MAINWINDOW_H













#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void showImage();
    void showEiffel();

private:
    QLabel *imageLabel;
    QPushButton *buttonImage;
    QPushButton *buttonEiffel;
};

#endif // MAINWINDOW_H

