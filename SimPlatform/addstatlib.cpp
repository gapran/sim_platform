#include "addstatlib.h"

addStatLib::addStatLib()
{

}
void addStatLib::ListView(QBoxLayout* qbw, QString ttp)
{
    QListView* lv = new QListView();
    qbw->addWidget(lv);
    lv->setToolTip(ttp);
}
