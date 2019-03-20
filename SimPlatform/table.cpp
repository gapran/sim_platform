#include "table.h"

#include<iostream>
#include<vector>

using namespace std; //Import the standard library


Table::Table(QWidget *parent) : QDialog(parent) {

    //Creates the table, then you set the number of rows and columns.
    table = new QTableWidget;

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(table);

    setLayout(layout);

}

void Table::createTable(int row, int column){

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

    QStringList tableHeaders;
    for (int var = 0; var < tableHeadersList.size(); ++var) {
        tableHeaders.append(tableHeadersList[var]);
    }

     table->setHorizontalHeaderLabels(tableHeaders);
}

void Table::addTableNameColumns(QStringList tableNameColumn) {
    for (int var = 0; var < tableNameColumn.size(); ++var) {
        tableNameColumn.append(tableNameColumn[var]);
    }

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
    for (int l = 0; l < tableStartDateColumn.size(); ++l) {
        tableStartDateColumn.append(tableStartDateColumn[l]);
    }

    //Add Start Date column values
    for (int j = 0; j < tableStartDateColumn.size(); ++j) {
        table->setItem(j, 3, new QTableWidgetItem(tableStartDateColumn[j]));
    }
}

void Table::addTableLastUpdateColumns(QStringList tableLastUpdateColumn) {
    for (int m = 0; m < tableLastUpdateColumn.size(); ++m) {
        tableLastUpdateColumn.append(tableLastUpdateColumn[m]);
    }


    //Add Last Update column values
    for (int k = 0; k < tableLastUpdateColumn.size(); ++k) {
        table->setItem(k, 4, new QTableWidgetItem(tableLastUpdateColumn[k]));
    }
}

void Table::addTableDescriptionColumns(QStringList tableDescriptionColumn) {
    for (int k = 0; k < tableDescriptionColumn.size(); ++k) {
        tableDescriptionColumn.append(tableDescriptionColumn[k]);
    }

    //Add Description column values
    for (int l = 0; l < tableDescriptionColumn.size(); ++l) {
        table->setItem(l, 5, new QTableWidgetItem(tableDescriptionColumn[l]));
    }
}

void Table::addTableActionColumns(QStringList tableActionColumn) {
    for (int n = 0; n < tableActionColumn.size(); ++n) {
        tableActionColumn.append(tableActionColumn[n]);
    }

    //Add Action column values
    for (int n = 0; n < tableActionColumn.size(); ++n) {
        table->setItem(n, 6, new QTableWidgetItem(tableActionColumn[n]));
    }
}

void Table::findColumn(QString columnName) {
    for (int a = 0; a < tableHeaders.size(); ++a) {
        if (columnName == tableHeaders[a]) {
            cout << "The column is found in the table." << "\n";
        }
    }
}

void Table::applyFilter(QString columnFilterName, QString filterName) {


    //Apply the filter on the table: Column name and Filter keyword
    if (filterName != "") {
        int columnFilterNo;
        int rowDeleteNo;
        std::vector<int> rowsToDelete;

        //   int rowCount = table->rowCount();
        for (int p = 0; p < tableHeaders.size(); ++p) {
            if (columnFilterName == tableHeaders[p]) {
                columnFilterNo = p;
            }
        }

        for (int q = 0; q < row; ++q) {

            QString search = table->item(q, columnFilterNo)->text();

            if (filterName != search) {
                // table->removeRow(q);
                rowsToDelete.push_back(q);
            }
        }

        for (unsigned int r = 0; r < rowsToDelete.size(); ++r) {
            rowDeleteNo = rowsToDelete[r];
            table->removeRow(rowDeleteNo -
                             r); // Once a row deleted, table view is now 1 less to the collected row value to be deleted
        }
    }

}

void Table::applyBackgroundColor(QString backgroundColor){

    QString bgColor = "background-color:"+backgroundColor;
    //Applies background color to Table if user provides a color
    if (!bgColor.isNull()){
    table->setStyleSheet(bgColor); }

}

void Table::applyBorderWidthColor( QStringList borderWidthColor){

    //Applies border width and color
    if (!borderWidthColor.isEmpty()){
    QString style = "border: " +borderWidthColor[0]+ " solid " +borderWidthColor[1];
    table->setStyleSheet(style); }

}

void Table::setSorting(bool value){

        //When the user presses a column header then sorting happens.
        table->setSortingEnabled(value);

}


Table::~Table() {
    delete table;
}
