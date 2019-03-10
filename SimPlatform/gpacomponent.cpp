#include "gpacomponent.h"


GpaComponent::GpaComponent()
{
}
void GpaComponent :: mainView(QMainWindow *mW , QString c ,int h , int w , QString color){
    mW->setWindowTitle(c);
    mW->resize(w,h);
    mW->setStyleSheet("background-color: "+color+";");
}

QWidget* GpaComponent :: newComponent(int w, int h, int posx, int posy, QBoxLayout* qbl, QString color, QString ttp, QString font)
{
    QWidget* qw = new QWidget();
    qw->resize(w,h);
    qw->setLayout(qbl);
    qw->setStyleSheet("background-color: "+color+";");
    qw->move(posx,posy);
    qw->setToolTip(ttp);

    return qw;
}

QVBoxLayout* GpaComponent:: newVLayout()
{
    QVBoxLayout* vLayout = new QVBoxLayout();
    return vLayout;
}
void GpaComponent :: addView(QBoxLayout* qw, QAbstractItemView* view, int posx, int posy, QString ttp){
    qw->addWidget(view);
    view->move(posx,posy);
    view->setToolTip(ttp);
}
void GpaComponent :: resize(QWidget* qw,int w, int h){
     qw->resize(w,h);
}
void GpaComponent :: open(QWidget* qw){
    qw->show();
}
void GpaComponent :: close(QWidget*qw){
     qw->close();
}
void GpaComponent :: update(QWidget* qw , QBoxLayout* qblay , QAbstractItemView* view , int w, int h, int posx, int posy,QString color,QString font){
    if(view != nullptr){
        qblay->addWidget(view);
    }
    view->move(posx,posy);
    qw->setStyleSheet("background-color: "+color+";");
    qw->resize(w,h);
}
