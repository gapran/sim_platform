#include <QtWidgets>
#include "tabdialog.h"
#include "container.h"

TabDialog::TabDialog(const QString &title, QMap<QString, QWidget*> tabs, QWidget *parent)
    : QDialog(parent)
{
    tabWidget = new QTabWidget;

    for(QString name : tabs.keys())
    {
        tabWidget->addTab(new GpaTab(tabs[name]), name);
    }

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    setLayout(mainLayout);
    setWindowTitle(title);
}

GpaTab::GpaTab(QWidget* contents, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(contents);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}
