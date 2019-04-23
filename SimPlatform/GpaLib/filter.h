#ifndef FILTER_H
#define FILTER_H

#include <QCheckBox>
#include <QListWidget>

class Filter : public QListWidget {
    Q_OBJECT

public:
    Filter(QWidget *parent = nullptr);
    ~Filter();

    void createFilter(QString value);
    void createFilterList(QStringList valueList);

private:
    QListWidget *filterList;
};

#endif // FILTER_H
