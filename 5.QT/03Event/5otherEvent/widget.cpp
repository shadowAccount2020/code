#include "widget.h"
#include <QDebug>
#include <QPalette>
#include <QCloseEvent>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

void Widget::enterEvent(QEvent *)
{
    qDebug() << __FUNCTION__ << endl;
    QPalette palette = this->palette();
    palette.setColor(QPalette::Background, Qt::red);
    this->setPalette(palette);
}

void Widget::leaveEvent(QEvent *)
{
    qDebug() << __FUNCTION__ << endl;
    QPalette palette = this->palette();
    palette.setColor(QPalette::Background, Qt::blue);
    this->setPalette(palette);
}

void Widget::closeEvent(QCloseEvent *ev)
{
    qDebug() << __FUNCTION__ << endl;
    //ev->ignore();
    ev->accept();
}


Widget::~Widget()
{

}
