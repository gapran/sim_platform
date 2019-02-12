#include "dashboard.h"
#include "ui_dashboard.h"
#include <QMessageBox>

DashBoard::DashBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DashBoard)
{
    ui->setupUi(this);
}

DashBoard::~DashBoard()
{
    delete ui;
}

void DashBoard::on_actionInfo_triggered()
{
    QMessageBox::information(this, "About", "Add info here");
}
