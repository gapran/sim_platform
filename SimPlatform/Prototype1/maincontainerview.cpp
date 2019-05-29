#include "maincontainerview.h"
#include "ui_maincontainerview.h"
#include "container.h"
#include "codeeditor.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}
