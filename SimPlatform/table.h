#ifndef TABLE_H
#define TABLE_H

#include <QDialog>

#include <QTableWidgetItem>
#include <QTableWidget>
#include <QHBoxLayout>

class Table : public QDialog {
    Q_OBJECT

public:
    explicit Table(QWidget *parent = 0);
    void createTable(int row, int column);
    void updateTable(int rowNo, int columnNo, QString value);
    void addTableHeaders(QStringList tableHeadersList);
    void addTableNameColumns(QStringList tableNameColumn);
    void addTableStatusColumns(QStringList tableStatusColumn);
    void addTableStartDateColumns(QStringList tableStartDateColumn);
    void addTableLastUpdateColumns(QStringList tableLastUpdateColumn);
    void addTableDescriptionColumns(QStringList tableDescriptionColumn);
    void addTableActionColumns(QStringList tableActionColumn);
    void findColumn(QString columnName);
    void setSorting(bool value);
    void applyFilter(QString columnFilterName, QString filterName);
    void applyBackgroundColor(QString backgroundColor);
    void applyBorderWidthColor( QStringList borderWidthColor);

    ~Table();

private:
    QTableWidget *table;

};


#endif // TABLE_H
