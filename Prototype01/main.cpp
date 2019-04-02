#include "mainwindow.h"
#include <QApplication>
#include "codeeditor.h"
#include "QWidget"
#include "QPushButton"
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QTableView>
#include <QtGui>
#include <QDockWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EditorWindow editor;
    editor.setWindowTitle(QObject::tr("Code Editor"));
    editor.showMaximized();
    editor.resize(640, 512);

    // testing
//    QMainWindow *mainWindow = new QMainWindow;
//        mainWindow->setWindowTitle("MainWindow") ;
//        mainWindow->setCentralWidget(new QTextEdit("Hello Main World!")) ;
//        QDockWidget *dock = new QDockWidget;
//        mainWindow->addDockWidget(Qt::RightDockWidgetArea, dock);
//        QToolBar *toolbar1 = new QToolBar ;
//        toolbar1->addAction(new QAction("FirstOne",0)) ;
//        mainWindow->addToolBar(toolbar1) ;
//        QToolBar *toolbar2 = new QToolBar ;
//        toolbar2->addAction(new QAction("SecondOne",0)) ;
//        mainWindow->addToolBar(toolbar2) ;
//   QDockWidget *dock = new QDockWidget;
//    editor->addDockWidget(Qt::RightDockWidgetArea, dock);
//    QMainWindow *subMainWindow = new QMainWindow(0);	// no parent
//    subMainWindow->setWindowTitle("sub-mainwindow") ;
//    subMainWindow->setCentralWidget(new QTextEdit("Hello Submain World!")) ;
//    QToolBar *toolbar3 = new QToolBar ;
//    toolbar3->addAction(new QAction("ThirdOne",0)) ;
//    subMainWindow->addToolBar(toolbar3) ;

//    dock->setWidget(subMainWindow) ;
//    subMainWindow->setParent(dock) ;
//mainWindow->show();


    /// for popup error tab
    QString fileName;

     if (argc >= 2)
         fileName = argv[1];
     else
         fileName = ".";

     TabDialog tabdialog(fileName);
     tabdialog.show();
    return a.exec();
}
