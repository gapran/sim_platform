#include "statlib.h"


StatLib::StatLib()
{
}
void StatLib :: mainView(QMainWindow *mW , QString c ,int h , int w , QString color){
    mW->setWindowTitle(c);
    mW->resize(w,h);
    mW->setStyleSheet("background-color: "+color+";");
}

QWidget* StatLib :: newComponent(int w, int h, int posx, int posy, QBoxLayout* qbl, QString color, QString ttp)
{
    QWidget* qw = new QWidget();
    qw->resize(w,h);
    qw->setLayout(qbl);
    qw->setStyleSheet("background-color: "+color+";");
    qw->move(posx,posy);
    qw->setToolTip(ttp);

    return qw;
}

QVBoxLayout* StatLib:: newVLayout()
{
    QVBoxLayout* vLayout = new QVBoxLayout();
    return vLayout;
}

void StatLib::addListView(QBoxLayout* qbw, QString ttp)
{
    QListView* lv = new QListView();
    qbw->addWidget(lv);
    lv->setToolTip(ttp);
}
