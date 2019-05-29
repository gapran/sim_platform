#include "table.h"
#include "borderlayout.h"
#include "globals.h"

#include <QDebug>
#include <QList>
#include <iostream>
#include <vector>

using namespace std; // Import the standard library

Table::Table(QWidget *parent) : QTableWidget(parent) {

    //Creates the table, then you set the number of rows and columns.
    table = new QTableWidget;

    BorderLayout *layout = new BorderLayout;
    layout->addWidget(table, BorderLayout::Center);

    setLayout(layout);
}

void Table::createTable(int row, int column) {

    table->setRowCount(row);
    table->setColumnCount(column);

}

void Table::updateTable(int rowNo, int columnNo, QString value) {

    int rowUpdateNo = rowNo;
    int columnUpdateNo = columnNo;
    QString valueUpdate = value;

    //Update a certain cell when the default values changed i.e., user has called the function with some values
    if (rowUpdateNo != 0 && columnUpdateNo != 0 && valueUpdate != "") {
        table->setItem(rowUpdateNo, columnUpdateNo, new QTableWidgetItem(valueUpdate));
    }
}

void Table::addTableHeaders(QStringList tableHeadersList) {

    table->setHorizontalHeaderLabels(tableHeadersList);
}

void Table::addTableNameColumns(QStringList tableNameColumn) {

    //Add Names column values
    for (int var = 0; var < tableNameColumn.size(); ++var) {
        table->setItem(var, 0, new QTableWidgetItem(tableNameColumn[var]));
    }

}

void Table::addTableStatusColumns(QStringList tableStatusColumn) {

    //Add Status column values
    for (int i = 0; i < tableStatusColumn.size(); ++i) {
        table->setItem(i, 1, new QTableWidgetItem(tableStatusColumn[i]));
    }
}

void Table::addTableStartDateColumns(QStringList tableStartDateColumn) {

    //Add Start Date column values
    for (int j = 0; j < tableStartDateColumn.size(); ++j) {
        table->setItem(j, 3, new QTableWidgetItem(tableStartDateColumn[j]));
    }
}

void Table::addTableLastUpdateColumns(QStringList tableLastUpdateColumn) {

    //Add Last Update column values
    for (int k = 0; k < tableLastUpdateColumn.size(); ++k) {
        table->setItem(k, 4, new QTableWidgetItem(tableLastUpdateColumn[k]));
    }
}

void Table::addTableDescriptionColumns(QStringList tableDescriptionColumn) {

    //Add Description column values
    for (int l = 0; l < tableDescriptionColumn.size(); ++l) {
        table->setItem(l, 5, new QTableWidgetItem(tableDescriptionColumn[l]));
    }
}

void Table::addTableActionColumns(QStringList tableActionColumn) {

    //Add Action column values
    for (int n = 0; n < tableActionColumn.size(); ++n) {
        table->setItem(n, 6, new QTableWidgetItem(tableActionColumn[n]));
    }
}

void Table::findColumn(QString columnName) {

    QStringList tableHeaders;
    for (int i = 0; i < table->model()->columnCount(); i++) {
        tableHeaders.append(table->model()->headerData(i, Qt::Horizontal).toString());
    }

    for (int a = 0; a < tableHeaders.size(); ++a) {
        if (columnName == tableHeaders[a]) {
            cout << "The column is found in the table." << "\n";
        }
    }
}

void Table::applyFilter(QString columnFilterName, QString filterName) {


    QStringList tableHeaders;
    for (int i = 0; i < table->model()->columnCount(); i++) {
        tableHeaders.append(table->model()->headerData(i, Qt::Horizontal).toString());
    }

    //Apply the filter on the table: Column name and Filter keyword
    if (filterName != "") {
        int columnFilterNo = 0;
        std::vector<int> rowsToDelete;

        for (int p = 0; p < tableHeaders.size(); ++p) {
            if (columnFilterName == tableHeaders[p]) {
                columnFilterNo = p;
            }
        }

        for (int q = 0; q < table->rowCount(); ++q) {

            QString search = table->item(q, columnFilterNo)->text();

            if (filterName != search) {
                rowsToDelete.push_back(q);
            }
        }

        for (unsigned int r = 0; r < rowsToDelete.size(); ++r) {
            int rowDeleteNo = rowsToDelete[r];
            table->removeRow(rowDeleteNo -
                             r); // Once a row deleted, table view is now 1 less to the collected row value to be deleted
        }
    }

}

//void Table::applyBackgroundColor(QString backgroundColor){

//    QString bgColor = "background-color:"+backgroundColor;
//    //Applies background color to Table if user provides a color
//    if (!bgColor.isNull()){
//    table->setStyleSheet(bgColor); }

//}

void Table::applyBorderWidthColor(QStringList borderWidthColor) {

    //Applies border width and color
    if (!borderWidthColor.isEmpty()) {
        QString style = "border: " + borderWidthColor[0] + " solid " + borderWidthColor[1];
        table->setStyleSheet(style);
    }

}

void Table::sort(bool value) {

    //When the user presses a column header then sorting happens.
    table->setSortingEnabled(value);

}

void Table::show() {

    table->show();

}

void Table::filterTable() {

    qDebug() << "I am in filter table";

    qDebug() << global_filter_list.length();
    qDebug() << table->rowCount();
    qDebug() << table->columnCount();

    for (int i = 0; i < global_filter_list.count(); i++) {
        for (int r = 0; r < table->rowCount(); r++) {
            bool found = false;
            for (int c = 0; c < table->columnCount(); c++) {
                if (c != 2) { // Skips the progress column i.e., empty
                    QTableWidgetItem *item = table->item(r, c);
                    QString filter_value = global_filter_list.at(i);
                    QString table_item = item->text();
                    qDebug() << filter_value;
                    qDebug() << table_item;
                    if (table_item == filter_value) {
                        table->showRow(r);
                        found = true;
                        break;
                    }
                }
                // table->setRowHidden(r, !found);
            }
            if (!found) {
                table->hideRow(r);
            }
        }
    }
}

Table::~Table() { delete table; }
