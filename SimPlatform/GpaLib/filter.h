#ifndef FILTER_H
#define FILTER_H

#include <QCheckBox>
#include <QLabel>

class Filter : public QLabel {
    Q_OBJECT

public:
    Filter(QWidget *parent = nullptr, QString value = "default");
    ~Filter();

    void createFilter(QString value);
    void createFilterList(QStringList valueList);

private:
    QCheckBox *filter;
};

#endif // FILTER_H
