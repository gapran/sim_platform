#include "bar.h"
#include<iostream>
#include<vector>

#include<QProgressBar>

using namespace std;

BarElement::BarElement(QWidget *parent) : QDialog (parent)
{
    bar = new QProgressBar;
}

void BarElement::setValue(int min, int max, int current)
{

    bar->setMinimum(min);
    bar->setMaximum(max);
    bar->setValue(current);

}
