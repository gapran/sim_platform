#ifndef IMAGE_COPY_H
#define IMAGE_COPY_H

#include <QDialog>
#include<QProgressBar>
#include <QHBoxLayout>

using namespace std;
class Qlabel;

class Bar: public QDialog
{
    Q_OBJECT
public:
    explicit Bar(QWidget *parent = 0, int min = 0, int max = 100);

    void setValue(int current) {
        bar->setValue(current);
    }
    void setText(QString text) { bar->setToolTip(text); }
    void updatable(bool value) {
        if(value == true) {
            bar->updatesEnabled();
        }
    }

    void populate();
    void onChange(int value);

private:
    QProgressBar *bar;
};

#endif // IMAGE_COPY_H
