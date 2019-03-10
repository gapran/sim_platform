#include "mainwindow.h"
#include <QApplication>
#include "gpacomponent.h"
#include "QWidget"
#include "QPushButton"
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    GpaComponent gpalib; // library

    int width =500;
    int height =500;
    QString name = "GPA";
    QString color = "grey";

    QBoxLayout* ql = gpalib.newVLayout();
    QListView* lv = new QListView();
    gpalib.addView(ql,lv,0, 20,"list view added"); // any view can be passed to the layout
    QWidget* qw = gpalib.newComponent(150, 150, 0, 20, ql, "lightgrey", "Container name");

    QBoxLayout* ql2 = gpalib.newVLayout();
    QTableView* tv = new QTableView();
    gpalib.addView(ql2,tv, 150, 20,"table view added"); // any view can be passed to the layout
    QWidget* qw2 = gpalib.newComponent(200, 200, 150, 20, ql2, "black", "Container name");

//    gpalib.close(qw2);// closing a component through library
//    gpalib.open(qw2); //opening a component through a library
//    gpalib.resize(qw2, 500,500); //resizing 2nd component
    gpalib.update(qw2 ,ql2 ,lv , 200, 200, 500, 500, "blue"); //updating listview to table view  and positions , size color etc

    w.layout()->addWidget(qw);
    w.layout()->addWidget(qw2);
    w.setToolTip("Main Window");


    gpalib.mainView(&w , name,width,height,color);    //initializing
    w.show();
    return a.exec();
}
