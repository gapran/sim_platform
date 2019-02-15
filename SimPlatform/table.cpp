#include "table.h"
#include "ui_table.h"

int row;
int column;
QStringList tableHeaders;
QStringList tableNamesColumn;
QStringList tableStatusColumnValues;
QStringList tableStartDatesColumn;
QStringList tableLastUpdatesColumn;
QStringList tableDescriptionsColumn;
QStringList tableActionsColumn;



Table::Table(QWidget *parent) : QDialog(parent) {

    //Creates the table, then you set the number of rows and columns.
    table = new QTableWidget;

    table->setRowCount(row);
    table->setColumnCount(column);

    table->setHorizontalHeaderLabels(tableHeaders);

    //Add Names column values
    for (int var = 0; var < tableNamesColumn.size(); ++var) {
        table->setItem(var, 0, new QTableWidgetItem(tableNamesColumn[var]));
    }

    //Add Status column values
    for (int i = 0; i < tableStatusColumnValues.size(); ++i) {
        table->setItem(i, 1, new QTableWidgetItem(tableStatusColumnValues[i]));
    }

    //Add Start Date column values
    for (int j = 0; j < tableStartDatesColumn.size(); ++j) {
        table->setItem(j, 3, new QTableWidgetItem(tableStartDatesColumn[j]));
    }

    //Add Last Update column values
    for (int k = 0; k < tableLastUpdatesColumn.size(); ++k) {
        table->setItem(k, 4, new QTableWidgetItem(tableLastUpdatesColumn[k]));
    }

    //Add Description column values
    for (int l = 0; l < tableDescriptionsColumn.size(); ++l) {
        table->setItem(l, 5, new QTableWidgetItem(tableDescriptionsColumn[l]));
    }

    //Add Action column values
    for (int n = 0; n < tableActionsColumn.size(); ++n) {
        table->setItem(n, 6, new QTableWidgetItem(tableActionsColumn[n]));
    }


    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(table);

    setLayout(layout);
}

Table::~Table() {
    delete table;
}
