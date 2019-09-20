#include "widget.h"
#include "pushbutton.h"
#include <QDebug>
#include <QEvent>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout* hBox = new QHBoxLayout(this);

    PushButton* pb0 = new PushButton("pb0", this);
    pb0->installEventFilter(this);

    PushButton* pb1 = new PushButton("pb1", this);
    pb1->installEventFilter(this);

    hBox->addWidget(pb0);
    hBox->addWidget(pb1);
}

bool Widget::eventFilter(QObject *ob, QEvent *ev)
{
    QString text = dynamic_cast<PushButton*>(ob)->text();
    if(text == "pb0" && ev->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "filte mouse button press event"<< endl;
        //return false; //不过滤事件
        return true; //过滤事件
    }
    return QWidget::eventFilter(ob, ev);
}


Widget::~Widget()
{

}
