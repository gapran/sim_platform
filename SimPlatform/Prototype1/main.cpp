#include "container.h"
#include "layout.h"
#include "maincontainerview.h"
#include <QApplication>
#include <QBoxLayout>
#include <QDebug>
#include <QHBoxLayout>
#include <QLayout>
#include "bar.h"
#include "container.h"
#include "image.h"
#include "maincontainerview.h"
#include "table.h"
#include "text.h"
#include <QApplication>
#include <QBoxLayout>
#include <QDebug>
#include <QHBoxLayout>
#include <QLayout>
#include <QPushButton>
#include <QTextBrowser>
#include <QTextEdit>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    qDebug() << "Welcome to GPA Prototype Builder!";
    MainWindow mainContainerView;

    // User Code goes here...

    QString mainTitle = "GPA Prototype";
    int mainContainerLength = 1000;
    int mainContainerWidth = 600;
    QString mainColour = "white";

    // Create main GpaComponent / window
    Container container;
    container.createMainContainer(&mainContainerView, mainContainerLength,
                                  mainContainerWidth, mainTitle, mainColour);

    // Desired layout has be given here as a background image
    // Layout Examples: cli, ide, mobile, web
    // Replace the filename with desired layout name
    mainContainerView.setStyleSheet(
        "border-image:url(:/resources/icon/ide.jpg)0 0 0 0 stretch "
        "stretch;");

    //    // Layout Management - https://doc.qt.io/qt-5/layout.html

    //    QPushButton *button1 = new QPushButton("Button 1");
    //    QPushButton *button2 = new QPushButton("Button 2");
    //    QPushButton *button3 = new QPushButton("Button 3");

    //    // Image
    //    QWidget *image1Widget = new
    //    QWidget(mainContainerView.centralWidget()); Image *image = new
    //    Image(image1Widget); QString filename =
    //    ":/resources/icon/bronze_image.jpg"; image->setImage(filename);
    //    image->setHover("This is Bronze Image.");
    //    image->noBorder();

    //    // Progress bar
    //    QWidget *imageCopy1Widget = new
    //    QWidget(mainContainerView.centralWidget()); Bar *bar = new
    //    Bar(imageCopy1Widget, 0, 100); bar->setValue(60);

    //    QGridLayout *layout = new QGridLayout;
    //    layout->addWidget(image, 0, 0);
    //    layout->addWidget(bar, 0, 1);
    //    layout->addWidget(button1, 1, 0, 1, 2);
    //    layout->addWidget(button2, 2, 0);
    //    layout->addWidget(button3, 2, 1);

    //    mainContainerView.centralWidget()->setLayout(layout);

    // User Code ends

    mainContainerView.show();
    return app.exec();
}
