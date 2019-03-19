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

class Text: public QDialog
{
    Q_OBJECT
public:
    explicit Text(QWidget *parent = 0);

    ~Text();

    void setText(QString text);
    void setTextSize(qreal size);
    void setFontFamily(QString family);
    void setFontUnderline(bool fontUnderline);
    void setFontItalic(bool fontItalic);
    void setTextColor(QString color);
    void setBackgroundColor(QString color);
    void setTextBold();
    void setHoverText(QString hoverText);
    void setClickable(QString link);

private:

    QTextEdit *textEdit;


};

#endif // TEXT_H
