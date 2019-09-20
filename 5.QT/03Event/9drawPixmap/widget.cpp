#include "widget.h"
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QPushButton>
#include <QDialog>
#include <QHBoxLayout>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    _pixmap = new QPixmap(this->size()); //会根据硬件设备进行优化。
    _pixmap->fill(QColor(0, 0, 0, 0));

    QDialog* _ctrlDialog = new QDialog(this);
    QHBoxLayout* hBox = new QHBoxLayout(_ctrlDialog);
    QPushButton* pb = new QPushButton("drawPixmap");
    hBox->addWidget(pb);
    connect(pb, SIGNAL(clicked()), this, SLOT(drawPixmap()));
    _ctrlDialog->show();

}

void Widget::drawPixmap()
{
    QPainter painter;
    painter.begin(_pixmap);
    painter.setPen(QPen(Qt::red));
    painter.setBrush(QBrush(Qt::blue));
    painter.drawLine(0, 0, 100, 100);
    painter.drawRect(100, 100, 100, 200);
    painter.drawEllipse(200, 200, 100, 200);
    painter.drawText(100, 100, "helloworld");
    painter.end();
    _pixmap->save("E:/1234.png");
    this->update();
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(0, 0, *_pixmap);
    painter.end();
}

Widget::~Widget()
{
    delete _pixmap;
}
