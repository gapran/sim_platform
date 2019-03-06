#include "text.h"

#include<iostream>
#include<vector>

using namespace std;

qreal textSize;
qreal font_family;

QString textColor;
QString textInput;
QString bgColor;

Text::Text(QWidget *parent) : QDialog (parent){


    textEdit = new QTextEdit;

    //Setting default text
    //setText("Default-Text");

    //Setting default text-size
    //setTextSize(NULL);

    //Setting default font-family
    //setFontFamily(NULL);

    //Setting default text-color
    setTextColor(NULL);

    //Setting default bg-color
    setBackgroundColor(NULL);

    setFontUnderline(false);
    setFontItalic(false);
    setTextBold(false);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(textEdit);

    setLayout(layout);

}

Text::~Text(){
    delete textEdit;
}

void Text:: setText(QString text)
{

        textEdit->setText(text); //Setting Input Text
}

void Text:: setTextSize(qreal textSize)
{
    if(QString::number(textSize).isNull())
    {
        textEdit->selectAll();
        textEdit->setFontPointSize(12); //Setting default text-size
    }
    else {
        textEdit->selectAll();
        textEdit->setFontPointSize(textSize); //Setting text-size
    }
}

void Text:: setFontFamily(qreal family)
{
    if(QString::number(family).isNull())
    {
        textEdit->selectAll();
        textEdit->setFontFamily("Times New Roman"); //Setting default font-family
    }
    else {
        textEdit->selectAll();
        textEdit->setFontFamily(QString::number(family)); //Setting font-family
    }
}

void Text:: setFontUnderline(bool fontUnderline)
{
    if(fontUnderline)
    {
        textEdit->setFontUnderline(true); //Setting font-style
    }
    else {
        textEdit->setFontUnderline(false);
    }
}

void Text:: setFontItalic(bool fontItalic)
{
    if(fontItalic)
    {
        textEdit->setFontItalic(true); //Setting font-style
    }
    else {
        textEdit->setFontItalic(false);
    }
}

void Text:: setTextColor(QString textColor )
{
    if(textColor.isNull())
    {
        textEdit->setTextColor("black");
    }
    else {
        textEdit->setTextColor(textColor);  //Setting font-color
    }
}

void Text:: setBackgroundColor(QString bgColor)
{
    if(bgColor.isNull())
    {
        textEdit->setTextBackgroundColor("white");
    }
    else {
        textEdit->setTextBackgroundColor(bgColor); //Setting bgColor
    }
}

void Text:: setTextBold(bool textBold)
{
    if(textBold)
    {
        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        textEdit->textCursor().mergeCharFormat(format);
    }
}

//void Text:: setHoverText(QString hoverText)
//{
//    QTextCursor cursor(textEdit->document());
//    textEdit->setTextCursor(cursor);
//    cursor.insertText(hoverText);
//}

//void Text:: setClickable(QString link)
//{
//    textEdit->selectAll();
//    QTextCursor cursor(textEdit->document());
//    textEdit->setTextCursor(cursor);
//    QTextCharFormat linkFormat = cursor.charFormat();
//    linkFormat.setAnchor(true);
//    linkFormat.setAnchorHref(link);
//}
