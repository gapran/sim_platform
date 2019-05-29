#ifndef TABDIALOG_H
#define TABDIALOG_H
#include <QDialog>

class QTabWidget;

class GpaTab : public QWidget
{
    Q_OBJECT

public:
    explicit GpaTab(QWidget* contents, QWidget *parent = 0);
};

class TabDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TabDialog(const QString &title, QMap<QString, QWidget*> tabs, QWidget *parent = 0);

private:
    QTabWidget *tabWidget;
};

#endif
