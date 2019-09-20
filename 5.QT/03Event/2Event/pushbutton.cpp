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
//        event->ignore(); //��������¼�
        event->accept(); //�ҽ���������¼�
//        return false; //��ʾ�Ҳ���������¼�
        return true; //���Ѿ�����������¼�

        /*
        * event->accept() �Լ� return true ���ʱ��Ų��������ڴ��ݡ�
        */
    }

    return QWidget::event(event);
}
