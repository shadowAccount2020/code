#include "widget.h"
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout* hBox = new QHBoxLayout(this);

    QPushButton* pb0 = new QPushButton("warning");
    QPushButton* pb1 = new QPushButton("information");
    QPushButton* pb2 = new QPushButton("question");

    hBox->addWidget(pb0);
    hBox->addWidget(pb1);
    hBox->addWidget(pb2);
    connect(pb0, SIGNAL(clicked()), this, SLOT(showWarning()));
    connect(pb1, SIGNAL(clicked()), this, SLOT(showInformation()));
    connect(pb2, SIGNAL(clicked()), this, SLOT(showQuestion()));
}

void Widget::showWarning()
{
     int sb = QMessageBox::warning(this, "warning", "unuse var"
                                   , QMessageBox::Open | QMessageBox::Save);
     qDebug() << sb << endl;
}

void Widget::showInformation()
{
    int sb = QMessageBox::information(this, "information", "unuse var"
                             , QMessageBox::Open | QMessageBox::Save);
    qDebug() << sb << endl;
}

void Widget::showQuestion()
{
    int sb = QMessageBox::question(this, "qusetion", "unuse var"
                             , QMessageBox::Open | QMessageBox::Save);
    qDebug() << sb << endl;
}


Widget::~Widget()
{

}
