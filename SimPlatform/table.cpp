#include "table.h"
#include "ui_table.h"

#include<iostream>
#include<vector>

using namespace std; //Import the standard library

int row;
int column;
int rowUpdateNo;
int columnUpdateNo;
QString columnsName;
QString valueUpdate;
QString filtersName;
QStringList tableHeaders;
QString columnFiltersName;
QStringList tableNamesColumn;
QStringList tableActionsColumn;
QStringList tableStartDatesColumn;
QStringList tableLastUpdatesColumn;
QStringList tableDescriptionsColumn;
QStringList tableStatusColumnValues;

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

    //Update a certain cell when the default values changed i.e., user has called the function with some values
    if (rowUpdateNo != 0 && columnUpdateNo != 0 && valueUpdate != "") {
        table->setItem(rowUpdateNo, columnUpdateNo, new QTableWidgetItem(valueUpdate));
    }

    //Apply the filter on the table: Column name and Filter keyword
    if (filtersName != "") {
        int columnFilterNo;
        int rowDeleteNo;
        std::vector<int> rowsToDelete;

        //   int rowCount = table->rowCount();
        for (int p = 0; p < tableHeaders.size(); ++p) {
            if (columnFiltersName == tableHeaders[p]) {
                columnFilterNo = p;
            }
        }

        for (int q = 0; q < row; ++q) {

            QString search = table->item(q, columnFilterNo)->text();

            if (filtersName != search) {
                // table->removeRow(q);
                rowsToDelete.push_back(q);
            }
        }

        for (int r = 0; r < rowsToDelete.size(); ++r) {
            rowDeleteNo = rowsToDelete[r];
            table->removeRow(rowDeleteNo -
                             r); // Once a row deleted, table view is now 1 less to the collected row value to be deleted
        }
    }


    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(table);

    setLayout(layout);

}

Table::~Table() {
    delete table;
}
