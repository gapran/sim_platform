#ifndef FILTER_H
#define FILTER_H

#include <QDialog>

class QGroupBox;

class Filter : public QDialog {
    Q_OBJECT

public:
    Filter(QWidget *parent = nullptr);
    ~Filter();

    void createFilterGroup();

private:
    QDialog *filter;
};

#endif // FILTER_H
