#ifndef DATABASE_H
#define DATABASE_H
#include<QtDebug>
#include<QFileInfo>
#include<QtSql>
#include<QTextStream>
#include<QFile>
#include<error.h>
#include<QSqlDatabase>
#include<QSqlQuery>

class Database
{
public:
    Database();
    void  connect();
    list<Error> getErrors();
    list<Error> getFileErrors(string file);
    void insertError(int id, string location, string message, string description, int start_line, int project_id, string program_line_of_code, string text_check_pannel , string sarif_file_location, string way_to_fix, string element, string rule_id , int repitition);
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
