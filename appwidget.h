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
    bool event(QEvent *event);
signals:
    void sigintrofm();

public:
    QHBoxLayout *appLayout;
    QVBoxLayout *rightLayout;
    QHBoxLayout *bottomLayout;
    QPushButton *headButton;
    QPushButton *nameButton;
    QLabel *introLabel;
    QString introstr;
    QPushButton *funcButton;
    QLabel *sizeLabel;
    QLabel *versionLabel;
    QPushButton *updateButton;
    QPixmap pix;


};

#endif // APPWIDGET_H
