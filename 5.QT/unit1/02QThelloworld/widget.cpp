#include "widget.h"
#include <QPushButton>
#include "pushbutton.h"

/*���Ӵ����Ƕ���֮�����Ϲ�ϵ��������̳й�ϵ*/

/*Qt��һ���Լ����ڴ�������, ֻҪ�Ǽ̳���QObject�Ķ��󶼿���ͨ����
 * ָ��һ��QObject�ĸ��������й������ڴ�*/

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    PushButton *pb = new PushButton("File",this);//�̳���
    this->move(300,400);
    this->resize(500,500);
//    delete pb;
//    pb->deleteLater();
}
