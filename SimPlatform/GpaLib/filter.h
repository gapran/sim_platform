#ifndef FILTER_H
#define FILTER_H

#include <QCheckBox>
#include <QList>
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

public slots:

    void getFiltersList();

private:
    QListWidget *listWidget;
};

#endif // FILTER_H
