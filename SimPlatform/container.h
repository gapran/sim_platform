#ifndef CONTAINER_H
#define CONTAINER_H

#include <QtWidgets>

class Container{

private:
    int length;
    int width;
    QString title;

public:
    void createMainContainer( int length, int width, QString title){

    this->length = length;
    this->width = width;
    this->title = title;

        // Pass the values in widget creation and later pass all widgets to a list
        //then a function like UI-Builder will create widgets in an application.


    }

};

#endif // CONTAINER_H
