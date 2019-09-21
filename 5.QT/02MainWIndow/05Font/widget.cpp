#include "widget.h"
#include <QFont>
#include <QDebug>
#include <QLabel>
#include <QFontDialog>
#include <QFontDatabase>
#include <QPushButton>
#include <QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont font =  this->font();                 //��ȡ��������
    font.setPointSize(50);                       //���������С������ʱ��������ʾ��ȥ��ֻ�еȵ������setFontʱ���Ż����óɹ�

//    QFontDatabase db ;
//    qDebug() << db.families() << endl;//�����п��Դ�ӡ�������õ��������壬Ȼ��������ѡ������һ��

    font.setFamily("Rockwell Condensed");   //����ʹ����������
    this->setFont(font);
    QLabel* label = new QLabel("helloworld", this);

    QVBoxLayout* vBox = new QVBoxLayout(this);
    QPushButton* pb = new QPushButton("showFontDialog");
    vBox->addWidget(label);
    vBox->addWidget(pb);
    connect(pb, SIGNAL(clicked()), this, SLOT(showFontDialog()));
}
void Widget::showFontDialog()//��ʾ����ģ̬�򣬿������û�ѡ��
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
