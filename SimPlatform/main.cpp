#include <QApplication>
#include <iostream>

#include "table.h"

using namespace std;

extern int rowUpdateNo;
extern int columnUpdateNo;

extern QString bgColor;
extern QString valueUpdate;
extern QString filtersName;
extern QStringList tableHeaders;
extern QString columnFiltersName;
extern QStringList tableNamesColumn;
extern QStringList tableActionsColumn;
extern QStringList borderWidthColorStyle;
extern QStringList tableStartDatesColumn;
extern QStringList tableLastUpdatesColumn;
extern QStringList tableDescriptionsColumn;
extern QStringList tableStatusColumnValues;







int main(int argc, char *argv[]) {
    Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("GPA");
    QCoreApplication::setApplicationName("GPA Prototype");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);


    //Create Table with rows and columns
    Table table;
    table.createTable(6,7);

    QStringList tableHeadersList = {"Name", "Status", "Progress", "Start date", "Last date", "Description", "Action"};
    table.addTableHeaders(tableHeadersList);

    QStringList insertNameColumn = {"Alex", "John", "Mike", "Bob", "Max"};
    table.addTableNameColumns(insertNameColumn);

    QStringList insertStatusColumn = {"fixed", "working", "not fixed", "fixed", "fixed"};
    table.addTableStatusColumns(insertStatusColumn);

    QStringList insertStartDateColumn = {"16-02-2019", "16-02-2019", "15-02-2019", "15-02-2019", "15-02-2019"};
    table.addTableStartDateColumns(insertStartDateColumn);

    QStringList insertLastUpdateColumn = {"17-02-2019", "18-02-2019", "16-02-2019", "17-02-2019", "17-02-2019"};
    table.addTableLastUpdateColumns(insertLastUpdateColumn);

    QStringList insertDescriptionColumn = {"des1", "des2", "des3", "des4", "des5"};
    table.addTableDescriptionColumns(insertDescriptionColumn);

    QStringList insertActionColumn = {"action1", "action2", "action3", "action4", "action5"};
    table.addTableActionColumns(insertActionColumn);

    //Update a certain cell in a table with a certain row id and column
    // updateTable(2, 1, "fixed");

    //Filter the table: Column name and Filter keyword
    //applyFilter("Status", "not fixed");

    //Apply color for background to Table
    //applyBackgroundColor("yellow");

    //Apply border width and color for Table window
    QStringList insertBorderStyle = {"1px", "blue"};
    table.applyBorderWidthColor(insertBorderStyle);

    Table *window = new Table;
    window->show();

    //Search on Column ID
    //findColumn("Action");


    return app.exec();
}
