#include "container.h"
#include "table.h"
#include "maincontainerview.h"
#include <QApplication>
#include <QPushButton>
#include <QBoxLayout>
#include <QLayout>
#include <QDebug>


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    qDebug() << "Welcome to GPA Prototype Builder!";
    MainWindow mainContainerView;

    // User Code goes here...

        QString mainTitle = "GPA Prototype";
        int mainContainerLength = 900;
        int mainContainerWidth = 300;
        QString mainColour = "white";


        //Create main GpaComponent / window
        Container container;
        container.createMainContainer(&mainContainerView,  mainContainerLength, mainContainerWidth, mainTitle, mainColour);


        //Create inner containers

        QWidget *tableWidget = new QWidget();
        Table *table1 = new Table(tableWidget);

        //Create Table with rows and columns
        table1->createTable(6,7);

        QStringList tableHeadersList = {"Name", "Status", "Progress", "Start date", "Last date", "Description", "Action"};
        table1->addTableHeaders(tableHeadersList);

        table1->show();
        tableWidget->show();



//        QStringList insertNameColumn = {"Alex", "John", "Mike", "Bob", "Max"};
//        table->addTableNameColumns(insertNameColumn);

//        QStringList insertStatusColumn = {"fixed", "working", "not fixed", "fixed", "fixed"};
//        table->addTableStatusColumns(insertStatusColumn);

//        QStringList insertStartDateColumn = {"16-02-2019", "16-02-2019", "15-02-2019", "15-02-2019", "15-02-2019"};
//        table->addTableStartDateColumns(insertStartDateColumn);

//        QStringList insertLastUpdateColumn = {"17-02-2019", "18-02-2019", "16-02-2019", "17-02-2019", "17-02-2019"};
//        table->addTableLastUpdateColumns(insertLastUpdateColumn);

//        QStringList insertDescriptionColumn = {"des1", "des2", "des3", "des4", "des5"};
//        table->addTableDescriptionColumns(insertDescriptionColumn);

//        QStringList insertActionColumn = {"action1", "action2", "action3", "action4", "action5"};
//        table->addTableActionColumns(insertActionColumn);



      //  container.createContainer(mainContainerView.centralWidget(), tableWidget, 500, 200, 150, 10, "Table Container","gray");



    // User Code ends

     mainContainerView.show();
     return app.exec();
}


////Update a certain cell in a table with a certain row id and column
//// updateTable(2, 1, "fixed");

////Filter the table: Column name and Filter keyword
////applyFilter("Status", "not fixed");

////Apply color for background to Table
////applyBackgroundColor("yellow");

////Apply border width and color for Table window
//QStringList insertBorderStyle = {"1px", "blue"};
//table->applyBorderWidthColor(insertBorderStyle);

////    Table *window = new Table;
////    window->show();

////Search on Column ID
////findColumn("Action");
