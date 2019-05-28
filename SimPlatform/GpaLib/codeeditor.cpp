#include "codeeditor.h"
//code editor implementation
CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    setupEditor();
    lineNumberArea = new LineNumberArea(this);
    errorArea = new ErrorArea(this);

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateErrorAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateErrorArea(QRect,int)));
    updateErrorAreaWidth(0);
    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
}

CodeEditor::~CodeEditor(){}

int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }
    int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;
    return space;
}

int CodeEditor:: errorAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;
    return space;
}


void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth()+errorAreaWidth(), 1, 0, 0);
}

void CodeEditor::updateErrorAreaWidth(int /* newBlockCount */)
{
//    setViewportMargins(errorAreaWidth() + lineNumberAreaWidth(), 15, 0, 0);
}



void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->height(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

void CodeEditor::updateErrorArea(const QRect &rect, int dy)
{
    if (dy)
        errorArea->scroll(0, dy);
    else
        errorArea->update(0, rect.y(), errorArea->height(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateErrorAreaWidth(0);
}

void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);
    QRect cr = contentsRect();
    QRect lna = QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height());
    lineNumberArea->setGeometry(lna);
    QRect ra = QRect(lna.right(), lna.top(), errorAreaWidth(), lna.height());
    errorArea->setGeometry(ra);
}

void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;
        QColor lineColor = QColor(Qt::green).lighter(160);
        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}
void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = int (blockBoundingGeometry(block).translated(contentOffset()).top());
    int bottom = top + int (blockBoundingRect(block).height());
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + int (blockBoundingRect(block).height());
        ++blockNumber;
    }
}

void CodeEditor::errorAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(errorArea);
    errPainter = &painter;
    painter.fillRect(event->rect(), Qt::gray);
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = int (blockBoundingGeometry(block).translated(contentOffset()).top());
    int bottom = top + int (blockBoundingRect(block).height());

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            if(number == "18"){
                painter.setPen(Qt::red);
                painter.fillRect(0,top, errorArea->width(), fontMetrics().height(), Qt::yellow);
            }
            else {
                painter.setPen(Qt::gray);
                painter.drawText(0, top, errorArea->width(), fontMetrics().height(),
                                 Qt::AlignRight, number);
            }
        }

        block = block.next();
        top = bottom;
        bottom = top + int (blockBoundingRect(block).height());
        ++blockNumber;
    }
}

void CodeEditor::showError(int lineNum)
{
    errPainter->setPen(Qt::red);
    errPainter->drawText(0, lineNum, errorArea->width(),fontMetrics().height(), Qt::AlignRight, "0");
}

//higlighter implementation for code editor
Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bchar\\b" << "\\bclass\\b" << "\\bconst\\b"
                    << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b"
                    << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b"
                    << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b"
                    << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
                    << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b"
                    << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
                    << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
                    << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                    << "\\bvoid\\b" << "\\bvolatile\\b" << "\\bbool\\b";
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegularExpression("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(Qt::red);
    rule.pattern = QRegularExpression("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::red);

    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegularExpression("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegularExpression("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegularExpression("/\\*");
    commentEndExpression = QRegularExpression("\\*/");
}

void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

    while (startIndex >= 0) {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}
void CodeEditor::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);
    editor = new QTextEdit;
    editor->setFont(font);
    highlighter = new Highlighter(this->document());
    QFile file("codeeditor.h");
    if (file.open(QFile::ReadOnly | QFile::Text))
        editor->setPlainText(file.readAll());

}
//editor Window
EditorWindow::EditorWindow(QWidget *parent): QMainWindow (parent){
    setupFileMenu();
    currFile.clear();
    layoutSetup();
}
void EditorWindow :: layoutSetup(){
    editor=new CodeEditor();
    QSplitter *mainsplitter = new QSplitter(Qt::Vertical);
    QSplitter *splitter_ver = new QSplitter(Qt::Vertical);
    splitter_ver->addWidget(editor);
    //for test
    listWidget = new QListWidget;

       for(int i = 0; i < 10; i++){
           listWidget->addItem("Bug number " + QString::number(i));
       }
       QStringList list ;
       list.push_back("text in the check pannel");
       list.push_back("Cause Of Error");
       list.push_back("Element/Activity");
       list.push_back("Way To Fix");
       list.push_back("Repitition");
       QTableWidget *tableWidget = new QTableWidget;
       tableWidget->setColumnCount(5);
       tableWidget->setShowGrid(true);
       tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
       tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
       tableWidget->setHorizontalHeaderLabels(list);
       tableWidget->horizontalHeader()->setStretchLastSection(true);

    QSplitter *splitterhor = new QSplitter(Qt::Horizontal);
    splitterhor->addWidget(listWidget);
    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
        this, SLOT(itemClicked(QListWidgetItem*)));
    splitterhor->addWidget(tableWidget);
    mainsplitter->addWidget(splitter_ver);
    mainsplitter->addWidget(splitterhor);
    setCentralWidget(mainsplitter);
}
void EditorWindow::itemClicked(QListWidgetItem* item)
{
    qDebug("Item Clicked: " + item->text().toLatin1());
    item->setTextColor(Qt::black);
    item->setBackgroundColor(Qt::yellow);
    int ln=18;
    QTextCursor cursor(editor->document()->findBlockByLineNumber(ln-1)); // ln-1 because line number starts from 0
    editor->setTextCursor(cursor);
}

void EditorWindow::setupFileMenu()
{
    QMenu *fileMenu = new QMenu(tr("&File"), this);
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction(tr("&New"), this, SLOT(newFile()), QKeySequence::New);
    fileMenu->addAction(tr("&Open..."), this, SLOT(openFile()), QKeySequence::Open);
    fileMenu->addAction(tr("&Save as"),this, SLOT(saveToFile()), QKeySequence::SaveAs);
    fileMenu->addAction(tr("&Save"),this, SLOT(save()), QKeySequence::Save);
}
void EditorWindow::openFile(const QString &path)
{
    QString fileName = path;

    if (fileName.isNull())
    {
        fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "C++ Files (*.cpp *.h)");
        qDebug()<<fileName;
        currFile = fileName;
    }

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text))
            editor->setPlainText(file.readAll());
    }
}

void EditorWindow::newFile()
{
    currFile.clear();
    editor->clear();
}

void EditorWindow::saveToFile()
{
    QString nomeFile = QFileDialog::getSaveFileName(this, tr("Save the File"), "",
                                                        tr("Text File(*.txt);;C++ File (*.cpp *.h)"));
        if (nomeFile != "") {
            QFile file(nomeFile);

            if (file.open(QIODevice::ReadWrite)) {
                QTextStream stream(&file);
                stream << editor->document()->toPlainText();
                file.flush();
                file.close();
            }
            else {
                QMessageBox::critical(this, tr("Error"), tr("can't save the file"));
                return;
            }
        }
}

void EditorWindow::save()
{
    if(currFile.isEmpty())
        saveToFile();
    else {
        QFile file(currFile);
            if (file.open(QIODevice::WriteOnly)) {
                QTextStream stream(&file);
                stream << editor->document()->toPlainText();
                file.flush();
                file.close();
            }
            else {
                QMessageBox::critical(this, tr("Error"), tr("can't save the file"));
                return;
            }
    }
}
