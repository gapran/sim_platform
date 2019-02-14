#include "table.h"
#include "ui_table.h"

int row;
int column;
QStringList tableHeader;

Table::Table(QWidget *parent) : QDialog(parent) {

    //Creates the table, then you set the number of rows and columns.
    table = new QTableWidget;

    table->setRowCount(row);
    table->setColumnCount(column);

    tableHeader<<"a"<<"b"<<"c"<<"d"<<"e";
    table->setHorizontalHeaderLabels(tableHeader);


    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(table);

    setLayout(layout);
}

Table::~Table() {
    delete table;
}
