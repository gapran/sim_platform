#include "container.h"
#include "bar.h"
#include "maincontainerview.h"
#include <QApplication>
#include <QPushButton>
#include <QBoxLayout>
#include <QLayout>
#include <QDebug>
#include <QTextEdit>
#include <QTextBrowser>
#include <QHBoxLayout>


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


    // Progress Bar
    QWidget *bar1Widget = new QWidget(mainContainerView.centralWidget());
    Bar *bar1 = new Bar(bar1Widget);
    bar1->setValue(0,100,60);
    bar1->setText("Analysis done!");
    bar1->updatable(true);
    container.createContainer(mainContainerView.centralWidget(), bar1, 150, 100, 10, 50, "Progress Bar", "white");

    QWidget *bar2Widget = new QWidget(mainContainerView.centralWidget());
    Bar *bar2 = new Bar(bar2Widget);
    bar2->populate();
    bar2->setText("Dummy value!");
    container.createContainer(mainContainerView.centralWidget(), bar2, 150, 100, 10, 200, "Progress Bar", "white");


    // User Code ends

    mainContainerView.show();
    return app.exec();
}
