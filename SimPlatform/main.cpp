#include "gpalib.h"

#include <QApplication>
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

    return app.exec();

}
