#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include "mainwindow.h"
#include "gpaview.h"

/*
 * Example from:
 * http://doc.qt.io/qt-5/qtwidgets-mainwindows-application-example.html
 */

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);
    QApplication app(argc, argv);
    GpaView gpa_view;
    gpa_view.show();

    return app.exec();
}
