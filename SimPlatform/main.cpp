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

    int width =500;
    int height =500;
    QString name = "GPA";
    QString color = "grey";

    QBoxLayout* ql = clib.newVLayout();
    clib.addListView(ql, "This is List View");
    QWidget* qw = clib.newComponent(150, 150, 0, 20, ql, "lightgrey", "Container 01");

    QBoxLayout* ql2 = clib.newVLayout();
    QWidget* qw2 = clib.newComponent(200, 200, 150, 20, ql2, "black", "Container 02");

    w.layout()->addWidget(qw);
    w.layout()->addWidget(qw2);
    w.setToolTip("Main Window");


    clib.mainView(&w , name,width,height,color);    //initializing
    w.show();
    return a.exec();
}
