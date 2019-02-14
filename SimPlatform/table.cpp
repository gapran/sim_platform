#include "table.h"
#include "ui_table.h"

int row;
int column;

Table::Table(QWidget *parent) : QDialog(parent) {

    //Creates the table, then you set the number of rows and columns.
    table = new QTableWidget;

    table->setRowCount(row);
    table->setColumnCount(column);


    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(table);

    setLayout(layout);
}

Table::~Table() {
    delete table;
}
