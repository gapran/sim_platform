#ifndef FILTER_H
#define FILTER_H

#include <QListWidget>

class Filter : public QListWidget {
    Q_OBJECT

public:
    Filter(QWidget *parent = nullptr);
    ~Filter();

    void createFilter(QString value);
    void createFilterHeader(QString text, int index);
    void createFilterList(QStringList valueList);

public slots:

    void getFiltersList();

private:
    QListWidget *listWidget;
};

#endif // FILTER_H
