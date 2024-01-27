// clickableWidget.hpp
#pragma once

#include <QWidget>
#include <QMouseEvent>

class ClickableWidget : public QWidget
{
    Q_OBJECT

public:
    // Constructeur et destructeur
    ClickableWidget() {}
    ClickableWidget(QWidget *parent) : QWidget(parent) {}
    ~ClickableWidget() {}

    // Setter
    void setDetails(const QString &details) { this->details = details; }

    // Méthode virtuelle de QWidget redéfinie pour émettre un signal lorsqu'on clique sur le widget
    void mousePressEvent(QMouseEvent *event) override
    {
        QWidget::mousePressEvent(event);
        emit clicked(details); 
    }

signals:
    // Émet un signal indiquant qu'un clic a eu lieu sur le widget, avec les détails associés (QString)
    void clicked(const QString &details);

private:
    // Attribut
    QString details;
};