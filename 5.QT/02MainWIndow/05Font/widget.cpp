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
    QFont font =  this->font();                 //获取窗口字体
    font.setPointSize(50);                       //设置字体大小，但此时并不会显示进去，只有等到下面的setFont时，才会设置成功

//    QFontDatabase db ;
//    qDebug() << db.families() << endl;//这两行可以打印出可以用的所有字体，然后我们再选择用哪一种

    font.setFamily("Rockwell Condensed");   //设置使用哪种字体
    this->setFont(font);
    QLabel* label = new QLabel("helloworld", this);

    QVBoxLayout* vBox = new QVBoxLayout(this);
    QPushButton* pb = new QPushButton("showFontDialog");
    vBox->addWidget(label);
    vBox->addWidget(pb);
    connect(pb, SIGNAL(clicked()), this, SLOT(showFontDialog()));
}
void Widget::showFontDialog()//显示字体模态框，可以让用户选择
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
