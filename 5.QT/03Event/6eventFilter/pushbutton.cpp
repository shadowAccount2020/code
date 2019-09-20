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
        qDebug() << "child widget mouse button press" << this->text() << endl;
        return true;
    }
    else if(event->type() == QEvent::MouseButtonRelease )
    {
        qDebug() << "child widget mouse button release" << this->text() << endl;
        return true;
    }
    return QWidget::event(event);
}
