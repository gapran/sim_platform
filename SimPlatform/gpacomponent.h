#ifndef STATLIB_H
#define STATLIB_H
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QListView>
#include <QString>

class GpaComponent
{

public:
    enum Colours{NORMAL,RED,GREEN ,YELLOW,BLUE,MAGENTA,CYAN,WHITE,RESET};
    GpaComponent();
    void mainView(QMainWindow *mW , QString s ,int l , int w , QString c);
    QWidget* newComponent(int w, int h, int posx, int posy, QBoxLayout* ql, QString color, QString ttp);
    QVBoxLayout* newVLayout();

};

#endif // STATLIB_H
