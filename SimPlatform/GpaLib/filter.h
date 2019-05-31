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
    void createConnections();

public slots:

    void getFiltersList();
    void addCheckedHighlight(QListWidgetItem *item);

private:
    QListWidget *listWidget;
};

#endif // FILTER_H
