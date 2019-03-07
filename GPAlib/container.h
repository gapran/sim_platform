#ifndef CONTAINER_H
#define CONTAINER_H

#include <QtWidgets>

class Container{

private:
    int length;
    int width;
    QString layout;

public:
    void createContainer( int length, int width, QString layout){

    this->length = length;
    this->width = width;
    this->layout = layout;


    }

};

#endif // CONTAINER_H
