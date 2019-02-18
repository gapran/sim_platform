#include "gpaview.h"
#include "ui_gpaview.h"
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>

GpaView::GpaView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GpaView)
{

    ui->setupUi(this);
}

GpaView::~GpaView()
{
    delete ui;
}

void GpaView::on_actionInfo_triggered()
{
    QMessageBox::information(this, "About", "Add info here");
}
void GpaView::on_actionchoose_color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::yellow, this ); //to change color of widgets
}
void GpaView :: on_actionNew_triggered(){}
void GpaView :: on_actionExit_triggered(){}
void GpaView :: on_actionOpen_triggered(){}
