#include "mainwindow.h"
#include <QApplication>
#include "codeeditor.h"
#include "QWidget"
#include<database.h>
#include<iostream>
#include<sarifparser.h>
#include<error.h>

int main(int argc, char *argv[])
{
//    Database * db = new Database();
//    db->connect();

//    SarifParser * sarif = new SarifParser();
//    sarif->parse(* db);

//    list<Error> errors = db->getErrors();
//    list<Error>::iterator p = errors.begin();
//    while(p != errors.end())
//    {
//        cout <<"Message "<< p->message<<endl ;
//        p++;
//    }

    QApplication a(argc, argv);
    EditorWindow editor;
    editor.setWindowTitle(QObject::tr("Code Editor"));
    editor.showMaximized();

    return a.exec();
}
