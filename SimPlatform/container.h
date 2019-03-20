#ifndef CONTAINER_H
#define CONTAINER_H

#include <QtWidgets>
#include <iostream>
#include <QIcon>

using namespace std;

class Container{


public:
    //QWidget qWidget;
    void createMainContainer( QMainWindow *mainWindow ,int length, int width, QString title, QString colour){

    mainWindow->setWindowTitle(title);
    mainWindow->resize(length,width);
    mainWindow->setStyleSheet("background-color: "+colour+";");
    mainWindow->setWindowIcon(QIcon(":/resources/icon/gpa_logo.png"));
    mainWindow->show();

}

   void createContainer( QWidget *centralWidget ,QWidget *qMainWidget, int length, int width, int positionX, int positionY, QString title, QString colour){

            qMainWidget->setParent(centralWidget);
            qMainWidget->resize(length, width);
            qMainWidget->move(positionX, positionY);
            qMainWidget->setToolTip(title);
            qMainWidget->setStyleSheet("background-color: "+colour+";");
            qMainWidget->show();

    }

};

#endif // CONTAINER_H
