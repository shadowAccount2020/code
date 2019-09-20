#include "widget.h"
#include <QFont>
#include <qDebug>
#include <QLabel>
#include <QFontDialog>
#include <QFontDatabase>
#include <QPushButton>
#include <QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont font =  this->font();
    font.setPointSize(50);
    font.setFamily("Rockwell Condensed");
    this->setFont(font);
    QLabel* label = new QLabel("helloworld", this);

    QVBoxLayout* vBox = new QVBoxLayout(this);
    QPushButton* pb = new QPushButton("showFontDialog");
    vBox->addWidget(label);
    vBox->addWidget(pb);
    connect(pb, SIGNAL(clicked()), this, SLOT(showFontDialog()));
}
void Widget::showFontDialog()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this->font(), this, "Font");
    if(ok)
    {
        qDebug() << font << endl;
        this->setFont(font);
    }
}

Widget::~Widget()
{

}
