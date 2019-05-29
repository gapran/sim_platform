#ifndef BUTTON_H
#define BUTTON_H

#include <QLabel>
#include <QPushButton>
#include <iostream>

using namespace std;
class Qlabel;

class Button : public QPushButton {
    Q_OBJECT

public:
    Button(QWidget *parent = nullptr);
    ~Button();

    void setName(QString name);

private:
    QLabel *name;

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *e) {
        emit clicked();
        cout << "Filter Button Clicked - " << e << endl;
    }
};

#endif // BUTTON_H
