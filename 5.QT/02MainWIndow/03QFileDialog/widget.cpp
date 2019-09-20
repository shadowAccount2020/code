#include "widget.h"
#include <QFileDialog>
#include <QPushButton>
#include <QDebug>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(640, 480);
    QHBoxLayout* hBox = new QHBoxLayout(this);
    QPushButton* pb_open = new QPushButton("openDialog");
    QPushButton* pb_save = new QPushButton("saveDialog");
    hBox->addWidget(pb_open);
    hBox->addWidget(pb_save);
    connect(pb_open, SIGNAL(clicked()), this, SLOT(showOpenFile()));
    connect(pb_save, SIGNAL(clicked()), this, SLOT(showSaveFile()));
}
void Widget::showSaveFile()
{
    QString filename = QFileDialog::getSaveFileName(this, "save", _filename, "Image (*.png *.jpg *.jepg *.bmp)");
    if(!filename.isEmpty())
    {
        qDebug() << "file name:" << filename << endl;
        _filename = filename;
    }
}

void Widget::showOpenFile()
{
    QString filename = QFileDialog::getOpenFileName(this, "open", _filename, "Image (*.png *.jpg *.jepg *.bmp)");
    if(!filename.isEmpty())
    {
        qDebug() << "file name:" << filename << endl;
        _filename = filename;
    }

}

Widget::~Widget()
{

}
