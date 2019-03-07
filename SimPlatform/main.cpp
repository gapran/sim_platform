#include "gpalib.h"

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QtGui>

int main(int argc, char *argv[])
{


    QApplication app(argc, argv);

    //Create Main Container
    QWidget window;
        window.resize(900, 300);
        window.show();
        window.setWindowTitle(
            QApplication::translate("toplevel", "GPA Prototype"));


    return app.exec();

}
