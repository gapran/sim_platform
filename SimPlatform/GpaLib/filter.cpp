#include "filter.h"
#include "borderlayout.h"
#include "globals.h"

#include <QVBoxLayout>
#include <QtWidgets>

Filter::Filter(QWidget *parent) : QListWidget(parent) {

    listWidget = new QListWidget;
    listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(listWidget);
    setLayout(layout);
}

void Filter::createFilter(QString value) { listWidget->addItem(value); }

void Filter::createFilterHeader(QString text, int index) {
    QListWidgetItem *item = listWidget->item(index);
    listWidget->addItem(text);
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
    }
}

void Filter::getFiltersList() {

    // Add to global filter list
    if (!global_filter_list.isEmpty()) {
        global_filter_list.clear(); // Removes the old filters
    }
    for (int i = 0; i < listWidget->count(); ++i) {
        QListWidgetItem *item = listWidget->item(i);
        if (item->isSelected())
            global_filter_list.append(item->text()); // Adds new filters
    }
}

Filter::~Filter() { delete listWidget; }
