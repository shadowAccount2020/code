#include "widget.h"
#include <QGridLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *gl = new QGridLayout(this);
    QPushButton *pb0 = new QPushButton("button1");
    QPushButton *pb1 = new QPushButton("button2");
    QPushButton *pb2 = new QPushButton("button3");
    QPushButton *pb3 = new QPushButton("button4");
    QPushButton *pb4 = new QPushButton("button5");
//    pb4->setMinimumHeight(100);
    gl->setRowStretch(4,0);
    gl->addWidget(pb0,0,0,1,1);
    gl->addWidget(pb1,0,1,1,1);
    gl->addWidget(pb2,1,0,1,1);
    gl->addWidget(pb3,1,1,1,1);
    gl->addWidget(pb4,2,0,2,3);

}

Widget::~Widget()
{

}
