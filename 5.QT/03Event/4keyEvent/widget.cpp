#include "widget.h"
#include <QDebug>
#include <QKeyEvent>
#include "pushbutton.h"
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *hBox = new QHBoxLayout(this);

    hBox->addWidget(new PushButton("pb0", this));
    hBox->addWidget(new PushButton("pb1", this));


    this->setFocus(Qt::OtherFocusReason);
}

void Widget::keyPressEvent(QKeyEvent * ev)
{

    if(ev->modifiers() & Qt::ControlModifier)
        qDebug() << "ctrl pressed" << endl;

    if(ev->modifiers() & Qt::AltModifier)
        qDebug() << "alt pressed" << endl;


    if(ev->modifiers() & Qt::ShiftModifier)
        qDebug() << "shift pressed" << endl;

    switch (ev->key())
    {
    case Qt::Key_A:
        qDebug() << "key A pressed" << endl;
        qDebug() << ev->text() << endl;
        break;
    case Qt::Key_B:
        qDebug() << "key B pressed" << endl;
        break;
    default:
        break;
    }

}


void Widget::keyReleaseEvent(QKeyEvent * ev)
{
    switch (ev->key())
    {
    case Qt::Key_A:
        qDebug() << "key A release" << endl;
        break;
    case Qt::Key_B:
        qDebug() << "key B release" << endl;
        break;
    default:
        break;
    }
}

Widget::~Widget()
{

}
