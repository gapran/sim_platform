#include "mainwindow.h"
#include <QApplication>
#include "codeeditor.h"
#include "QWidget"
#include "QPushButton"
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QTableView>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EditorWindow editor;
    editor.setWindowTitle(QObject::tr("Code Editor"));
    editor.showMaximized();
    editor.resize(640, 512);
    return a.exec();
}
