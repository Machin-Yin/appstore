#include "mainwindow.h"
#include "appwidget.h"
#include <QLabel>
#include <QHeaderView>
#include <QPushButton>
#include <QGridLayout>
#include <QPalette>
#include <QDebug>

#define ROW_NUM 7

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    setupView();
    for(int i = 0; i < ROW_NUM; i++)
    {
        addRow(i);
    }
}
MainWindow::~MainWindow()
{

}

void MainWindow::setupView()
{
    resize(1200,900);
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(1);
    tableWidget->setRowCount(ROW_NUM);
    tableWidget->setColumnWidth(0,this->width()-450);
    tableWidget->setColumnWidth(1,450);
    tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    tableWidget->setFrameShape(QFrame::NoFrame);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setFocusPolicy(Qt::NoFocus);

    tableWidget->setShowGrid(false);
    tableWidget->setStyleSheet(
                "QTableWidget {"
                "background-color: white;"
                "}"
                "QTableWidget::item {"
                "border-top: 1px solid #dcdcdc;"
                "}"
                "QTableWidget::item:selected{"
                        "background:rgb(34, 175, 75);"
                  "}"
                );

    tableWidget->verticalHeader()->setDefaultSectionSize(96);
    tableWidget->horizontalHeader()->setStretchLastSection(true);

    QHeaderView* vheaderView = tableWidget->verticalHeader();
    vheaderView->setHidden(true);
    QHeaderView *hheaderView = tableWidget->horizontalHeader();
    hheaderView->setHidden(true);

    standardLayout = new QHBoxLayout() ;
    standardLayout->setMargin(0);
    standardLayout->addSpacing(16);
    standardLayout->addWidget(tableWidget);
    standardLayout->addSpacing(16);
    setLayout(standardLayout);
}

void MainWindow::addRow(int row)
{
    AppWidget* appWidget = new AppWidget();
    tableWidget->setCellWidget(row,0,appWidget);

//    QLabel *svbLabel = new QLabel();
//    QHBoxLayout *rowLayout = new QHBoxLayout();
//    rowLayout->setMargin(0);
//    tableWidget->setCellWidget(row,1,svbLabel);
//    svbLabel->setLayout(rowLayout);

//    QLabel *sizeLabel = new QLabel();
//    sizeLabel->resize(16,64);
//    sizeLabel->setText(tr("13.8M"));

//    QLabel *versionLabel = new QLabel();
//    versionLabel->setText(tr("V7.0.0"));

//    rowLayout->addStretch();
//    QPushButton *updateButton = new QPushButton();
//    updateButton->setFixedSize(80,32);
//    QPalette pal;
//    pal.setColor(QPalette::ButtonText, QColor(2,122,255));
//    updateButton->setPalette(pal);
//    updateButton->setStyleSheet("border: 1px solid #027aff  ; border-radius: 2px; ");
// //    updateButton->setStyleSheet("border-color: #027aff; border-width: 1px; border-style: solid; border-radius: 2px; ");
//    updateButton->setText(tr("update"));

//    rowLayout->addWidget(sizeLabel);
//    rowLayout->addSpacing(112);
//    rowLayout->addWidget(versionLabel);
//    rowLayout->addSpacing(112);
//    rowLayout->addWidget(updateButton);

//    updateButton->setProperty("row", row);
//    connect(updateButton,SIGNAL(clicked()),this,SLOT(on_update_licked()));
}

void MainWindow::on_update_licked()
{
    QPushButton *btn = (QPushButton *) sender();
    clicked_row = btn->property("row").toInt();
    qDebug() << "clicked_row = " << clicked_row;
    getAppWidget();
    tableWidget->removeRow(clicked_row);
}

//void MainWindow::on_newfun_clicked()
//{

//}

void MainWindow::getAppWidget()
{
    AppWidget *curAppWidget = (AppWidget *)tableWidget->cellWidget(clicked_row,0);
    qDebug() << "curAppWidget->nameButton->text()" << curAppWidget->nameButton->text();
}


