#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "mainwindow.h"
#include "table.h"

using namespace std;

extern int row;
extern int column;
extern QStringList tableHeaders;
extern QStringList tableNamesColumn;
//extern QStringList tableStatusColumn;
extern QStringList tableDescriptionsColumn;

void createTable(int a, int b) {

    row = a;
    column = b;

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

//void addTableStatusColumns(QStringList tableStatusColumn) {
//    for (int j = 0; j < tableStatusColumn.size(); ++j) {
//        tableStatusesColumn.append(tableStatusColumn[j]);
//    }
//}

void addTableDescriptionColumns(QStringList tableDescriptionColumn) {
    for (int k = 0; k < tableDescriptionColumn.size(); ++k) {
        tableDescriptionsColumn.append(tableDescriptionColumn[k]);
    }
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

    //Table
    createTable(5, 6);

    QStringList tableHeadersList = {"Name", "Status", "Progress", "Start date", "Last date", "Description"};
    addTableHeaders(tableHeadersList);

    QStringList insertNameColumn = {"Alex", "John", "Mike", "Bob", "Max"};
    addTableNameColumns(insertNameColumn);

//    QStringList insertStatusColumn = {"fixed", "working", "not fixed", "fixed", "fixed"};
//    addTableStatusColumns(insertStatusColumn);

    QStringList insertDescriptionColumn = {"des1", "des2", "des3", "des4", "des5"};
    addTableDescriptionColumns(insertDescriptionColumn);

    Table *window = new Table;
    window->showMaximized();

    return app.exec();
}
