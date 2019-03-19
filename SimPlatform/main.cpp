#include "main.h"
#include "mainwindow.h"
#include "text.h"

/*
 * Example from:
 * http://doc.qt.io/qt-5/qtwidgets-mainwindows-application-example.html
 */

int main(int argc, char *argv[])

{

    //Text Element
    QWidget *textWidget = new QWidget();
    Text *text = new Text(textWidget);
    text->setText("Welcome to GPA");
    text->show();
    textWidget->show();

    MainWindow mainWin;
    if (!parser.positionalArguments().isEmpty())
        mainWin.loadFile(parser.positionalArguments().first());
    mainWin.show();
    return app.exec();
}
