#ifndef GPAVIEW_H
#define GPAVIEW_H
#include <QString>
#include <QMainWindow>

namespace Ui {
class GpaView;
}

class GpaView : public QMainWindow
{
    Q_OBJECT

public:
    explicit GpaView(QWidget *parent = nullptr);
    ~GpaView();
    QString title;
    QString default_background_color;
    QString default_foreground_color;
    QString leftwidget_color;
    QString Rightwidget_color;
    int font;
    int alignemnt;

private slots:
    void on_actionInfo_triggered();
    void on_actionchoose_color_triggered();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();

private:
    Ui::GpaView *ui;

};

#endif // GPAVIEW_H
