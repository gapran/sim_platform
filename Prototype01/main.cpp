#include "container.h"
#include "layout.h"
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
    int mainContainerLength = 800;
    int mainContainerWidth = 600;
    QString mainColour = "white";


    //Create main GpaComponent / window
    Container container;
    container.createMainContainer(&mainContainerView, mainContainerLength, mainContainerWidth, mainTitle, mainColour);

    //Create layout
    QWidget *layoutWidget = new QWidget(mainContainerView.centralWidget());
    Layout *layoutMobile = new Layout(layoutWidget);
    //layoutMobile->setMobile();
    //layoutMobile->setWeb();
    //layoutMobile->setIDE();
    layoutMobile->setCLI();

    container.createContainer(mainContainerView.centralWidget(), layoutMobile, mainContainerLength, mainContainerWidth, 0, 0, "This is layout.", "white");


    // User Code ends

    mainContainerView.show();
    return app.exec();
}
