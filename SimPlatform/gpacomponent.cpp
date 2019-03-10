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
void GpaComponent :: Resize(QResizeEvent *r_event){

}
void GpaComponent :: open(){

}
void GpaComponent :: close(QCloseEvent *c_event){

}
void GpaComponent :: Update(){

}
