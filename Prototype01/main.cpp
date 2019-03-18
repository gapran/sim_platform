#include "container.h"
#include "maincontainerview.h"
#include <QApplication>
#include <QPushButton>
#include<QGraphicsProxyWidget>
#include <QBoxLayout>
#include <QLayout>
#include <QDebug>

QGraphicsProxyWidget* buttonWidget;

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    qDebug() << "Welcome to GPA Prototype Builder!";
    MainWindow mainContainerView;

    QWidget *qWidget = new QWidget();

    // User Code goes here...

        QString mainTitle = "GPA Prototype";
        int mainContainerLength = 900;
        int mainContainerWidth = 300;
        QString mainColour = "green";


        //Create main GpaComponent / window
        Container container;
        container.createMainContainer(&mainContainerView,  mainContainerLength, mainContainerWidth, mainTitle, mainColour);


        //Create inner containers
        container.createContainer(mainContainerView.centralWidget(), qWidget, 50, 50, 10, 10, "Container 1", "blue");

      //  QPushButton *button = new QPushButton;
      //  buttonWidget->scene()->addWidget(button);
      //  container.createContainer(mainContainerView.centralWidget(), &buttonWidget, 50, 50, 80, 10, "Container 2", "orange");
     //   container.createContainer(mainContainerView.centralWidget(), 50, 50, 150, 10, "Container 3", "brown");


    // User Code ends

     mainContainerView.show();
     return app.exec();
}
