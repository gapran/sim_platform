#include "container.h"
#include "maincontainerview.h"
#include <QApplication>
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
        QString mainColour = "green";

        //Create main container / window

        Container container;
        container.createMainContainer(&mainContainerView, mainContainerLength, mainContainerWidth, mainTitle, mainColour);

        //Create inner containers

        QWidget* container1 = container.createContainer( 50, 50, 10, 10, "Container 1", "blue");
        QWidget* container2 = container.createContainer( 50, 50, 80, 10, "Container 2", "orange");
        QWidget* container3 = container.createContainer( 50, 50, 150, 10, "Container 3", "brown");



        //Specify Layout for the containers

        Container layoutContainer1;
        Container layoutContainer2;

        QWidgetList containerList1;
        containerList1.append(container1);
        containerList1.append(container2);


       layoutContainer1.createLayout(&mainContainerView, "horizontalLayout", containerList1);


       // Add 3rd container in vertical layout

//       QWidgetList containerList2;
//       containerList1.append(container3);
//       layoutContainer2.createLayout(&mainContainerView, "verticalLayout", containerList2);



   //User Code ends



     mainContainerView.show();
     return app.exec();
}
