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
    void setWeb();
    void setIDE();
    void setCLI();

private:
    QLabel *label;

};

#endif // LAYOUT_H
