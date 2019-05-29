#include "button.h"
#include "container.h"
#include "filter.h"
#include "image.h"
#include "maincontainerview.h"
#include "table.h"
#include "text.h"
#include <QApplication>
#include <QBoxLayout>
#include <QDebug>
#include <QHBoxLayout>
#include <QLayout>
#include <QObject>
#include <QPushButton>
#include <QTextBrowser>
#include <QTextEdit>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    qDebug() << "Welcome to GPA Prototype Builder!";
    MainWindow mainContainerView;

    // User Code goes here...

    QString mainTitle = "GPA Prototype";
    int mainContainerLength = 1050;
    int mainContainerWidth = 400;
    QString mainColour = "white";

    // Create main GpaComponent / window
    Container container;
    container.createMainContainer(&mainContainerView, mainContainerLength,
                                  mainContainerWidth, mainTitle, mainColour);

    // Create inner containers

    // GPA Issue 4 - Table implementation
    Table *table1 = new Table(mainContainerView.centralWidget());

    // Create Table with rows and columns
    table1->createTable(7, 7);

    QStringList tableHeadersList = {"Name",       "Status",    "Progress",
                                    "Start date", "Last date", "Description",
                                    "Action"};
    table1->addTableHeaders(tableHeadersList);

    QStringList insertNameColumn = {"Alex", "John",  "Mike", "Bob",
                                    "Max",  "Sarah", "Cindy"};
    table1->addTableNameColumns(insertNameColumn);

    QStringList insertStatusColumn = {"fixed",  "working", "not fixed",
                                      "fixed",  "fixed",   "not fixed",
                                      "working"};
    table1->addTableStatusColumns(insertStatusColumn);

    QStringList insertStartDateColumn = {
        "16-02-2019", "16-02-2019", "15-02-2019", "15-02-2019",
        "15-02-2019", "14-02-2019", "15-02-2019"};
    table1->addTableStartDateColumns(insertStartDateColumn);

    QStringList insertLastUpdateColumn = {
        "17-02-2019", "18-02-2019", "16-02-2019", "17-02-2019",
        "17-02-2019", "18-02-2019", "18-02-2019"};
    table1->addTableLastUpdateColumns(insertLastUpdateColumn);

    QStringList insertDescriptionColumn = {"des1", "des2", "des3", "des4",
                                           "des5", "des6", "des7"};
    table1->addTableDescriptionColumns(insertDescriptionColumn);

    QStringList insertActionColumn = {"action1", "action2", "action3",
                                      "action4", "action5", "action6",
                                      "action7"};
    table1->addTableActionColumns(insertActionColumn);

    // Update a certain cell in a table with a certain row id and column
    // table1->updateTable(2, 1, "fixed");

    // Filter the table: Column name and Filter keyword
    // table1->applyFilter("Status", "not fixed");

    // Apply border width and color for Table window
    // QStringList insertBorderStyle = {"1px", "blue"};
    // table1->applyBorderWidthColor(insertBorderStyle);

    // Search on Column ID
    // table1->findColumn("Action");

    // When the user presses a column header then sorting happens.
    // table1->sort(true);

    container.createContainer(mainContainerView.centralWidget(), table1, 700,
                              200, 150, 10, "Table Container", "gray");

    // Text
    QWidget *textWidget = new QWidget(mainContainerView.centralWidget());
    Text *text = new Text(textWidget);

    // Text Styles
    text->setFontFamily("Georgia");
    text->setTextSize(10);
    // text->setTextItalic();
    // text->setTextUnderline();
    text->setTextBold();
    // text->setTextColor("blue");
    text->setBackgroundColor("white");
    text->noBorder();

    text->setText("Bronze");
    // QString link = "<a href=\"www.example.de\bronze\">Bronze</a>";
    // text->setClick(link);

    container.createContainer(mainContainerView.centralWidget(), text, 100, 100,
                              10, 100, "This is hover for this text box.",
                              "white");

    // Image
    QWidget *image1Widget = new QWidget(mainContainerView.centralWidget());
    Image *image1 = new Image(image1Widget);
    QString filename = ":/resources/icon/bronze_image.jpg";
    image1->setImage(filename);
    image1->setBox();
    image1->setHover("This is Bronze Image.");
    image1->noBorder();
    // image1->clicked();

    container.createContainer(mainContainerView.centralWidget(), image1, 100,
                              100, 10, 10, "This is hover for image.", "white");

    // Filter - For header, give index number considering complete list
    QWidget *filter1Widget = new QWidget(mainContainerView.centralWidget());
    Filter *filter1 = new Filter(filter1Widget);

    filter1->createFilter("My Bugs");
    filter1->createFilter("All Bugs");

    filter1->createFilterHeader("Status", 2);
    QStringList insertFilters0 = {"fixed", "not fixed", "working"};
    filter1->createFilterList(insertFilters0);

    filter1->createFilterHeader("Marker Type", 6);
    QStringList insertFilters1 = {"Source", "Sink", "Fix locations"};
    filter1->createFilterList(insertFilters1);

    filter1->createFilterHeader("Vulnerability Type", 10);
    QStringList insertFilters2 = {"SQL Injections", "XSS", "CSRF"};
    filter1->createFilterList(insertFilters2);

    container.createContainer(mainContainerView.centralWidget(), filter1, 150,
                              200, 870, 10, "This is hover for filter.",
                              "white");

    // Filter Button
    QWidget *filterButtonWidget =
        new QWidget(mainContainerView.centralWidget());
    Button *filterButton = new Button(filterButtonWidget);
    filterButton->setName("Filter");
    container.createContainer(mainContainerView.centralWidget(), filterButton,
                              150, 50, 870, 200,
                              "This is hover for filter butoon.", "white");

    // Connections

    //    QObject::connect(filter1, &Filter::itemSelectionChanged, table1,
    //                     table1->filterTable(filter1->selectedItems()));

    QObject::connect(filter1, SIGNAL(itemSelectionChanged()), table1,
                     SLOT(filterTable()));

    QPushButton *button = new QPushButton("click me");
    QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
    button->show();
    // User Code ends

    mainContainerView.show();
    return app.exec();
}
