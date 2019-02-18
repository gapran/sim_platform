#include "leftwidget.h"
#include "ui_leftWidget.h"

LeftWidget::LeftWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeftWidget)
{
    ui->setupUi(this);
}

LeftWidget::~LeftWidget()
{
    delete ui;
}
