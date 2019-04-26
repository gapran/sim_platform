#ifndef IMAGE_COPY_H
#define IMAGE_COPY_H

#include <QDialog>
#include <QHBoxLayout>
#include <QProgressBar>

using namespace std;
class Qlabel;

class Bar : public QDialog {
    Q_OBJECT
public:
    explicit Bar(QWidget *parent = nullptr, int min = 0, int max = 100);

    void setValue(int current) { bar->setValue(current); }
    void setText(QString text) { bar->setToolTip(text); }
    void updatable(bool value) {
        if (value == true) {
            bar->updatesEnabled();
        } else {
            bar->setUpdatesEnabled(false);
        }
    }

    void populate();

private:
    QProgressBar *bar;
};

#endif // IMAGE_COPY_H
