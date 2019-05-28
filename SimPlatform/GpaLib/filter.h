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
    void createFilterHeader(QString text, int index);
    void createFilterList(QStringList valueList);

    // public:
    // signals:
    //    QList<QListWidgetItem *> filtersSelected();

private:
    QListWidget *listWidget;
};

#endif // FILTER_H
