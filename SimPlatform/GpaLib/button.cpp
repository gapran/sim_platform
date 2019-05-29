#include "button.h"
#include "borderlayout.h"

#include <QList>
#include <QVBoxLayout>
#include <QtWidgets>
#include <iostream>

Button::Button(QWidget *parent) : QPushButton(parent) {

    name = new QLabel;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(name, Qt::AlignCenter);
    setLayout(layout);
}

void Button::setName(QString name_value) {
    name->setText(name_value);
    name->setAlignment(Qt::AlignCenter);
}

Button::~Button() { delete name; }
