#include "widget.h"
#include <QDebug>
#include <QEvent>
#include "pushbutton.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    new PushButton("button", this);
}

bool Widget::event(QEvent *event)
{

    if(event->type() == QEvent::MouseButtonPress
            | QEvent::MouseButtonDblClick)
    {
        qDebug() << "father widget mouse button press" << endl;
//        return true;
    }
    return QWidget::event(event);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    static int i = 0;
    qDebug() << __FUNCTION__ << i++ << endl;
}

Widget::~Widget()
{

}
