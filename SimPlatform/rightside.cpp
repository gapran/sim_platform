#include "rightside.h"
#include "ui_rightside.h"

RightSide::RightSide(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RightSide)
{
    ui->setupUi(this);
}

RightSide::~RightSide()
{
    delete ui;
}
