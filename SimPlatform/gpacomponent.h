#ifndef GPACOMPONENT_H
#define GPACOMPONENT_H
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QListView>
#include <QString>
#include <QAbstractItemView>
class GpaComponent
{
public:
    enum Colours{NORMAL,RED,GREEN ,YELLOW,BLUE,MAGENTA,CYAN,WHITE,RESET};
    GpaComponent();
    void main();
    void mainView(QMainWindow *mW , QString s ,int l , int w , QString c);
    QWidget* newComponent(int w, int h, int posx, int posy, QBoxLayout* ql, QString color, QString ttp);
    QVBoxLayout* newVLayout();
    void addView(QBoxLayout* qw, QAbstractItemView* view, int posx, int posy, QString ttp);
    void resize(QWidget* qw,int w, int h);
    void open(QWidget* qw);
    void close(QWidget* qw);
    void update(QWidget* qw , QBoxLayout* qblay , QAbstractItemView* view , int w, int h, int posx, int posy,QString color);
};

#endif // GPACOMPONENT_H
