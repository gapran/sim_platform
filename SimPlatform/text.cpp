#include "text.h"

#include<iostream>
#include<QLabel>
#include<vector>

using namespace std;

qreal textSize;

QString font_family;
QString textColor;
QString textInput;
QString bgColor;

Text::Text(QWidget *parent) : QDialog (parent){


    textEdit = new QTextEdit;

    //Setting default text
    setText("Default-Text");

    //Setting default text-size
    setTextSize(12);

    //Setting default font-family
    setFontFamily("Times New Roman");

    //Setting default text-color
    setTextColor("black");

    //Setting default bg-color
    setBackgroundColor("white");

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

void Text:: setHoverText(QString hoverText)
{

//   QTextCursor cursor(textEdit->document());
//    textEdit->setTextCursor(cursor);
//    cursor.insertText(hoverText);
//   textEdit->setStyleSheet("QLabel { background-color : red; }");
//   textEdit->toolTip() = hoverText;
//   QMouseEvent *e;
//    textEdit->mousePressEvent(&e);
//    cursor.insertText(hoverText);
}

void Text:: setClick(QString link)
{

//    QLabel label;
//    label.setOpenExternalLinks(true);
//    label.setText("<a href=" + link + ">click here</a>");



//   // QString previousText = textEdit->s;
//    QString textLink = "<a href='http://" + link + "'>" + previousText + "</a>";
//    textEdit->setText(textLink);
//    QLabel* myLabel;
//    myLabel->setText("<a href=\"http://example.com/\">Click Here!</a>");
//    myLabel->setTextFormat(Qt::RichText);
//    myLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
//    myLabel->setOpenExternalLinks(true);

    textEdit->selectAll();
    QTextCursor cursor(textEdit->document());

    QString text = textEdit->document()->toPlainText();
   // textEdit->setTextCursor(cursor);
   // textEdit->setText("click here");
    QTextCharFormat linkFormat = cursor.charFormat();
    linkFormat.setAnchor(true);
    linkFormat.setAnchorHref(link);
    linkFormat.anchorName() = "hello";
    textEdit->clear();
    cursor.insertText(text, linkFormat);

   // textEdit->setText();


//    textEdit->textCursor().mergeCharFormat( linkFormat );
  //  textEdit->textCursor().mergeCurrrentCharFormat( linkFormat );

//   QString test = " Text {
//        anchors.centerIn: parent
//        text: " UPB, <a href='http://www.upb.de'>click here</a>"
//        onLinkActivated: Qt.openUrlExternally(link)

//        MouseArea {
//            anchors.fill: parent
//            acceptedButtons: Qt.NoButton
//            cursorShape: parent.hoveredLink ? Qt.PointingHandCursor : Qt.ArrowCursor
//        }
//    } "
}
