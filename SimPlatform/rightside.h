#ifndef RIGHTSIDE_H
#define RIGHTSIDE_H

#include <QWidget>

namespace Ui {
class RightSide;
}

class RightSide : public QWidget
{
    Q_OBJECT

public:
    explicit RightSide(QWidget *parent = nullptr);
    ~RightSide();

private:
    Ui::RightSide *ui;
};

#endif // RightSide_H
