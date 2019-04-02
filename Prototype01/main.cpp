#include "container.h"
#include "image.h"
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

    QWidget *image1Widget = new QWidget(mainContainerView.centralWidget());
    Image *image1 = new Image(image1Widget);
    QString filename = "C:/Users/varma/Pictures/gpa_logo.PNG";
    image1->setImage(filename);
    image1->setBox();
    image1->setHover("This is GPA Logo.");
    image1->clicked();
    container.createContainer(mainContainerView.centralWidget(), image1, 100, 100, 50, 100, "This is hover for image.", "white");


    // User Code ends

    mainContainerView.show();
    return app.exec();
}
