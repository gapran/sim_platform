#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "mainwindow.h"
#include "table.h"

#include <iostream>

using namespace std;

extern int row;
extern int column;
extern int rowUpdateNo;
extern int columnUpdateNo;

extern QString bgColor;
extern QString valueUpdate;
extern QString filtersName;
extern QStringList tableHeaders;
extern QString columnFiltersName;
extern QStringList tableNamesColumn;
extern QStringList tableActionsColumn;
extern QStringList tableStartDatesColumn;
extern QStringList tableLastUpdatesColumn;
extern QStringList tableDescriptionsColumn;
extern QStringList tableStatusColumnValues;


void createTable(int a, int b) {

    row = a;
    column = b;

}

void updateTable(int rowNo, int columnNo, QString value) {

    rowUpdateNo = rowNo;
    columnUpdateNo = columnNo;
    valueUpdate = value;
}

void addTableHeaders(QStringList tableHeadersList) {

    for (int var = 0; var < tableHeadersList.size(); ++var) {
        tableHeaders.append(tableHeadersList[var]);
    }
}

void addTableNameColumns(QStringList tableNameColumn) {
    for (int var = 0; var < tableNameColumn.size(); ++var) {
        tableNamesColumn.append(tableNameColumn[var]);
    }
}

void addTableStatusColumns(QStringList tableStatusColumn) {
    for (int j = 0; j < tableStatusColumn.size(); ++j) {
        tableStatusColumnValues.append(tableStatusColumn[j]);
    }
}

void addTableStartDateColumns(QStringList tableStartDateColumn) {
    for (int l = 0; l < tableStartDateColumn.size(); ++l) {
        tableStartDatesColumn.append(tableStartDateColumn[l]);
    }
}

void addTableLastUpdateColumns(QStringList tableLastUpdateColumn) {
    for (int m = 0; m < tableLastUpdateColumn.size(); ++m) {
        tableLastUpdatesColumn.append(tableLastUpdateColumn[m]);
    }
}

void addTableDescriptionColumns(QStringList tableDescriptionColumn) {
    for (int k = 0; k < tableDescriptionColumn.size(); ++k) {
        tableDescriptionsColumn.append(tableDescriptionColumn[k]);
    }
}

void addTableActionColumns(QStringList tableActionColumn) {
    for (int n = 0; n < tableActionColumn.size(); ++n) {
        tableActionsColumn.append(tableActionColumn[n]);
    }
}

void findColumn(QString columnName) {
    for (int a = 0; a < tableHeaders.size(); ++a) {
        if (columnName == tableHeaders[a]) {
            cout << "The column is found in the table." << "\n";
        }
    }
}

void applyFilter(QString columnFilterName, QString filterName) {

    columnFiltersName = columnFilterName;
    filtersName = filterName;

}

void applyBackgroundColor(QString backgroundColor){

    bgColor = "background-color:"+backgroundColor;

}

/*
 * Example from:
 * http://doc.qt.io/qt-5/qtwidgets-mainwindows-application-example.html
 */
int main(int argc, char *argv[]) {
    Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationName("Application Example");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", "The file to open.");
    parser.process(app);

    MainWindow mainWin;
    if (!parser.positionalArguments().isEmpty())
        mainWin.loadFile(parser.positionalArguments().first());
    mainWin.show();

    //Create Table with rows and columns
    createTable(5, 7);

    QStringList tableHeadersList = {"Name", "Status", "Progress", "Start date", "Last date", "Description", "Action"};
    addTableHeaders(tableHeadersList);

    QStringList insertNameColumn = {"Alex", "John", "Mike", "Bob", "Max"};
    addTableNameColumns(insertNameColumn);

    QStringList insertStatusColumn = {"fixed", "working", "not fixed", "fixed", "fixed"};
    addTableStatusColumns(insertStatusColumn);

    QStringList insertStartDateColumn = {"16-02-2019", "16-02-2019", "15-02-2019", "15-02-2019", "15-02-2019"};
    addTableStartDateColumns(insertStartDateColumn);

    QStringList insertLastUpdateColumn = {"17-02-2019", "18-02-2019", "16-02-2019", "17-02-2019", "17-02-2019"};
    addTableLastUpdateColumns(insertLastUpdateColumn);

    QStringList insertDescriptionColumn = {"des1", "des2", "des3", "des4", "des5"};
    addTableDescriptionColumns(insertDescriptionColumn);

    QStringList insertActionColumn = {"action1", "action2", "action3", "action4", "action5"};
    addTableActionColumns(insertActionColumn);

    //Update a certain cell in a table with a certain row id and column
    // updateTable(2, 1, "fixed");

    //Filter the table: Column name and Filter keyword
    //applyFilter("Status", "not fixed");

    //Apply color for background to Table
    applyBackgroundColor("yellow");

    Table *window = new Table;
    window->showMaximized();

    //Search on Column ID
    //findColumn("Action");


    return app.exec();
}
