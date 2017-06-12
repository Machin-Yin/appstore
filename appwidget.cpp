#include "appwidget.h"
#include <QDebug>
#include <QPalette>

#define SIZE_W 250

AppWidget::AppWidget(QWidget *parent) : QWidget(parent)
{
    appLayout = new QHBoxLayout();
    appLayout->setMargin(0);
    rightLayout = new QVBoxLayout();
    rightLayout->setMargin(0);
    bottomLayout = new QHBoxLayout();

    headButton = new QPushButton();
    QPixmap pixmap(tr("image/head.png"));
    headButton->setFlat(true);
    headButton->setIcon(pixmap);
    headButton->setIconSize(QSize(64,64));
//    headButton->setFixedSize(pixmap.size());

    nameButton = new QPushButton();
    nameButton->setFlat(true);
    nameButton->setMaximumWidth(100);
    nameButton->setStyleSheet("text-align: left;");
    nameButton->setText(tr("QQ"));

    QString text1(tr("全新视觉，简约界面乐享沟通！全新视觉，简约界面乐享沟通！"));
    QFont font;
    QFontMetrics fm(font);
    QString text2 = fm.elidedText(text1, Qt::ElideRight, SIZE_W);
    introLabel = new QLabel();
    introLabel->setStyleSheet("border-right: 1px; border-style: solid; border-color: #cccccc;");
    introLabel->setText(text2);

    funcButton = new QPushButton();
    funcButton->setFlat(true);
    funcButton->setText(tr("新版功能"));
    funcButton->setFlat(true);
    QPalette fucpal;
    fucpal.setColor(QPalette::ButtonText, QColor(2,122,255));
    funcButton->setPalette(fucpal);
    funcButton->setStyleSheet("text-align: left;");
    funcButton->setMaximumWidth(64);
//    qDebug() << "funcButton->size()" << funcButton->size() ;

    QLabel *sizeLabel = new QLabel();
    sizeLabel->resize(16,64);
    sizeLabel->setText(tr("13.8M"));

    QLabel *versionLabel = new QLabel();
    versionLabel->setText(tr("V7.0.0"));

    QPushButton *updateButton = new QPushButton();
    updateButton->setFixedSize(80,32);
//    QPalette uppal;
//    uppal.setColor(QPalette::ButtonText, QColor(2,122,255));
//    updateButton->setPalette(uppal);
//    updateButton->setStyleSheet("border: 1px solid #027aff  ; border-radius: 2px; ");
//    updateButton->setStyleSheet("border-color: #027aff; border-width: 1px; border-style: solid; border-radius: 2px; ");
    updateButton->setText(tr("update"));

//    rowLayout->addWidget(sizeLabel);
//    rowLayout->addSpacing(112);
//    rowLayout->addWidget(versionLabel);
//    rowLayout->addSpacing(112);
//    rowLayout->addWidget(updateButton);

    appLayout->addWidget(headButton);
    appLayout->setSpacing(16);
    appLayout->addLayout(rightLayout);
    rightLayout->addStretch(24);
    rightLayout->addWidget(nameButton);
    rightLayout->setSpacing(3);
    rightLayout->addLayout(bottomLayout);
    rightLayout->addStretch(24);
    bottomLayout->addWidget(introLabel);
    bottomLayout->addWidget(funcButton);
    bottomLayout->addStretch();
    appLayout->addWidget(sizeLabel);
    appLayout->addSpacing(112);
    appLayout->addWidget(versionLabel);
    appLayout->addSpacing(112);
    appLayout->addWidget(updateButton);
//    appLayout->add
    setLayout(appLayout);

}



