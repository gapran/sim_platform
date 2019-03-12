#ifndef GPACOMPONENT_H
#define GPACOMPONENT_H

#include <QtWidgets>
#include <iostream>
#include <QIcon>

using namespace std;

class GpaComponent{

private:
    int length;
    int width;
    QString title;

public:

    void createMainComponent( QMainWindow *mainWindow ,int length, int width, QString title, QString colour){

    mainWindow->setWindowTitle(title);
    mainWindow->resize(length,width);
    mainWindow->setStyleSheet("background-color: "+colour+";");
    mainWindow->setWindowIcon(QIcon(":/resources/icon/gpa_logo.png"));
    mainWindow->show();

}

   void createComponent( QMainWindow *mainWindow ,int length, int width, int positionX, int positionY, QString title, QString colour){

            QWidget* qWidget = new QWidget();
            qWidget->setParent(mainWindow->centralWidget());
            qWidget->resize(length, width);
            qWidget->move(positionX, positionY);
            qWidget->setToolTip(title);
            qWidget->setStyleSheet("background-color: "+colour+";");
            qWidget->show();

    }

   void setChild( QWidget *presentWindow, QString child, QString parent){

       QWidget* childComponent = presentWindow->findChild<QWidget*>(child);
       QWidget* parentComponent = presentWindow->findChild<QWidget*>(parent);
      // childComponent->setParent(parentComponent);
   }

};

#endif // GPACOMPONENT_H
