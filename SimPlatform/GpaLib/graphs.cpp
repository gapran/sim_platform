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

//    //chartView = new QtCharts::QChartView();
//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(chartView);
//    setLayout(layout);

    QString var = "hello";
    qDebug()<<var;
}

void Graphs::drawBarGraph(int num, QStringList names, QStringList values)
{
    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();

    for (int i=0;i<num;i++)
        {
            QtCharts::QBarSet *set = new QtCharts::QBarSet(names[i]);

            *set << values[i].toInt();

            series->append(set);
        }

//        QtCharts::QBarSet *set0 = new QtCharts::QBarSet("Bronze");
//        *set0 << 10;
//        QtCharts::QBarSeries *series = new QtCharts::QBarSeries();
//        series->append(set0);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Barchart");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,100);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(chartView);
        setLayout(layout);


}

void Graphs::drawLineGraph(int num, QStringList valx, QStringList valy)
{

    QLineSeries *series = new QLineSeries();

    for (int i=0;i<num;i++)
        {
        int x= valx[i].toInt();
        int y= valy[i].toInt();
         series->append(x,y);
        }

         QChart *chart = new QChart();
         chart->legend()->hide();
         chart->addSeries(series);
         chart->createDefaultAxes();
         chart->setTitle("Line Chart");

         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);

         QHBoxLayout *layout = new QHBoxLayout;
         layout->addWidget(chartView);
         setLayout(layout);

}
