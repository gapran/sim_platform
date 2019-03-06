#include "statlib.h"


StatLib::StatLib()
{
}
void StatLib :: mainView(QMainWindow *mW , QString c ,int h , int w , QString color){
    mW->setWindowTitle(c);
    mW->resize(w,h);
    mW->setStyleSheet("background-color: "+color+";");
}
void StatLib :: leftWidget(QWidget *qW , QString c){
//    qW->resize(w,h);
    qW->setStyleSheet("background-color: "+c+";");
}
void StatLib :: rightWidget(QWidget *qW  , QString c){
//    qW->resize(w,h);
    qW->setStyleSheet("background-color: "+c+";");
}
