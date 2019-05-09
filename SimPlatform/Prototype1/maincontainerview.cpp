#include "maincontainerview.h"
#include "ui_maincontainerview.h"
#include "container.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Desired layout has be given here as a background image
    // Layout Examples: cli, ide, mobile, web
    // Replace the filename with desired layout name
    this->centralWidget()->setStyleSheet(
        "border-image:url(:/resources/icon/ide.jpg)0 0 0 0 stretch "
        "stretch;");
}

MainWindow::~MainWindow() {
    delete ui;
}
