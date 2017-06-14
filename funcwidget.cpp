#include "funcwidget.h"

FuncWidget::FuncWidget(QWidget *parent) : QWidget(parent)
{
    funcLayout = new QHBoxLayout;
    funcLayout->setMargin(0);
    leftLayout = new QVBoxLayout;
    rightLayout = new QVBoxLayout;
    funcLabel = new QLabel();
//    funcEdit = new QTextEdit();
    nfuncLabel = new QLabel();
    hideButton = new QPushButton();

    funcLabel->setText(tr("新版特性"));
    nfuncLabel->setText("lsdflafl asdfsldks ldkslak dasld fkslfsk dhhhhhh hhhh hh,hhh hhhhhh hhhhhhhhhh hhhhhhh hhhhhhhhhhh hhhhhhhhhhhhh hhhhhhhhhhhhhh hhfslfskldfskd lfkslfls klsllad kdkkkkkk kkkkkkkkk      ddddddd ddddd        dddddddd            kkkkkkkkkkkk kkkkkkkkkkk lssssssss ssssssssssss ssssssssssss ssssssssss sssssssssssssd dddddddddddggggg gggggggggmmmmm mmmmmmmmmmmm mmmmmmmmm mmmmmmm mmmuuuu uuuuuuuuu uuuuuuuu ggggs");
//    nfuncLabel->setStyleSheet("border: 0;" "background:white");
//    nfuncLabel->setReadOnly(true);
    nfuncLabel->adjustSize();
//    nfuncLabel->setGeometry(QRect(328, 240, 329, 27*4));
    nfuncLabel->setWordWrap(true);
    nfuncLabel->setAlignment(Qt::AlignTop);
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
    leftLayout->addWidget(nfuncLabel);
//    leftLayout->addStretch();
    leftLayout->addSpacing(24);
    funcLayout->addStretch();
    funcLayout->addSpacing(100);
    funcLayout->addLayout(rightLayout);
    rightLayout->addStretch();
    rightLayout->addWidget(hideButton);
    rightLayout->addSpacing(10);
    funcLayout->addSpacing(10);
    setLayout(funcLayout);

}
