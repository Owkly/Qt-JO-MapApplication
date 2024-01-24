#ifndef DETAILEDWINDOW_HPP
#define DETAILEDWINDOW_HPP

#include <QDialog>

namespace Ui {
class DetailedWindow;
}

class DetailedWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DetailedWindow(QWidget *parent = nullptr);
    ~DetailedWindow();

private:
    Ui::DetailedWindow *ui;
};

#endif // DETAILEDWINDOW_HPP
