#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H

#include <QWidget>

namespace Ui {
class rightwidget;
}

class rightwidget : public QWidget
{
    Q_OBJECT

public:
    explicit rightwidget(QWidget *parent = nullptr);
    ~rightwidget();

private:
    Ui::rightwidget *ui;
};

#endif // RIGHTWIDGET_H
