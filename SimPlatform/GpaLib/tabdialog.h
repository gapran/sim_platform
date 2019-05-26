#ifndef TABDIALOG_H
#define TABDIALOG_H
#include <QDialog>

class QDialogButtonBox;
class QFileInfo;
class QTabWidget;

class AnalyiseTab : public QWidget
{
    Q_OBJECT

public:
    explicit AnalyiseTab(const QFileInfo &fileInfo, QWidget *parent = 0);
};

class MonitorVisulizeTab : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorVisulizeTab(const QFileInfo &fileInfo, QWidget *parent = 0);
};

class CatogariseTab : public QWidget
{
    Q_OBJECT

public:
    explicit CatogariseTab(const QFileInfo &fileInfo, QWidget *parent = 0);
};

class HighlightsTab : public QWidget
{
    Q_OBJECT

public:
    explicit HighlightsTab(const QFileInfo &fileInfo, QWidget *parent = 0);
};

class TabDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TabDialog(const QString &fileName, QWidget *parent = 0);

private:
    QTabWidget *tabWidget;
};

#endif
