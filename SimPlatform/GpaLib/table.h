#ifndef TABLE_H
#define TABLE_H

#include <QHBoxLayout>
#include <QListWidget>
#include <QTableWidget>
#include <QTableWidgetItem>

class Table : public QTableWidget {
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);

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

    void sort(bool value);

    void applyFilter(QString columnFilterName, QString filterName);

    void applyBackgroundColor(QString backgroundColor);

    void applyBorderWidthColor(QStringList borderWidthColor);

    void show();

    ~Table();

private:
    QTableWidget *table;

public slots:

    void filterTable();
};


#endif // TABLE_H
