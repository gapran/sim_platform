#ifndef BAR_H
#define BAR_H

#include <QDialog>
#include<QProgressBar>
#include <QHBoxLayout>

class Bar: public QDialog
{
     Q_OBJECT

public:
    explicit Bar(QWidget *parent = 0);
     ~Bar();

    void setValue(int min, int max, int current);
    void setText(QString text);
    void updatable(bool value);
    void populate();
    void onChange(int value);


private:
    QProgressBar *bar;
};

#endif // BAR_H
