// detailedWindow.hpp
#pragma once
#include <QDialog>
#include <QTextBrowser>
#include "dataManager.hpp"

namespace Ui {
class DetailedWindow;
}

class DetailedWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DetailedWindow(QWidget *parent = nullptr);
    ~DetailedWindow();
    void setDetails(const QString &details);

private slots:
    void closeDetailedWindow();
    
private:
    Ui::DetailedWindow *ui;
};

