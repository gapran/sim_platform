#ifndef CODEEDITOR_H
#define CODEEDITOR_H
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QListView>
#include <QString>
#include <QAbstractItemView>
//for code editor
#include <QPlainTextEdit>
#include <QObject>
#include <QtGui>
//for highlighter
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>
#include <QtWidgets>
#include <QTextStream>
// for popup error elaboration
#include <QDialog>
#include <QTableWidget>
#include <QStringList>

class QDialogButtonBox;
class QFileInfo;
class QTabWidget;
////////////////////


class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
class LineNumberArea;
class CodeEditor;
class EditorWindow;
class QTextDocument;
class Highlighter;

class main
{
public:
    main();
};

class EditorWindow :public QMainWindow {
    Q_OBJECT
public:
    EditorWindow(QWidget *parent =0);
    void setupFileMenu();
public slots :
    void newFile();
    void save();
    void saveToFile();
    void openFile(const QString &path = QString());

private:
    CodeEditor *editor;
    QString currFile;
};
//code editor
class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeEditor(QWidget *parent = 0);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
    virtual ~CodeEditor();
protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);

    //highlighter
private:
    void setupEditor();
    void setupFileMenu();

    QTextEdit *editor;
    Highlighter *highlighter;
    QWidget *lineNumberArea;
    QWidget *MenulineNumberArea;
};

class LineNumberArea : public QWidget
{
public:

    LineNumberArea(CodeEditor *editor) : QWidget(editor) {
        codeEditor = editor;
    }

    QSize sizeHint() const {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }
protected:
    void paintEvent(QPaintEvent *event) {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor *codeEditor;
};

// highlighter
class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};
//tab for pop up

class TabDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TabDialog(const QString &fileName, QWidget *parent = 0);
   void  createUI(const QStringList &headers);
//   void setHeaders

private:
    QTabWidget *tabWidget;
//    QDialogButtonBox *buttonBox;
};
#endif // CODEEDITOR_H
