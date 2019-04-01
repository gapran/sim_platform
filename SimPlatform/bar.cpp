#include "bar.h"
#include<iostream>
#include<vector>

#include<QProgressBar>


Bar::Bar(QWidget *parent) : QDialog (parent)
{
    bar = new QProgressBar;

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(bar);

    setLayout(layout);
}

Bar::~Bar(){
    delete bar;
}

void Bar::setValue(int min, int max, int current)
{

    bar->setMinimum(min);
    bar->setMaximum(max);
    bar->setValue(current);

}

void Bar::setText(QString text)
{
    bar->setToolTip(text);
}

void Bar::updatable(bool value)
{
    if(value == true){
    bar->updatesEnabled(); }

}

void Bar::populate(){
    bar->setMinimum(0);
    bar->setMaximum(100);
    bar->setValue(75);
}

void Bar::onChange(int value)
{
    bar->setValue(value);
}
