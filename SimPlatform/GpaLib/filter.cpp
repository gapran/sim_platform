#include "filter.h"
#include "borderlayout.h"

#include <QHBoxLayout>
#include <QtWidgets>
#include <iostream>

Filter::Filter(QWidget *parent, QString value) : QLabel(parent) {

    QGroupBox *groupBox = new QGroupBox();

    filter = new QCheckBox(value);
    // BorderLayout *layout = new BorderLayout;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(filter);
    layout->addWidget(filter);

    groupBox->setLayout(layout);
    setLayout(layout);
}

void Filter::createFilter(QString value) { filter->setText(value); }

void Filter::createFilterList(QStringList valueList) {

    QGroupBox *groupBox = new QGroupBox();
    groupBox->setFlat(true);

    QVBoxLayout *vbox = new QVBoxLayout;

    for (int i = 0; i < valueList.size(); i++) {

        QCheckBox *checkBoxListItem = new QCheckBox();
        QString value = valueList[i];
        checkBoxListItem->setText(value);
        vbox->addWidget(checkBoxListItem);
    }

    groupBox->setLayout(vbox);

    groupBox->show();
}

Filter::~Filter() { delete filter; }
