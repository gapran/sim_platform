#include "container.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    qDebug() << "Welcome to GPA Prototype Builder!";
    MainWindow mainWindowView;

    // User Code goes here...

        //Create main container / window
        Container top;
        top.createMainContainer(&mainWindowView, 900,300,"GPA Prototype");

   //User Code ends

     mainWindowView.show();
     return app.exec();

}
