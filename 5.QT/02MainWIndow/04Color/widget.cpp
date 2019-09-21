#include "widget.h"
#include <QColor>//û�̳��κλ���
#include <QPalette> //��ɫ��
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
    QColor color = QColorDialog::getColor(QColor("#00FF00"), this, "color");//������ɫ
    if(color.isValid())
    {
        QPalette palette = this->palette();
        qDebug() << palette.color(QPalette::WindowText) << endl;//�����ı�����ɫ
//        palette.setColor(QPalette::WindowText, color);
        palette.setColor(QPalette::Background, QColor(color));
        this->setPalette(palette);
    }
}

Widget::~Widget()
{

}
