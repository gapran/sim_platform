#include "gpalib.h"

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QtGui>

int main(int argc, char *argv[])
{

    // Test the library linked
    GPAlib gpaLib;
    gpaLib.Test();

    QApplication app(argc, argv);

    //Create Main Container
    QWidget window;
        window.resize(900, 300);
        window.show();
        window.setWindowTitle(
            QApplication::translate("toplevel", "GPA Prototype"));

        //Create Child Widget
        QPushButton *button = new QPushButton(
                QApplication::translate("toplevel", "Press me"), &window);
            button->move(100, 100);
            button->show();

    return app.exec();

}
