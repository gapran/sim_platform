#ifndef LAYOUT_H
#define LAYOUT_H

#include <QDialog>
#include <QLabel>

class Layout: public QDialog
{
    Q_OBJECT

public:
    explicit Layout(QWidget *parent = 0);
    void setMobile();

private:
    QLabel *label;

};

#endif // LAYOUT_H
