#pragma once

#include <QWidget>
#include <QPushButton>

class SecondWindow : public QWidget {
    Q_OBJECT

public:
    SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow() = default;

private:
    QPushButton *buttonBack;
};
