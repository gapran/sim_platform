#include "bar.h"

#include<vector>
#include<QLabel>
#include<QTextCursor>

Bar::Bar(QWidget *parent, int min, int max) : QDialog (parent)
{
    bar = new QProgressBar;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(bar);
    setLayout(layout);

    bar->setMinimum(min);
    bar->setMaximum(max);
}

void Bar::populate(){
    bar->setValue(75);
}
