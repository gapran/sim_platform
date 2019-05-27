#include<graphs.h>
#include<QtWidgets/QApplication>
#include<QtWidgets/QMainWindow>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QValueAxis>
#include<QtCharts/QChart>
#include<QDialog>
#include<QHBoxLayout>
#include<QtDebug>
#include <QtCharts/QLineSeries>

//using namespace QtCharts;
QT_CHARTS_USE_NAMESPACE

Graphs::Graphs(QWidget *parent) : QDialog (parent){

    chartView = new QChartView();
}

Graphs:: ~Graphs()
{
    delete  chartView;
}

void Graphs::drawBarGraph(QString title, QMap<QString, int> bars)
{
    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();

    for(QString barName : bars.keys())
    {
        QtCharts::QBarSet *set = new QtCharts::QBarSet(barName);
        *set << bars[barName];
        series->append(set);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(title);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    //QChartView *chartView = new QChartView(chart);
    chart->setMargins(QMargins(0,0,0,0));
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(chartView);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}
