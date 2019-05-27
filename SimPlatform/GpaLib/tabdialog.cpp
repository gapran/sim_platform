#include <QtWidgets>
#include "tabdialog.h"
#include"graphs.h"
#include "container.h"

TabDialog::TabDialog(const QString &fileName, QWidget *parent)
    : QDialog(parent)
{
    QFileInfo fileInfo(fileName);

    tabWidget = new QTabWidget;
    tabWidget->addTab(new AnalyiseTab(fileInfo), tr("Analyise"));
    tabWidget->addTab(new MonitorVisulizeTab(fileInfo), tr("Monitor & Visulize"));
    tabWidget->addTab(new CatogariseTab(fileInfo), tr("Catogarise"));
    tabWidget->addTab(new HighlightsTab(fileInfo), tr("Highlights"));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    setLayout(mainLayout);
    setWindowTitle(tr("Tab Dialog"));
}

AnalyiseTab::AnalyiseTab(const QFileInfo &fileInfo, QWidget *parent)
    : QWidget(parent)
{
    QLabel *fileNameLabel = new QLabel(tr("Add component here "));
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(fileNameLabel);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

MonitorVisulizeTab::MonitorVisulizeTab(const QFileInfo &fileInfo, QWidget *parent)
    : QWidget(parent)
{
    QGroupBox *permissionsGroup = new QGroupBox(tr("Add component for MonitorVisulize here"));
    QVBoxLayout *permissionsLayout = new QVBoxLayout;


    QWidget *graph = new QWidget();
    Graphs *barGraph = new Graphs(graph);
    QStringList names = {"Bronze", "Silver", "Gold", "Master","Proessional"};
    QStringList val = {"10", "50", "25", "80","65"};
    barGraph->drawBarGraph(5, names, val);
    Container container;
    container.createContainer(graph, barGraph, 400, 400, 80, 80, "This is hover for graph.", "white");

    permissionsGroup->setLayout(permissionsLayout);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(barGraph);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

CatogariseTab::CatogariseTab(const QFileInfo &fileInfo, QWidget *parent)
    : QWidget(parent)
{
    QLabel *topLabel = new QLabel(tr("Add component for Catogarisation here"));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(topLabel);
    setLayout(layout);
}

HighlightsTab::HighlightsTab(const QFileInfo &fileInfo, QWidget *parent)
    : QWidget(parent)
{
    QLabel *topLabel = new QLabel(tr("Add component for HighlightsTab here"));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(topLabel);
    setLayout(layout);
}
