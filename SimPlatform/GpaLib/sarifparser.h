#ifndef SARIFPARSER_H
#define SARIFPARSER_H
#include<QJsonDocument>
#include<iostream>
#include<database.h>
using namespace std;


class SarifParser
{
public:
    SarifParser();
    void  parse(Database db);
private:
    QJsonDocument doc;
    QString getDescription(QString ruleId, QJsonObject run);
    QString getLineNumber(QJsonObject analysisTarget);
    QString getLocation(QJsonObject analysisTarget);
    QJsonObject getAnalysisTarget(QJsonObject result);

};

#endif // SARIFPARSER_H
