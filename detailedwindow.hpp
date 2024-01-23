#ifndef DETAILEDWINDOW_HPP
#define DETAILEDWINDOW_HPP

#include <QDialog>
#include "ui_MyNewWindow.h"

class detailedwindow : public QDialog {
    Q_OBJECT

public:
    detailedwindow(QWidget *parent = nullptr) : QDialog(parent) {
        ui.setupUi(this);
        // Autres initialisations
    }

private:
    Ui::detailedwindow ui;
};

#endif // DETAILSWINDOW_HPP

