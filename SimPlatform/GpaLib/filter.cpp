#include "filter.h"
#include "borderlayout.h"

#include <QVBoxLayout>
#include <QtWidgets>
#include <iostream>

Filter::Filter(QWidget *parent) : QListWidget(parent) {

    listWidget = new QListWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(listWidget);
    setLayout(layout);
}

void Filter::createFilter(QString value) { listWidget->addItem(value); }

void Filter::createFilterHeader(QString text) {
    QListWidgetItem *item = nullptr;
    listWidget->addItem(text);

    item = listWidget->item(0);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
}

void Filter::createFilterList(QStringList valueList) {

    for (int i = 0; i < valueList.size(); i++) {

        QString value = valueList[i];
        listWidget->addItem(value);
    }

    QListWidgetItem *item = nullptr;
    for (int i = 0; i < listWidget->count(); ++i) {
        item = listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }
}

Filter::~Filter() { delete listWidget; }
