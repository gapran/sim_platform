#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "statlib.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    StatLib clib; // library
    ui->setupUi(this);
    clib.leftWidget((ui->left) , "grey");
    clib.rightWidget((ui->right), "grey");
    ui->splitter->setSizes(QList<int>() << 50 << 300); // left and right widget split sizes
}

MainWindow::~MainWindow()
{
    delete ui;
}
