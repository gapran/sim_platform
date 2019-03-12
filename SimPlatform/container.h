#ifndef CONTAINER_H
#define CONTAINER_H

#include <QtWidgets>
#include <iostream>
#include <QIcon>

using namespace std;

class Container{

private:
    int length;
    int width;
    QString title;

public:

    void createMainContainer( QMainWindow *mainWindow ,int length, int width, QString title, QString colour){

    mainWindow->setWindowTitle(title);
    mainWindow->resize(length,width);
    mainWindow->setStyleSheet("background-color: "+colour+";");
    mainWindow->setWindowIcon(QIcon(":/resources/icon/gpa_logo.png"));
    mainWindow->show();

}

   void createContainer( QWidget *centralWidget ,int length, int width, int positionX, int positionY, QString title, QString colour){

        QWidget* qWidget = new QWidget();

            qWidget->setParent(centralWidget);
            qWidget->resize(length, width);
            qWidget->move(positionX, positionY);
            qWidget->setToolTip(title);
            qWidget->setStyleSheet("background-color: "+colour+";");
            qWidget->show();

    }

};

#endif // CONTAINER_H
