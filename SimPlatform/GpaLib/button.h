#ifndef BUTTON_H
#define BUTTON_H

#include <QDialog>
#include <QPushButton>

class Button : public QDialog {
    Q_OBJECT

public:
    Button(QWidget *parent = nullptr);
    ~Button();

    void setName(QString name);

private:
    QPushButton *pushButton;
};

#endif // BUTTON_H
