#ifndef BAR_H
#define BAR_H

#include<QDialog>
#include<QProgressBar>
#include <QHBoxLayout>

class BarElement: public QDialog
{
public:
    explicit BarElement(QWidget *parent = 0);

    void setValue(int min, int max, int current);


private:
    QProgressBar *bar;
};

#endif // BAR_H
