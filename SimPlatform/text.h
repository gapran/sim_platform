#ifndef TEXT_H
#define TEXT_H

#include <QDialog>
#include<QTextEdit>
#include <QHBoxLayout>
#include<QString>
#include<QFont>
#include<QStyle>
#include<QSize>

class QTextEdit;

class TextElement: public QDialog
{
    Q_OBJECT
public:
    explicit TextElement(QWidget *parent = 0);

    ~TextElement();

    void setText(QString text);
    void setTextSize(qreal size);
    void setFontFamily(qreal family);
    void setFontUnderline(bool fontUnderline);
    void setFontItalic(bool fontItalic);
    void setTextColor(QString color);
    void setBackgroundColor(QString color);
    void setTextBold(bool textBold);

private:

    QTextEdit *textEdit;


};

#endif // TEXT_H
