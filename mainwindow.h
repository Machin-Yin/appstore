#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QSplitter>
#include <QVBoxLayout>
#include <QPixmap>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupView();
    void addRow(int row);
    void getAppWidget();
private:
    QTableWidget *tableWidget;
    QHBoxLayout *standardLayout;
    QSplitter *splitter;
    int clicked_row;
public slots:
    void on_button_clicked();
};

#endif // MAINWINDOW_H
