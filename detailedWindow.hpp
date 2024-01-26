// detailedWindow.hpp
#pragma once
#include <QDialog>
#include <QTextBrowser>


namespace Ui {
class DetailedWindow;
}

class DetailedWindow : public QDialog
{
    Q_OBJECT

public:
    // Constructeur et destructeur
    explicit DetailedWindow(QWidget *parent = nullptr);
    ~DetailedWindow();

    // Méthode
    void setDetails(const QString &details);

private slots:
    // Méthode de slot
    void closeDetailedWindow();
    
private:
    // Attribut
    Ui::DetailedWindow *ui;
};

