#ifndef CONTAINER_H
#define CONTAINER_H

#include <QtWidgets>

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

    return mainWindow;

    }

    QWidget* createContainer(QBoxLayout* qBoxLayout, int length, int width, int positionX, int positionY, QString title, QString colour){

        QWidget* qWidget = new QWidget();
            qWidget->setLayout(qBoxLayout);
            qWidget->resize(length, width);
            qWidget->move(positionX, positionY);
            qWidget->setToolTip(title);
            qWidget->setStyleSheet("background-color: "+colour+";");
            return qWidget;

    }

};

#endif // CONTAINER_H
