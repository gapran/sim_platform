#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>

namespace Ui {
class DashBoard;
}

class DashBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashBoard(QWidget *parent = nullptr);
    ~DashBoard();

private slots:
    void on_actionInfo_triggered();

private:
    Ui::DashBoard *ui;
};

#endif // DASHBOARD_H
