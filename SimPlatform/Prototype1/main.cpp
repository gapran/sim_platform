#include "codeeditor.h"
#include "QWidget"
#include "bar.h"
#include "container.h"
#include "graphs.h"
#include "image.h"
#include "layout.h"
#include "maincontainerview.h"
#include "tabdialog.h"
#include "table.h"
#include "text.h"
#include <QApplication>
#include <QBoxLayout>
#include <QDebug>
#include <QHBoxLayout>
#include <QLayout>
#include <QPushButton>
#include <QTextBrowser>
#include <QTextEdit>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    qDebug() << "Welcome to GPA Prototype Builder!";
    MainWindow mainContainerView;

    /** User Code starts here... **/

    QString mainTitle = "GPA Prototype";
    int mainContainerLength = 1200;
    int mainContainerWidth = 700;
    QString mainColour = "white";

    // Create main GpaComponent / window
    Container container;
    container.createMainContainer(&mainContainerView, mainContainerLength,
                                  mainContainerWidth, mainTitle, mainColour);

    // Create layout
    QWidget *layoutWidget = new QWidget(mainContainerView.centralWidget());
    Layout *layoutMobile = new Layout(layoutWidget);
    // layoutMobile->setMobile();
    // layoutMobile->setWeb();
    layoutMobile->setIDE();
    // layoutMobile->setCLI();

    container.createContainer(mainContainerView.centralWidget(), layoutMobile,
                              mainContainerLength, mainContainerWidth, 0, 0,
                              "This is layout.", "white");

    // Create inner containers

    // GPA Issue 4 - Table implementation
    Table *table1 = new Table(mainContainerView.centralWidget());

    // Create Table with rows and columns
    table1->createTable(7, 7);

    QStringList tableHeadersList = {"Name",       "Status",    "Progress",
                                    "Start date", "Last date", "Description",
                                    "Action"};
    table1->addTableHeaders(tableHeadersList);

    QStringList insertNameColumn = {"Alex", "John",  "Mike", "Bob",
                                    "Max",  "Sarah", "Cindy"};
    table1->addTableNameColumns(insertNameColumn);

    QStringList insertStatusColumn = {"fixed",  "working", "not fixed",
                                      "fixed",  "fixed",   "not fixed",
                                      "working"};
    table1->addTableStatusColumns(insertStatusColumn);

    QStringList insertStartDateColumn = {
        "16-02-2019", "16-02-2019", "15-02-2019", "15-02-2019",
        "15-02-2019", "14-02-2019", "15-02-2019"};
    table1->addTableStartDateColumns(insertStartDateColumn);

    QStringList insertLastUpdateColumn = {
        "17-02-2019", "18-02-2019", "16-02-2019", "17-02-2019",
        "17-02-2019", "18-02-2019", "18-02-2019"};
    table1->addTableLastUpdateColumns(insertLastUpdateColumn);

    QStringList insertDescriptionColumn = {"des1", "des2", "des3", "des4",
                                           "des5", "des6", "des7"};
    table1->addTableDescriptionColumns(insertDescriptionColumn);

    QStringList insertActionColumn = {"action1", "action2", "action3",
                                      "action4", "action5", "action6",
                                      "action7"};
    table1->addTableActionColumns(insertActionColumn);

    // Update a certain cell in a table with a certain row id and column
    // table1->updateTable(2, 1, "fixed");

    // Filter the table: Column name and Filter keyword
    // table1->applyFilter("Status", "not fixed");

    // Apply border width and color for Table window
    // QStringList insertBorderStyle = {"1px", "blue"};
    // table1->applyBorderWidthColor(insertBorderStyle);

    // Search on Column ID
    // table1->findColumn("Action");

    // When the user presses a column header then sorting happens.
    // table1->sort(true);

    container.createContainer(mainContainerView.centralWidget(), table1, 700,
                              200, 150, 70, "Table Container", "gray");

    // Text
    QWidget *textWidget = new QWidget(mainContainerView.centralWidget());
    Text *text = new Text(textWidget);

    // Text Styles
    text->setFontFamily("Georgia");
    text->setTextSize(10);
    // text->setTextItalic();
    // text->setTextUnderline();
    text->setTextBold();
    // text->setTextColor("blue");
    text->setBackgroundColor("white");
    text->noBorder();

    text->setText("Bronze");
    // QString link = "<a href=\"www.example.de\bronze\">Bronze</a>";
    // text->setClick(link);

    container.createContainer(mainContainerView.centralWidget(), text, 100, 100,
                              40, 180, "This is hover for this text box.",
                              "white");

    // Image
    QWidget *image1Widget = new QWidget(mainContainerView.centralWidget());
    Image *image1 = new Image(image1Widget);
    QString filename = ":/resources/icon/bronze_image.jpg";
    image1->setImage(filename);
    image1->setBox();
    image1->setHover("This is Bronze Image.");
    image1->noBorder();
    //  image1->clicked();

    container.createContainer(mainContainerView.centralWidget(), image1, 100,
                              100, 30, 90, "This is hover for image.", "white");

    // Progress bar
    QWidget *imageCopy1Widget = new QWidget(mainContainerView.centralWidget());
    Bar *bar = new Bar(imageCopy1Widget, 0, 100);
    bar->setValue(60);
    container.createContainer(mainContainerView.centralWidget(), bar, 100, 100,
                              40, 220, "", "white");

    // Tabs
    QWidget *genrarltabWidget = new QWidget(mainContainerView.centralWidget());

    QLabel *labelAnalyze = new QLabel("Analysis results");
    QLabel *labelMonitor = new QLabel("Monitor functionalities");
    QLabel *labelCategorize = new QLabel("Categorize functionalities");
    QLabel *labelHighlights = new QLabel("Highlights information");

    QMap<QString, QWidget *> tabs;
    tabs.insert("Analyze", labelAnalyze);
    tabs.insert("Monitor and visualize", labelMonitor);
    tabs.insert("Categorize", labelCategorize);
    tabs.insert("Highlights", labelHighlights);

    TabDialog *tabdialog = new TabDialog("Tabs", tabs, genrarltabWidget);
    container.createContainer(mainContainerView.centralWidget(), tabdialog, 800,
                              360, 150, 270,"This is hover for tabs.", "white");

    // Graphs
    QWidget *graph = new QWidget();
    Graphs *barGraph = new Graphs(graph);
    QMap<QString, int> bars;
    bars.insert("Bronze", 10);
    bars.insert("Silver", 50);
    bars.insert("Gold", 25);
    bars.insert("Master", 80);
    bars.insert("Professional", 65);
    barGraph->drawBarGraph("Bar chart", bars);
    container.createContainer(mainContainerView.centralWidget(), barGraph, 700,
                              200, 200, 425, "This is hover for graph.", "white");
    EditorWindow editor;
    editor.setWindowTitle(QObject::tr("Code Editor"));
//    editor.showMaximized();

    /** User code ends here... **/

    mainContainerView.show();
    return app.exec();
}
