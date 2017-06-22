#include "mainwindow.h"
#include <QApplication>
#include <appwidget.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    AppWidget * aa = (AppWidget *)w.tableWidget->cellWidget(1,0);
//    qDebug() << "aa->introLabel->width()" << aa->introLabel->width();
    return a.exec();
}
