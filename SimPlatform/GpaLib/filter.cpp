#include "filter.h"
#include "borderlayout.h"

#include <QVBoxLayout>
#include <QtWidgets>
#include <iostream>

Filter::Filter(QWidget *parent) : QListWidget(parent) {

    filterList = new QListWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(filterList);
    setLayout(layout);
}

void Filter::createFilter(QString value) { filterList->addItem(value); }

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

Filter::~Filter() { delete filterList; }
