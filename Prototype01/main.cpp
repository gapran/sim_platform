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

    // User Code goes here...

        QString mainTitle = "GPA Prototype";
        int mainComponentLength = 900;
        int mainComponentWidth = 300;
        QString mainColour = "green";


        //Create main GpaComponent / window

        GpaComponent* gpaComponent = new GpaComponent(&mainComponentView, mainComponentLength, mainComponentWidth, mainTitle, mainColour);


        //Create inner components

    //    GpaComponent* childComponent1 = new GpaComponent( 100, 100,  "Component 1", "blue");


    //   QBoxLayout* layout =  gpaComponent->addChild(&mainComponentView, childComponent1,0,0);
     //  mainComponentView.setLayout(layout);
//

   //User Code ends


     mainComponentView.show();
     return app.exec();
}
