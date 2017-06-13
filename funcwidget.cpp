#include "funcwidget.h"

FuncWidget::FuncWidget(QWidget *parent) : QWidget(parent)
{
    funcLayout = new QHBoxLayout;
    funcLayout->setMargin(0);
    leftLayout = new QVBoxLayout;
    rightLayout = new QVBoxLayout;
    funcLabel = new QLabel();
    funcEdit = new QTextEdit();
    hideButton = new QPushButton();

    funcLabel->setText(tr("新版特性"));
    funcEdit->setText("lsdflaflasdfsldksldkslakdasldfkslfskdfslfskldfskdlfkslflsklslladkdkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkklssssssssssssssssssssssssssssssssssssssssssssssssssssssss");
    QPixmap pixmap(tr("image/hide.png"));
    hideButton->setFlat(true);
    hideButton->setIcon(pixmap);
//    hideButton->setStyleSheet("border-image: /image/hide.png");
    hideButton->setIconSize(QSize(44,44));

    funcLayout->addSpacing(80);
    funcLayout->addLayout(leftLayout);
    leftLayout->addSpacing(20);
    leftLayout->addWidget(funcLabel);
    leftLayout->addSpacing(12);
    leftLayout->addWidget(funcEdit);
    leftLayout->addStretch();
    funcLayout->addSpacing(100);
    funcLayout->addLayout(rightLayout);
    rightLayout->addStretch();
    rightLayout->addWidget(hideButton);
    rightLayout->addSpacing(10);
    funcLayout->addSpacing(20);
    setLayout(funcLayout);

}
