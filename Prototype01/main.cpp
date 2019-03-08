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
      // mainContainerView.layout()->addWidget(container1);

        QWidget* container2 = container.createContainer( 50, 50, 80, 10, "Container 2", "orange");
       // mainContainerView.layout()->addWidget(container2);

//        QWidget* container3 = container.createContainer( 50, 50, 150, 10, "Container 3", "brown");
//        mainContainerView.layout()->addWidget(container3);



        //Specify Layout for the containers

        Container layoutContainer;
        QWidgetList containerList;
        containerList.append(container1);
        containerList.append(container2);

        QBoxLayout* layoutAll =  layoutContainer.createLayout(&mainContainerView, "horizontalLayout", containerList);
        mainContainerView.setLayout(layoutAll);


   //User Code ends

     mainContainerView.show();
     return app.exec();
}
