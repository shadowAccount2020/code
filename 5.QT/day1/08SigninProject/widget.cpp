#include "widget.h"
#include <QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QGridLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{

    QGridLayout* grid = new QGridLayout(this);

    QLabel *la0 = new QLabel;
    QLabel *la1 = new QLabel;
    la0->setText("用户名 :");
    la1->setText("密码 :");

    QPushButton *pb0 = new QPushButton("确认",this);
    QPushButton *pb1 = new QPushButton("取消",this);

    QLineEdit *edit0 = new QLineEdit;
    QLineEdit *edit1 = new QLineEdit;

    QHBoxLayout *hb = new QHBoxLayout;


    grid->addWidget(la0, 0, 0, 1, 1);
    grid->addWidget(edit0, 0, 1, 1, 2);
    grid->addWidget(la1, 1, 0, 1, 1);
    grid->addWidget(edit1, 1, 1, 1, 2);

    grid->addLayout(hb, 2, 0, 1, 3);
    hb->addSpacing(80);
    hb->addWidget(pb0);
    hb->addWidget(pb1);

    edit1->setEchoMode(QLineEdit::Password);
}

Widget::~Widget()
{

}
