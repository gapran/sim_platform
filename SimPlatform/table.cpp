#include "table.h"
#include "ui_table.h"

int row;
int column;
QStringList tableHeaders;
QStringList tableNamesColumn;

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

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(table);

    setLayout(layout);
}

Table::~Table() {
    delete table;
}
