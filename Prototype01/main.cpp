#include "container.h"
#include "maincontainerview.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QLayout>
#include <QDebug>


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


    // Layout
    QWidget *layoutWidget = new QWidget(mainContainerView.centralWidget());
    Layout *layout = new Layout(layoutWidget);


    container.createContainer(mainContainerView.centralWidget(), layout, 450, 100, 150, 300, "This is layout.", "white");


    // User Code ends

    mainContainerView.show();
    return app.exec();
}
