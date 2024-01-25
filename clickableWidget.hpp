//clickableWidget.hpp
#pragma once

#include <QWidget>
#include <QMouseEvent>

class ClickableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClickableWidget(QWidget *parent = nullptr);
    void setDetails(const QString &details); // Pour stocker les détails de chaque élément

signals:
    void clicked(const QString &details); // Signal émis lors du clic

protected:
    void mousePressEvent(QMouseEvent *event) override; // Réagit au clic

private:
    QString details; // Stocke les détails de l'élément
};