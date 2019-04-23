#ifndef FILTER_H
#define FILTER_H

#include <QCheckBox>
#include <QLabel>

class Filter : public QLabel {
    Q_OBJECT

public:
    Filter(QWidget *parent = nullptr);
    ~Filter();

    void createFilterGroup();
    void createFilter(QString value);

private:
    QCheckBox *filter;
};

#endif // FILTER_H
