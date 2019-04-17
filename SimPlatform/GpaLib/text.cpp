#include "text.h"

#include<iostream>
#include<QLabel>
#include<vector>

qreal textSize;

QString font_family;
QString textColor;
QString textInput;
QString bgColor;

Text::Text(QWidget *parent) : QDialog (parent){


    textEdit = new QTextEdit;

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

void Text:: setFontFamily(QString family)
{
    if(family.isNull())
    {
        textEdit->selectAll();
        textEdit->setFontFamily("Times New Roman"); //Setting default font-family
    }
    else {
        textEdit->selectAll();
        textEdit->setFontFamily(family); //Setting font-family
    }
}

void Text:: setTextUnderline()
{

    textEdit->setFontUnderline(true); //Setting font-style

}

void Text:: setTextItalic()
{
    textEdit->setFontItalic(true); //Setting font-style

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

void Text:: setTextBold()
{
        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        textEdit->textCursor().mergeCharFormat(format);
}


void Text:: setClick(QString link)
{

    QTextCursor cursor(textEdit->document());
    textEdit->setTextCursor(cursor);
    cursor.insertHtml(link);
    textEdit->setTextInteractionFlags( Qt::TextEditorInteraction | Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard | Qt::LinksAccessibleByMouse | Qt::LinksAccessibleByKeyboard);

}

void Text:: setPopulate()
{
    textEdit->setText("dummy-text"); // Populates with dummy text
}

void Text:: setCancel()
{
    textEdit->clear(); // Clears the text present previously
}

QStringList Text:: setLinkTo(QWidget* widget, QString search)
{
    QStringList linkList;
    QString widgetName = widget->accessibleName();
    linkList.append(widgetName);
    linkList.append(search);
    return linkList; // this list now can be used by target view for further operation
}
