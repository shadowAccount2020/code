#include "widget.h"
#include <QColor>//没继承任何基类
#include <QPalette> //调色板
#include <QDebug>
#include <QLabel>
#include <QColorDialog>
#include <QVBoxLayout>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout* vBox = new QVBoxLayout(this);
    QLabel * label = new QLabel("helloworld");
    QPushButton* pb = new QPushButton("showColorDialog");
    vBox->addWidget(label);
    vBox->addWidget(pb);
    connect(pb, SIGNAL(clicked()), this, SLOT(showColorDialog()));
}

void Widget::showColorDialog()
{
    QColor color = QColorDialog::getColor(QColor("#00FF00"), this, "color");//设置颜色
    if(color.isValid())
    {
        QPalette palette = this->palette();
        qDebug() << palette.color(QPalette::WindowText) << endl;//设置文本的颜色
//        palette.setColor(QPalette::WindowText, color);
        palette.setColor(QPalette::Background, QColor(color));
        this->setPalette(palette);
    }
}

Widget::~Widget()
{

}
