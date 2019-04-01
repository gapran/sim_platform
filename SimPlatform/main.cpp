<<<<<<< HEAD
#include "main.h"
=======
#include <QApplication>
#include<QLabel>
#include <QCommandLineParser>
#include <QCommandLineOption>

>>>>>>> Sets a link to a Text
#include "mainwindow.h"
#include "text.h"

/*
 * Example from:
 * http://doc.qt.io/qt-5/qtwidgets-mainwindows-application-example.html
 */

int main(int argc, char *argv[])

{

    // Text
    QWidget *textWidget = new QWidget();
    Text *text = new Text(textWidget);
    text->setText("Welcome to GPA");

    // Text Styles
    text->setFontFamily("Georgia");
    text->setTextSize(16);
    text->setTextItalic();
    text->setTextUnderline();
    text->setTextBold();
    text->setTextColor("blue");
    text->setBackgroundColor("yellow");

    //text->setHoverText("Hello");
    text->setClick("www.upb.de");

//    QLabel *myLabel = new QLabel();
//    myLabel->setText("<a href=\"http://example.com/\">Click Here!</a>");
//    myLabel->show();

    text->show();
    textWidget->show();

    // Text
    QWidget *textWidget = new QWidget();
    Text *text = new Text(textWidget);
    text->setText("Welcome to GPA");

    // Text Styles
    text->setFontFamily("Georgia");
    text->setTextSize(16);
    text->setTextItalic();
    text->setTextUnderline();
    text->setTextBold();
    text->setTextColor("blue");
    text->setBackgroundColor("yellow");

    //text->setHoverText("Hello");
    text->setClick("www.upb.de");

//    QLabel *myLabel = new QLabel();
//    myLabel->setText("<a href=\"http://example.com/\">Click Here!</a>");
//    myLabel->show();

    text->show();
    textWidget->show();

    MainWindow mainWin;
    if (!parser.positionalArguments().isEmpty())
        mainWin.loadFile(parser.positionalArguments().first());
    //mainWin.show();
    return app.exec();
}
