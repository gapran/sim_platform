#ifndef GRAPHS_H
#define GRAPHS_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include<QDialog>


class Graphs : public QDialog
{
    Q_OBJECT

public:
    explicit Graphs(QWidget *parent = nullptr);

     void drawBarGraph(int num, QStringList list, QStringList values);
     void drawLineGraph(int num, QStringList valx, QStringList valy);

private:
     QtCharts::QChartView *chartView;
};

#endif // GRAPHS_H

