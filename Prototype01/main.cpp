#include "mainwindow.h"
#include <QApplication>
#include "gpacomponent.h"
#include "addstatlib.h"
#include "QWidget"
#include "QPushButton"
#include <QVBoxLayout>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    GpaComponent gpalib; // library
    addStatLib addlayout; //add layout

    int width =500;
    int height =500;
    QString name = "GPA";
    QString color = "grey";

    QBoxLayout* ql = gpalib.newVLayout();
    addlayout.ListView(ql, "This is List View");
    QWidget* qw = gpalib.newComponent(150, 150, 0, 20, ql, "lightgrey", "Container name","font name");

    QBoxLayout* ql2 = gpalib.newVLayout();
    QWidget* qw2 = gpalib.newComponent(200, 200, 150, 20, ql2, "black", "Container name","font name");

    w.layout()->addWidget(qw);
    w.layout()->addWidget(qw2);
    w.setToolTip("Main Window");


    gpalib.mainView(&w , name,width,height,color);    //initializing
    w.show();
    return a.exec();
}
