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
     * 1. Defines what kind of layout is required
     * 2. List of containers
     */
    QBoxLayout* createLayout(QString layoutName, QWidgetList containerList){

        QBoxLayout *mainLayout = new QVBoxLayout;
        QHBoxLayout *horizontalLayout = new QHBoxLayout;

        if( layoutName == "horizontalLayout"){

            for (int var = 0; var < containerList.size(); ++var) {
                horizontalLayout->addWidget(containerList.at(var));
            }

            mainLayout->addLayout(horizontalLayout);

} return mainLayout; }


//        } else if (layoutName == "verticalLayout") {

//            QVBoxLayout *verticalLayout = new QVBoxLayout;
//            verticalLayout->addWidget(presentContainer);

//            QBoxLayout *mainLayout = new QBoxLayout;
//            mainLayout->addLayout(verticalLayout);

//            return mainLayout;


//        } else {

//            clog << "Please provide valid input." << endl;

//        }

 //   }

};

#endif // CONTAINER_H
