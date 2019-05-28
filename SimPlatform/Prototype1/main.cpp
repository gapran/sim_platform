#include "mainwindow.h"
#include <QApplication>
#include "codeeditor.h"
#include "QWidget"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EditorWindow editor;
    editor.setWindowTitle(QObject::tr("Code Editor"));
    editor.showMaximized();
//    editor.resize(640, 512);

     return a.exec();
}
