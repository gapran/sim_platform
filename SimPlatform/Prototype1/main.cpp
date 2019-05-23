#include "container.h"
#include "image.h"
#include "table.h"
#include "maincontainerview.h"
#include <QApplication>
#include <QPushButton>
#include <QBoxLayout>
#include <QLayout>
#include <QDebug>
#include <QTextEdit>
#include <QTextBrowser>
#include <QHBoxLayout>
#include "text.h"
#include"graphs.h"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    qDebug() << "Welcome to GPA Prototype Builder!";
    MainWindow mainContainerView;

    // User Code goes here...

    QString mainTitle = "GPA Prototype";
    int mainContainerLength = 1000;
    int mainContainerWidth = 400;
    QString mainColour = "white";


    //Create main GpaComponent / window
    Container container;
    container.createMainContainer(&mainContainerView, mainContainerLength, mainContainerWidth, mainTitle, mainColour);


    //Create inner containers

    // GPA Issue 4 - Table implementation
    Table *table1 = new Table(mainContainerView.centralWidget());

    //Create Table with rows and columns
    table1->createTable(7, 7);

    QStringList tableHeadersList = {"Name", "Status", "Progress", "Start date", "Last date", "Description", "Action"};
    table1->addTableHeaders(tableHeadersList);

    QStringList insertNameColumn = {"Alex", "John", "Mike", "Bob", "Max", "Sarah", "Cindy"};
    table1->addTableNameColumns(insertNameColumn);

    QStringList insertStatusColumn = {"fixed", "working", "not fixed", "fixed", "fixed", "not fixed", "working"};
    table1->addTableStatusColumns(insertStatusColumn);

    QStringList insertStartDateColumn = {"16-02-2019", "16-02-2019", "15-02-2019", "15-02-2019", "15-02-2019",
                                         "14-02-2019", "15-02-2019"};
    table1->addTableStartDateColumns(insertStartDateColumn);

    QStringList insertLastUpdateColumn = {"17-02-2019", "18-02-2019", "16-02-2019", "17-02-2019", "17-02-2019",
                                          "18-02-2019", "18-02-2019"};
    table1->addTableLastUpdateColumns(insertLastUpdateColumn);

    QStringList insertDescriptionColumn = {"des1", "des2", "des3", "des4", "des5", "des6", "des7"};
    table1->addTableDescriptionColumns(insertDescriptionColumn);

    QStringList insertActionColumn = {"action1", "action2", "action3", "action4", "action5", "action6", "action7"};
    table1->addTableActionColumns(insertActionColumn);


    //Update a certain cell in a table with a certain row id and column
    //table1->updateTable(2, 1, "fixed");

    //Filter the table: Column name and Filter keyword
    //table1->applyFilter("Status", "not fixed");

    //Apply border width and color for Table window
    //QStringList insertBorderStyle = {"1px", "blue"};
    //table1->applyBorderWidthColor(insertBorderStyle);

    //Search on Column ID
    //table1->findColumn("Action");

    //When the user presses a column header then sorting happens.
    //table1->sort(true);

    container.createContainer(mainContainerView.centralWidget(), table1, 700, 200, 150, 10, "Table Container", "gray");

    // Text
       QWidget *textWidget = new QWidget(mainContainerView.centralWidget());
       Text *text = new Text(textWidget);

    // Text Styles
       text->setFontFamily("Georgia");
       text->setTextSize(10);
       //text->setTextItalic();
       //text->setTextUnderline();
       text->setTextBold();
       //text->setTextColor("blue");
       text->setBackgroundColor("white");
       text->noBorder();

       text->setText("Bronze");
     //QString link = "<a href=\"www.example.de\bronze\">Bronze</a>";
     //text->setClick(link);

     container.createContainer(mainContainerView.centralWidget(), text, 100, 100, 10, 100, "This is hover for this text box.", "white");

    // Image
      QWidget *image1Widget = new QWidget(mainContainerView.centralWidget());
      Image *image1 = new Image(image1Widget);
      QString filename = ":/resources/icon/bronze_image.jpg";
      image1->setImage(filename);
      image1->setBox();
      image1->setHover("This is Bronze Image.");
      image1->noBorder();
      //image1->clicked();

    container.createContainer(mainContainerView.centralWidget(), image1, 100, 100, 10, 10, "This is hover for image.", "white");

    QWidget *graph = new QWidget(mainContainerView.centralWidget());
    Graphs *barGraph = new Graphs(graph);
    QStringList names = {"Bronze", "Silver", "Gold", "Master","Proessional"};
    QStringList val = {"10", "50", "25", "80","65"};
    barGraph->drawBarGraph(5, names, val);

    container.createContainer(mainContainerView.centralWidget(), barGraph, 400, 300, 80, 80, "This is hover for graph.", "white");

    Graphs *lineGraph = new Graphs(graph);
    //int values[5][2] = {{0,6}, {2,4}, {3,8}, {7,4}, {10,5}};
    QStringList valx = {"0", "2", "3", "7","10"};
    QStringList valy = {"6", "4", "8", "4","5"};
    int num = 5;
    lineGraph->drawLineGraph(num, valx, valy);

    container.createContainer(mainContainerView.centralWidget(), lineGraph, 400, 300, 550, 80, "This is hover for graph.", "white");
   // User Code ends

    mainContainerView.show();
    return app.exec();
}
