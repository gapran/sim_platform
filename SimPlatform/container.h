#ifndef CONTAINER_H
#define CONTAINER_H

#include <QBoxLayout>
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

    QMainWindow* createMainContainer( QMainWindow *mainWindow ,int length, int width, QString title, QString colour){

    mainWindow->setWindowTitle(title);
    mainWindow->resize(length,width);
    mainWindow->setStyleSheet("background-color: "+colour+";");
    mainWindow->setWindowIcon(QIcon(":/resources/icon/gpa_logo.png"));

    return mainWindow;

    }

    QWidget* createContainer(int length, int width, int positionX, int positionY, QString title, QString colour){

        QWidget* qWidget = new QWidget();

            qWidget->resize(length, width);
            qWidget->move(positionX, positionY);
            qWidget->setToolTip(title);
            qWidget->setStyleSheet("background-color: "+colour+";");
            return qWidget;

    }

    /*
     * Method parameters:
     * 1. Provides view of Main Container
     * 2. Defines what kind of layout is required
     * 3. List of containers
     */
 void createLayout(QMainWindow *mainContainerView, QString layoutName, QWidgetList containerList){

        QWidget *centralWidget = new QWidget (mainContainerView);
        QVBoxLayout *widgetLayout = new QVBoxLayout(centralWidget);
        QHBoxLayout *mainLayout = new QHBoxLayout;
        QHBoxLayout *horizontalLayout1 = new QHBoxLayout;
        QVBoxLayout *verticalLayout1 = new QVBoxLayout;


        if( layoutName == "horizontalLayout"){

            for (int var = 0; var < containerList.size(); ++var) {
                horizontalLayout1->addWidget(containerList.at(var));
            }

            mainLayout->addLayout(horizontalLayout1);

            widgetLayout->addLayout(mainLayout);
            mainContainerView->setCentralWidget(centralWidget);


        } else if (layoutName == "verticalLayout") {

            for (int var = 0; var < containerList.size(); ++var) {
                verticalLayout1->addWidget(containerList.at(var));
            }

           mainLayout->addLayout(verticalLayout1);

           widgetLayout->addLayout(mainLayout);
           mainContainerView->setCentralWidget(centralWidget);


        } else {

            clog << "Please provide valid input." << endl;

        }


}
};

#endif // CONTAINER_H
