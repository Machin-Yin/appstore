#ifndef APPWIDGET_H
#define APPWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class AppWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AppWidget(QWidget *parent = 0);

public:
    QHBoxLayout *appLayout;
    QVBoxLayout *rightLayout;
    QHBoxLayout *bottomLayout;
    QPushButton *headButton;
    QPushButton *nameButton;
    QLabel *introLabel;
    QPushButton *funcButton;
    QPixmap pix;

};

#endif // APPWIDGET_H
