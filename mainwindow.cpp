#include "mainwindow.h"
#include "appwidget.h"
#include <QLabel>
#include <QHeaderView>
#include <QPushButton>
#include <QGridLayout>
#include <QPalette>
#include <QDebug>
#include <funcwidget.h>

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
    resize(960,640);
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(1);
    tableWidget->setRowCount(ROW_NUM);
    tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tableWidget->setFrameShape(QFrame::NoFrame);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setFocusPolicy(Qt::NoFocus);
    tableWidget->resizeColumnToContents (0);
    tableWidget->setShowGrid(false);
    tableWidget->setStyleSheet(
                "QTableWidget {"
                "background-color: white;"
                "}"
                "QTableWidget::item {"
                "border-top: 1px solid #dcdcdc;"
                "}"
                "QTableWidget::item:selected{"
                "background:white;"
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
    qDebug() << "appWidget->introLabel->sizeHint()" << appWidget->introLabel->sizeHint();

    connect(appWidget->headButton,SIGNAL(clicked()),this,SLOT(on_button_clicked()));
    connect(appWidget->nameButton,SIGNAL(clicked()),this,SLOT(on_button_clicked()));
    connect(appWidget->funcButton,SIGNAL(clicked()),this,SLOT(on_button_clicked()));
    connect(appWidget->updateButton,SIGNAL(clicked()),this,SLOT(on_button_clicked()));
    connect(appWidget,SIGNAL(sigintrofm()),this,SLOT(strLenChanged()));
}

void MainWindow::on_button_clicked()
{
    for(int i = 0; i < tableWidget->rowCount(); i++)
    {
        AppWidget* appWidget = (AppWidget*)tableWidget->cellWidget(i,0);

        if(sender() == appWidget->headButton )
        {
            qDebug() << "btn == headButton:" << "row == " << i;
            break;
        }
        else if(sender() == appWidget->nameButton)
        {
            qDebug() << "btn == nameButton:" << "row == " << i;
            break;
        }
        else if(sender() == appWidget->funcButton)
        {
            qDebug() << "btn == funcButton:" << "row == " << i;
            tableWidget->insertRow(i+1);

            FuncWidget *nfuncWidget = new FuncWidget();
            tableWidget->setCellWidget(i+1,0,nfuncWidget);
            int textHeight  = nfuncWidget->nfuncEdit->document()->size().height();
            qDebug() << "textHeight =="  << textHeight;
            tableWidget->setRowHeight(i+1,textHeight+20+16+18+22);
            appWidget->funcButton->setEnabled(false);

            connect(nfuncWidget->hideButton,SIGNAL(clicked()),this,SLOT(on_button_clicked()));
            connect(nfuncWidget,SIGNAL(sigTextHeight(int)),this,SLOT(textAreaChanged(int)));

            break;
        }
        else if(sender() == appWidget->updateButton)
        {
            qDebug() << "btn == updateButton:" << "row == " << i;
            break;
        }
        else
        {
            FuncWidget* gfuncWidget = (FuncWidget*)tableWidget->cellWidget(i,0);
            if(sender() == gfuncWidget->hideButton)
            {
                qDebug() << "btn == hideButton:" << "row == " << i;
                AppWidget *eblBtnWid = (AppWidget *)tableWidget->cellWidget(i-1,0);
                eblBtnWid->funcButton->setEnabled(true);
                tableWidget->removeRow(i);
            }
        }
    }
}

void MainWindow::textAreaChanged(int hig)
{
    qDebug() << "The Text Area Changed!" << endl;
    qDebug() << "The TextEdit Height Is " << hig;
    for(int i = 0; i < tableWidget->rowCount(); i++)
    {
       FuncWidget* chEditHeight = (FuncWidget*)tableWidget->cellWidget(i,0);
       if(sender() == chEditHeight)
       {
           tableWidget->setRowHeight(i,hig+20+16+18+22);
       }
    }
}

void MainWindow::strLenChanged()
{
    qDebug() << "The Text Area Changed!" << endl;
    for(int i = 0; i < tableWidget->rowCount(); i++)
    {
       AppWidget* chLabelWidth = (AppWidget*)tableWidget->cellWidget(i,0);
       if(sender() == chLabelWidth)
       {
           qDebug() << "The introLabel sizeHint() is " << chLabelWidth->introLabel->sizeHint();
           chLabelWidth->introLabel->setText(chLabelWidth->introstr);
           int labelWidth = chLabelWidth->introLabel->width();
           QFont font;
           QFontMetrics fm(font);
           int fontSize = fm.width(chLabelWidth->introstr);
           QString fmstr = chLabelWidth->introstr;
           labelWidth = tableWidget->width() -520;
           if(labelWidth > 550)
           {
               labelWidth = 550;
           }
           if(fontSize > labelWidth)
           {
               fmstr = fm.elidedText(chLabelWidth->introstr, Qt::ElideRight, labelWidth - 70);

           }
           chLabelWidth->introLabel->setText(fmstr);
       }
    }
}




