#include "sarifparser.h"
#include<QJsonDocument>
#include<QFile>
#include<QJsonObject>
#include<QtDebug>
#include<QJsonArray>
#include<iostream>
#include<error.h>
#include<database.h>
#include<string>
using namespace std;

SarifParser::SarifParser()
{
    QString val;
    QFile file;
    file.setFileName("C:/Users/Rashmi/Documents/GAPRAN/db_utils/scan_results/sarif/findbugsXmltosarif.sarif");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    doc = QJsonDocument::fromJson(val.toUtf8());


}

void SarifParser::parse(Database db)
{
     QJsonObject jObject = doc.object();
     string location="";
     string message;
     string description;
     string start_line;
     int project_id=1;
     string sarif_file_location="";
     int id;
     string error_id;
     string text_check_pannel="";
     string way_to_fix="";
     string element="";
     int repitition=0;

     QJsonArray runs = jObject["runs"].toArray();

     QJsonObject run = runs.at(0).toObject();

     QJsonObject files = run["files"].toObject();
     QJsonArray results = run["results"].toArray();

     std::string pro_id_string = std::to_string(project_id);



     cout<<"Size of results"<<results.size();

     for(int j=0;j<results.size();j++)
     {
         QJsonObject result = results.at(j).toObject();
         QString ruleId = result["ruleId"].toString();
         QString qmessage = result["message"].toString();
         QString qdescription = getDescription(ruleId, run);
         QJsonObject analysisTarget = getAnalysisTarget(result);
         QString qline_number = getLineNumber(analysisTarget);
         QString qlocation = getLocation(analysisTarget);
         location = qlocation.toUtf8().constData();
         message = qmessage.toUtf8().constData();
         description = qdescription.toUtf8().constData();
         start_line = qline_number.toUtf8().constData();
         string program_line_of_code ="";


         cout<<"Line Number"<<start_line<<endl;

         int line_number = stoi(start_line);

         //std::string s = std::to_string(j);
         //error_id = error_id+"_"+s ;


         cout<<"Value of id"<<j<<endl;

         db.insertError(j,location,message,description,line_number,project_id,program_line_of_code,text_check_pannel,sarif_file_location,way_to_fix,element,repitition);




     }

}

QString SarifParser::getLineNumber(QJsonObject analysisTarget)
{
   QJsonObject region = analysisTarget["region"].toObject();
   QString line_number = region["startLine"].toString();
   return line_number;

}
QString SarifParser::getLocation(QJsonObject analysisTarget)
{
    QString location = analysisTarget["uri"].toString();
    return location;
}

QJsonObject SarifParser::getAnalysisTarget(QJsonObject result)
{
    QJsonArray locArray = result["locations"].toArray();
    QJsonObject locations = locArray.at(0).toObject();
    QJsonObject analysisTarget = locations["analysisTarget"].toObject();

    return analysisTarget;
}

QString SarifParser::getDescription(QString ruleId, QJsonObject run)
{
    QString description ;

    QJsonObject ruleObj = run["rules"].toObject();
    QJsonObject rules = ruleObj["rules"].toObject();
    QJsonObject findDescription = rules[ruleId].toObject();

    description = findDescription["description"].toString();
    return description;
}
