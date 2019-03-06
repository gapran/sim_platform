#ifndef STATLIB_H
#define STATLIB_H
#include <QMainWindow>
#include <QWidget>

class StatLib
{

public:
    enum Colours{NORMAL,RED,GREEN ,YELLOW,BLUE,MAGENTA,CYAN,WHITE,RESET};
    StatLib();
    void mainView(QMainWindow *mW , QString s ,int l , int w , QString c);
    void leftWidget(QWidget *qW , QString c);
    void rightWidget(QWidget *qW , QString c);
};

#endif // STATLIB_H
