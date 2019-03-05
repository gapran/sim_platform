#include "mainwindow.h"
#include <QApplication>
#include "statlib.h"
#include "QWidget"
#include "QPushButton"
#include <QVBoxLayout>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    StatLib clib; // library

    int width =1000;
    int height =500;
    QString name = "GPA";
    QString color = "lightgrey";

    clib.mainView(&w , name,width,height,color);    //initializing
    w.show();
    return a.exec();
}
