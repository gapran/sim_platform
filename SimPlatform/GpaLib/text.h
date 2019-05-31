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
    explicit Text(QWidget *parent = nullptr);

    ~Text();

    void setText(QString text);
    void setTextSize(qreal size);
    void setFontFamily(QString family);
    void setTextUnderline();
    void setTextItalic();
    void setTextColor(QString color);
    void setBackgroundColor(QString color);
    void setTextBold();
    void setClick(QString link);
    void setPopulate();
    void setCancel();
    QStringList setLinkTo(QWidget* widget, QString search);
    void noBorder();

private:

    QTextEdit *textEdit;
};

#endif // TEXT_H
