//clickableWidget.cpp
#include "clickableWidget.hpp"

ClickableWidget::ClickableWidget(QWidget *parent) : QWidget(parent) {}

void ClickableWidget::setDetails(const QString &details)
{
    this->details = details;
}

void ClickableWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    emit clicked(details); // Émet le signal avec les détails
}