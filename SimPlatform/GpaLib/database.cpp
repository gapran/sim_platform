#include "database.h"
#include<QSqlRecord>
#include<QSqlDatabase>

Database::Database()
{
   db = QSqlDatabase::addDatabase("QSQLITE");


}
void Database::connect()
{
    db.setDatabaseName("GAPRAN.sqlite");
    db.open();

    if(!db.open())
        {
            qDebug()<<"Failed to connect"<<endl;
        }
    else {
        qDebug()<<"Connected .."<<endl;
    }

}

void Database::insertError(int id, string location, string message, string description, int start_line, int project_id, string program_line_of_code, string text_check_pannel ,string sarif_file_location, string way_to_fix, string element, string rule_id , int repitition)
{
    QSqlQuery qry;
    qry.prepare("Insert into Errors("
                "location, "
                "message, "
                "description, "
                "start_line, "
                "project_id, "
                "program_line_of_code, "
                "text_check_pannel, "
                "sarif_file_location, "
                "way_to_fix, "
                "element, "
                "rule_id, "
                "repitition) "
                "Values "
                "(?,?,?,?,?,?,?,?,?,?,?,?)");

    qry.addBindValue(location.data());
    qry.addBindValue(message.data());
    qry.addBindValue(description.data());
    qry.addBindValue(start_line);
    qry.addBindValue(project_id);
    qry.addBindValue(program_line_of_code.data());
    qry.addBindValue(text_check_pannel.data());
    qry.addBindValue(sarif_file_location.data());
    qry.addBindValue(way_to_fix.data());
    qry.addBindValue(element.data());
    qry.addBindValue(rule_id.data());
    qry.addBindValue(repitition);
    //qry.exec();

    if(!qry.exec())
    {
        qDebug()<<"Could not insert "<<endl;
    }
    else {
        qDebug()<<"Inserted errors"<<endl ;
    }



}

list<Error> Database::getErrors()
{
    QSqlQuery query;
    list<Error> errors;
    query.prepare("Select * from Errors");

    if( !query.exec() )
        qDebug() << "Could not execute"<<endl;
    else
    {
        qDebug( "Selected!" );
        QSqlRecord rec = query.record();
        while (query.next())
        {
            int id = query.value(rec.indexOf("id")).toInt();
            string location = query.value(rec.indexOf("location")).toString().toUtf8().data();
            string message = query.value(rec.indexOf("message")).toString().toUtf8().data() ;
            string description = query.value(rec.indexOf("description")).toString().toUtf8().data();
            int start_line = query.value(rec.indexOf("start_line")).toInt();
            int project_id = query.value(rec.indexOf("project_id")).toInt();
            string text_check_pannel = query.value(rec.indexOf("program_line_of_code")).toString().toUtf8().data();
            string sarif_file_location = query.value(rec.indexOf("sarif_file_location")).toString().toUtf8().data();
            string way_to_fix = query.value(rec.indexOf("way_to_fix")).toString().toUtf8().data();
            string element = query.value(rec.indexOf("element")).toString().toUtf8().data();
            int repition = query.value(rec.indexOf("repitition")).toInt();
            string program_line_of_code="";
            string rule_id = query.value(rec.indexOf("rule_id")).toString().toUtf8().data();
            Error error(id, location, message , description, start_line, project_id,program_line_of_code, text_check_pannel, sarif_file_location, way_to_fix, element, rule_id , repition);
            errors.push_back(error);
        }
    }

    return errors;
}
list<Error> Database::getFileErrors(string file)
{
    QSqlQuery query;
    list<Error> errors;
    query.prepare("Select * from Errors where instr(location, ?) > 0");
    query.addBindValue(file.data());

    if( !query.exec() )
        qDebug() << "Could not execute"<<endl;
    else
    {
        qDebug( "Selected!" );
        QSqlRecord rec = query.record();
        while (query.next())
        {
            int id = query.value(rec.indexOf("id")).toInt();
            string location = query.value(rec.indexOf("location")).toString().toUtf8().data();
            string message = query.value(rec.indexOf("message")).toString().toUtf8().data() ;
            string description = query.value(rec.indexOf("description")).toString().toUtf8().data();
            int start_line = query.value(rec.indexOf("start_line")).toInt();
            int project_id = query.value(rec.indexOf("project_id")).toInt();
            string text_check_pannel = query.value(rec.indexOf("program_line_of_code")).toString().toUtf8().data();
            string sarif_file_location = query.value(rec.indexOf("sarif_file_location")).toString().toUtf8().data();
            string way_to_fix = query.value(rec.indexOf("way_to_fix")).toString().toUtf8().data();
            string element = query.value(rec.indexOf("element")).toString().toUtf8().data();
            int repition = query.value(rec.indexOf("repitition")).toInt();
            string program_line_of_code="";
            string rule_id = query.value(rec.indexOf("rule_id")).toString().toUtf8().data();
            Error error(id, location, message , description, start_line, project_id,program_line_of_code, text_check_pannel, sarif_file_location, way_to_fix, element, rule_id , repition);
            errors.push_back(error);
        }
    }

    return errors;
}
