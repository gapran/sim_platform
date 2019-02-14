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

    ~Table();

private:
    QTableWidget *table;

};


#endif // TABLE_H
