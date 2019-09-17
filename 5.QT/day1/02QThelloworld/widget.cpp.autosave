#include "widget.h"
#include <QPushButton>
#include "pushbutton.h"

/*父子窗口是对象之间的组合关系，父子类继承关系*/

/*Qt有一套自己的内存管理机制, 只要是继承至QObject的对象都可以通过，
 * 指定一个QObject的父对象来托管他的内存*/

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    PushButton *pb = new PushButton("File",this);//继承自
    this->move(300,400);
    this->resize(500,500);
//    delete pb;
//    pb->deleteLater();
}
