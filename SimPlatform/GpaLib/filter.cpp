#include "filter.h"
#include "borderlayout.h"

#include <QHBoxLayout>
#include <QtWidgets>
#include <iostream>

Filter::Filter(QWidget *parent) : QLabel(parent) {

    filter = new QCheckBox;
    BorderLayout *layout = new BorderLayout;
    layout->addWidget(filter, BorderLayout::Center);
    setLayout(layout);
}

void Filter::createFilter(QString value) {

    filter = new QCheckBox(value, this);
}

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
