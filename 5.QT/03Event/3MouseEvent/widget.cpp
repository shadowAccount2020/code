#include "widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //this->setMouseTracking(true);
}

void Widget::mousePressEvent(QMouseEvent* ev)
{
    switch (ev->button()) {
        case Qt::LeftButton:
            qDebug() << __FUNCTION__ << ev->pos() << "LeftButton" << endl;
            break;
        case Qt::RightButton:
            qDebug() << __FUNCTION__  << "RightButton" << endl;
            break;
        case Qt::MidButton:
            qDebug() << __FUNCTION__ << "MidButton" << endl;
            break;
        default:
            break;
    }
}
void Widget::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug() << __FUNCTION__ << ev->pos() << ev->button() << endl;
    /*
     * ev-buttonÓÀÔ¶·µ»ØQMouseEvent::NoButton
    */
}

void Widget::mouseReleaseEvent(QMouseEvent* ev)
{
    qDebug() << __FUNCTION__ << endl;
    /*
    switch (ev->button()) {
        case Qt::LeftButton:
            qDebug() << __FUNCTION__ << "LeftButton" << endl;
            break;
        case Qt::RightButton:
            qDebug() << __FUNCTION__  << "RightButton" << endl;
            break;
        case Qt::MidButton:
            qDebug() << __FUNCTION__ << "MidButton" << endl;
            break;
        default:
            break;
    }
    */
}

void Widget::wheelEvent(QWheelEvent* ev)
{
    qDebug() << __FUNCTION__ << ev->angleDelta() << endl;
}

Widget::~Widget()
{

}
