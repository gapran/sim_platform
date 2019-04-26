#include "bar.h"

#include <QLabel>
#include <QTextCursor>
#include <vector>

Bar::Bar(QWidget *parent, int min, int max) : QDialog(parent) {
    bar = new QProgressBar;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(bar);
    setLayout(layout);

    bar->setMinimum(min);
    bar->setMaximum(max);

    QString minValue = QString::number(min);
    QString maxValue = QString::number(max);

    QString hint = "Min: " + minValue + "   Max: " + maxValue;
    bar->setToolTip(hint);
}

void Bar::populate() { bar->setValue(75); }
