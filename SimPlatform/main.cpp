#include "main.h"
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
    text->setTextBold();
    text->setTextColor("blue");
    text->show();
    textWidget->show();

    MainWindow mainWin;
    if (!parser.positionalArguments().isEmpty())
        mainWin.loadFile(parser.positionalArguments().first());
    mainWin.show();
    return app.exec();
}
