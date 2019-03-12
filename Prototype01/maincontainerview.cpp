#include "maincontainerview.h"
#include "ui_maincontainerview.h"
#include "container.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *centralWidget = new QWidget (this);
    MainWindow::setCentralWidget(centralWidget );
}

MainWindow::~MainWindow()
{
    delete ui;
}
