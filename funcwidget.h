#ifndef FUNCWIDGET_H
#define FUNCWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class FuncWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FuncWidget(QWidget *parent = 0);
    QPushButton *hideButton;

signals:

public slots:
private:
    QHBoxLayout *funcLayout;
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QLabel *funcLabel;
    QTextEdit *funcEdit;
};

#endif // FUNCWIDGET_H
