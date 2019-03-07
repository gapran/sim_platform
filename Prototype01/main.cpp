#include "container.h"
#include "maincontainerview.h"
#include <QApplication>
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
        QString mainColour = "sky-blue";

        //Create main container / window
        Container container;
        container.createMainContainer(&mainContainerView, mainContainerLength, mainContainerWidth, mainTitle, mainColour);

        //Create inner containers
        QBoxLayout* qBoxLayout1 = new QVBoxLayout();
        QWidget* container1 = container.createContainer(qBoxLayout1, 50, 50, 10, 10, "Container 1", "blue");
        mainContainerView.layout()->addWidget(container1);

        QBoxLayout* qBoxLayout2 = new QHBoxLayout();
        QWidget* container2 = container.createContainer(qBoxLayout2, 50, 50, 70, 80, "Container 2", "orange");
        mainContainerView.layout()->addWidget(container2);


   //User Code ends

     mainContainerView.show();
     return app.exec();

}
