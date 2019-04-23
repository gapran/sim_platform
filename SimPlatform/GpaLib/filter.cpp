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

    // QVBoxLayout *hbox = new QVBoxLayout;
    filter = new QCheckBox(value, this);
    // hbox->addWidget(checkBox);
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

void Filter::createFilterGroup() {
    QGroupBox *groupBox = new QGroupBox(tr("Header"));
    groupBox->setFlat(true);

    QCheckBox *checkBox1 = new QCheckBox(tr("&Checkbox 1"));
    QCheckBox *checkBox2 = new QCheckBox(tr("&Checkbox 2"));
    QCheckBox *checkBox3 = new QCheckBox(tr("&Checkbox 3"));

    checkBox3->setChecked(true);
    QCheckBox *tristateBox = new QCheckBox(tr("Tri-&state button"));
    tristateBox->setTristate(true);
    tristateBox->setCheckState(Qt::PartiallyChecked);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(checkBox1);
    vbox->addWidget(checkBox2);
    vbox->addWidget(checkBox3);
    vbox->addWidget(tristateBox);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    groupBox->show();
}

Filter::~Filter() { delete filter; }
