#include "widget.h"
#include <QLabel>
#include <QLineEdit>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("MC's Blog");
    this->move(300,400);
    this->resize(500,500);
    QLabel *la = new QLabel(this);
    QLineEdit *edit = new QLineEdit("handsome",this);
    edit->move(333,444);
    la->setText("File");
}
