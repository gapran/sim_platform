#ifndef GPACOMPONENT_H
#define GPACOMPONENT_H

#include <QtWidgets>
#include <iostream>
#include <QIcon>

using namespace std;

class GpaComponent{

private:

    QWidget* qWidget;
    int length;
    int width;
    QString title;
    QLayout* layout = new QHBoxLayout();

public:
    GpaComponent(){

    }
    void createMainContainer( QMainWindow *mainWindow ,int length, int width, QString title, QString colour){

        mainWindow->setWindowTitle(title);
        mainWindow->resize(length,width);
        mainWindow->setStyleSheet("background-color: "+colour+";");
        mainWindow->setWindowIcon(QIcon(":/resources/icon/gpa_logo.png"));
        mainWindow->show();

    }

    GpaComponent(QWidget* widget, int length, int width, QString title, QString colour){
//            qWidget = widget;
//            qWidget->resize(length, width);
//           // qWidget->move(positionX, positionY);
//            qWidget->setToolTip(title);
//            qWidget->setStyleSheet("background-color: "+colour+";");
//          // if(!qWidget->layout()) qWidget->setLayout(new QHBoxLayout());
//            qWidget->show();
//            std::cout << colour.toStdString() ;
            qWidget = widget;
            qWidget->setWindowTitle(title);
             qWidget->resize(length,width);
             qWidget->setStyleSheet("background-color: "+colour+";");
              qWidget->setWindowIcon(QIcon(":/resources/icon/gpa_logo.png"));
             qWidget->show();

    }

    GpaComponent( int length, int width, QString title, QString colour){
    GpaComponent(new QWidget(), length, width,title, colour);

    }

QBoxLayout* addChild(QMainWindow *mainContainerView, GpaComponent* childComponent, int x, int y){

         //    QWidget *centralWidget = new QWidget (mainContainerView);
          //   QVBoxLayout *widgetLayout = new QVBoxLayout(centralWidget);
             QHBoxLayout *mainLayout = new QHBoxLayout;

     QHBoxLayout *horizontalLayout1 = new QHBoxLayout;
     QWidget* child = childComponent->qWidget;
     child->move(x, y);
     horizontalLayout1->addWidget(child);

     mainLayout->addLayout(horizontalLayout1);
  //     widgetLayout->addLayout(mainLayout);
 //                mainContainerView->setCentralWidget(centralWidget);

     return mainLayout;
   }



};

#endif // GPACOMPONENT_H
