#ifndef LEFTWIDGET_H
#define LEFTWIDGET_H

#include <QWidget>

namespace Ui {
class leftwidget;
}

class leftwidget : public QWidget
{
    Q_OBJECT

public:
    explicit leftwidget(QWidget *parent = nullptr);
    ~leftwidget();

private:
    Ui::leftwidget *ui;
};

#endif // LEFTWIDGET_H
