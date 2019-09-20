#include "widget.h"
#include <QDebug>
#include <QPainter>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    auto *pb = new QPushButton(this);
    pb->move(100, 100);



    /*使用QPainter在QWidget派生类对象上绘制图形时，
     * QPainter必须放在paintEvent事件处理函数里面绘制*/
}

#if 0
void Widget::paintEvent(QPaintEvent *)
{
    static int i = 0;
    qDebug() << __FUNCTION__ << i++ << endl;
    QPainter painter;
    painter.begin(this);
    /*画笔绘制轮廓*/
    painter.setPen(QPen(Qt::red));
    //painter.setPen(QPen(Qt::red, 5, Qt::DashLine));

    /*笔刷填充颜色*/
    painter.setBrush(QBrush(Qt::blue));
    //painter.setBrush(QBrush(Qt::blue, Qt::Dense1Pattern));


    painter.drawLine(0, 0, 100, 100);
    painter.drawRect(100, 100, 100, 200);
    painter.drawEllipse(200, 200, 100, 200);

    painter.drawText(100, 100, "helloworld");


    painter.end();
}
#endif

#if 0
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setPen(Qt::red);
    painter.drawRect(100, 100, 100, 100);
    /*只是改变画家绘图的坐标系，并不会改变窗口自身坐标系*/
    painter.rotate(10);
    painter.scale(0.5, 0.5);
    painter.translate(100, 0);
    painter.setPen(Qt::blue);
    painter.drawRect(100, 100, 100, 100);
    painter.end();
}
#endif


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    painter.drawRect(100, 100, 100, 100);

    painter.save();
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::blue);
    painter.drawRect(200, 100, 100, 100);
    painter.restore();


    painter.drawRect(300, 100, 100, 100);

    painter.end();
}


Widget::~Widget()
{

}
