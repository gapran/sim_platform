#include "filter.h"
#include "borderlayout.h"

#include <QtWidgets>
#include <iostream>

Filter::Filter(QWidget *parent) : QDialog(parent) {

    filter = new Filter;
    BorderLayout *layout = new BorderLayout;
    layout->addWidget(filter, BorderLayout::Center);
    setLayout(layout);
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
}

Filter::~Filter() { delete filter; }
