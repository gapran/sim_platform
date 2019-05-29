#include "button.h"
#include "borderlayout.h"

#include <QList>
#include <QVBoxLayout>
#include <QtWidgets>
#include <iostream>

Button::Button(QWidget *parent) : QDialog(parent) {

    pushButton = new QPushButton;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(pushButton);
    setLayout(layout);
}

void Button::setName(QString name) { pushButton->setText(name); }

Button::~Button() { delete pushButton; }
