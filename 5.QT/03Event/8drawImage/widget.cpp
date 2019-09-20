#include "widget.h"
#include <QPainter>
#include <QPixmap>
#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    _pixmap = new QPixmap("E:/123.jpg"); //会根据硬件设备进行优化。
    _image = new QImage("E:/123.jpg"); //提供像素级别的图像处理。
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    /*painter.drawPixmap(0, 0, _pixmap->scaled(this->width(), this->height()
                                             , Qt::KeepAspectRatioByExpanding
                                             , Qt::SmoothTransformation));*/
    painter.drawImage(0, 0, _image->scaled(this->width(), this->height()
                                           , Qt::KeepAspectRatioByExpanding
                                           , Qt::SmoothTransformation));
    painter.end();
}

Widget::~Widget()
{
    delete _pixmap;
}
