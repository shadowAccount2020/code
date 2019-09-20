#include "pushbutton.h"
#include <QDebug>
PushButton::PushButton(const QString &text, QWidget *parent) : QPushButton(text,parent)
{

}


void PushButton::keyPressEvent(QKeyEvent *)
{
    qDebug() << this->text() << __FUNCTION__ << endl;
}


void PushButton::keyReleaseEvent(QKeyEvent *e)
{
    qDebug() << this->text() << __FUNCTION__<< endl;
}
