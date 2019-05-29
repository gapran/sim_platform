#include "filter.h"
#include "borderlayout.h"
#include "globals.h"

#include <QList>
#include <QVBoxLayout>
#include <QtWidgets>
#include <iostream>

Filter::Filter(QWidget *parent) : QListWidget(parent) {

    listWidget = new QListWidget;
    listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
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
    item->setSelected(false);
}

void Filter::createFilterList(QStringList valueList) {

    for (int i = 0; i < valueList.size(); i++) {

        QString value = valueList[i];
        listWidget->addItem(value);
    }

    QListWidgetItem *item = nullptr;
    for (int i = 0; i < listWidget->count(); ++i) {
        item = listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsSelectable);
        // item->setCheckState(Qt::Checked);
        // item->setSelected(true);
    }
}

void Filter::getFiltersList() {

    // QList<QListWidgetItem *> filtersList = listWidget->selectedItems();
    qDebug() << "I am in getFiltersList";
    // qDebug() << listWidget->selectedItems().at(1);
    qDebug() << listWidget->size();
    qDebug() << listWidget->selectedItems().length();
    qDebug() << listWidget->item(0)->text();

    for (int i = 0; i < listWidget->count(); ++i) {
        QListWidgetItem *item = listWidget->item(i);
        if (item->isSelected())
            qDebug() << item->text();
    }

    // Add to global filter list
    if (!global_filter_list.isEmpty()) {
        global_filter_list.clear(); // Removes the old filters
    }
    for (int i = 0; i < listWidget->count(); ++i) {
        QListWidgetItem *item = listWidget->item(i);
        if (item->isSelected())
            global_filter_list.append(item->text()); // Adds new filters
    }

    qDebug() << global_filter_list.length();
}

// QList<QListWidgetItem *> Filter::filtersSelected() {

//    return this->selectedItems();
//}

Filter::~Filter() { delete listWidget; }
