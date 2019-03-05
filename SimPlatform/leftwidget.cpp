#include "leftwidget.h"
#include "ui_leftwidget.h"

leftwidget::leftwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::leftwidget)
{
    ui->setupUi(this);
}

leftwidget::~leftwidget()
{
    delete ui;
}
