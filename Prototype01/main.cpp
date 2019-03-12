#include "gpacomponent.h"
#include "maincontainerview.h"
#include <QApplication>
#include <QBoxLayout>
#include <QLayout>
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    qDebug() << "Welcome to GPA Prototype Builder!";
    MainWindow mainComponentView;
    QWidget* presentWindow = QApplication::activeWindow();


    // User Code goes here...

        QString mainTitle = "GPA Prototype";
        int mainComponentLength = 900;
        int mainComponentWidth = 300;
        QString mainColour = "green";

        //Create main GpaComponent / window

        GpaComponent component;
        component.createMainComponent(&mainComponentView, mainComponentLength, mainComponentWidth, mainTitle, mainColour);

        //Create inner components

     component.createComponent(&mainComponentView, 100, 100, 25, 25, "Component1 1", "blue");
     component.createComponent(&mainComponentView, 50, 50, 50, 50, "Component 2", "orange");


     component.setChild(presentWindow, "Component 2", "Component 1");


//     container.createContainer(&mainContainerView, 50, 50, 150, 10, "Container 3", "brown");
//     container.createContainer(&mainContainerView, 50, 50, 800, 200, "Container 4", "purple");


   //User Code ends


     mainComponentView.show();
     return app.exec();
}
