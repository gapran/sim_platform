#include "container.h"
#include "text.h"
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

    // Text
    QWidget *textWidget = new QWidget(mainContainerView.centralWidget());
    Text *text = new Text(textWidget);
    // text->setText("Welcome to GPA");

    // Text Styles
    text->setFontFamily("Georgia");
    text->setTextSize(16);
    text->setTextItalic();
    text->setTextUnderline();
    text->setTextBold();
    text->setTextColor("blue");
    text->setBackgroundColor("yellow");

    QString link = "<a href=\"www.upb.de\" >Visit UPB</a>";
    text->setClick(link);

    container.createContainer(mainContainerView.centralWidget(), text, 450, 100, 150, 300, "This is hover for this text box.", "white");


    // User Code ends

    mainContainerView.show();
    return app.exec();
}
