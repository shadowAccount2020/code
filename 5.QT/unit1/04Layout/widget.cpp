#include "widget.h"
#include <QPushButton>
#include <QHBoxLayout> //水平布局管理器，继承自QLayout,QLayout继承自QObject,QLayout是抽象基类，不能创建对象
#include <QVBoxLayout> //垂直布局管理器，继承自QLayout,QLayout继承自QObject,QLayout是抽象基类，不能创建对象
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("MC");     //设置窗口的文本，窗口的名字

    QHBoxLayout *hb = new QHBoxLayout(this);//创建水平布局管理器
    this->setLayout(hb);                    //要加上这句话，设置hb为水平布局管理器

    QPushButton *pb0 = new QPushButton("button1");
    QPushButton *pb1 = new QPushButton("button2");
    QPushButton *pb2 = new QPushButton("button3");
    QPushButton *pb3 = new QPushButton("button4");
    hb->addWidget(pb0,1); //将pb0添加到水平布局管理器中，后面的1是按钮的伸缩量，不加为0
    hb->addWidget(pb1);
    hb->addSpacing(10); //在pb1和pb2之间加上空隙，10个像素
    hb->addWidget(pb2);
    hb->addWidget(pb3);
    hb->addStretch(1);//拉伸的时候，增加一个伸缩量
//    hb->setMargin(0); //设置边界的像素为几个
    hb->setSpacing(0);  //设置按钮之间的空隙值为多少

//    pb1->setMinimumWidth(10);//设置伸缩的时候按钮最小为多少
    qDebug() << this->sizeHint() << endl; //打印最适合的窗口大小为多少，只有设置了布局管理器，才能使用这句话
}

Widget::~Widget()
{

}
