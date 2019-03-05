#include "rightwidget.h"
#include "ui_rightwidget.h"

rightwidget::rightwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rightwidget)
{
    ui->setupUi(this);
}

rightwidget::~rightwidget()
{
    delete ui;
}
