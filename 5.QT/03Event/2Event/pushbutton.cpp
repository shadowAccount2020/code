#include "pushbutton.h"
#include <QEvent>
#include <QDebug>
PushButton::PushButton(const QString & text, QWidget * parent)
    : QPushButton(text, parent)
{

}


bool PushButton::event(QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress )
    {
        qDebug() << "child widget mouse button press" << endl;
//        event->ignore(); //忽略这个事件
        event->accept(); //我接受了这个事件
//        return false; //表示我不处理这个事件
        return true; //我已经处理了这个事件

        /*
        * event->accept() 以及 return true 这个时候才不往父窗口传递。
        */
    }

    return QWidget::event(event);
}
