#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "mainwindow.h"
#include "text.h"

/*
 * Example from:
 * http://doc.qt.io/qt-5/qtwidgets-mainwindows-application-example.html
 */

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationName("Application Example");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", "The file to open.");
    parser.process(app);

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
