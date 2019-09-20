#include "widget.h"
#include <QPainter>
#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent), _bgColor(Qt::red)
{
    /*布局控制窗口*/
    QDialog* ctrlDialog = new QDialog(this);
    QHBoxLayout* hBox = new QHBoxLayout(ctrlDialog);

    QPushButton* pb = new QPushButton("blue");
    hBox->addWidget(pb);

    QPushButton* pb1 = new QPushButton("updateBlue");
    hBox->addWidget(pb1);


    QPushButton* pb2 = new QPushButton("repaintYellow");
    hBox->addWidget(pb2);

    connect(pb, SIGNAL(clicked()), this, SLOT(setBlueSlot()));
    connect(pb1, SIGNAL(clicked()), this, SLOT(updateBlueSlot()));
    connect(pb2, SIGNAL(clicked()), this, SLOT(repaintYellowSlot()));



    ctrlDialog->show();
}
void Widget::setBlueSlot()
{
    _bgColor = Qt::blue;
}
void Widget::updateBlueSlot()
{
    _bgColor = Qt::blue;
    this->update(); //调用update的时候，并不是马上出触发paintEvent事件，
                    //而是把绘画事件丢到消息循环中，等待消息循环调度，会多次update合并成一个。
}
void Widget::repaintYellowSlot()
{
    _bgColor = Qt::yellow;
    this->repaint(0, 0, 100, 100);//调用repaint的时候，马上触发paintEvent事件。
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setBrush(_bgColor);
    painter.drawRect(this->rect());
    painter.end();
}

Widget::~Widget()
{

}
