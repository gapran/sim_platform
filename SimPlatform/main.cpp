#include "container.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    qDebug() << "Welcome to GPA Prototype Builder!";

    // User Code goes here...

        //Create main container / window
        Container top;
        top.createMainContainer(900,300,"GPA Prototype");


    return app.exec();

}
