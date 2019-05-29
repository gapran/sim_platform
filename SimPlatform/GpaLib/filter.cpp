#include "filter.h"
#include "borderlayout.h"

#include <QList>
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

void Filter::createFilterHeader(QString text, int index) {
    QListWidgetItem *item = nullptr;
    listWidget->addItem(text);

    item = listWidget->item(index);
    item->setFlags(item->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEnabled);
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

void Filter::getFiltersList() {

    QList<QListWidgetItem *> filtersList = listWidget->selectedItems();
    qDebug() << "I am in getFiltersList";
}

// QList<QListWidgetItem *> Filter::filtersSelected() {

//    return this->selectedItems();
//}

Filter::~Filter() { delete listWidget; }
