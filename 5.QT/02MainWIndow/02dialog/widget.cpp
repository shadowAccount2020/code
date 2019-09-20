#include "widget.h"
#include <QDialog>
#include <QDebug>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

/*
 * ��ͨ����QWidget����ͨ�����ַ�ʽ��ʾ:
 * 1����ָ�������ڣ�ֱ�ӵ���show������ʾ���Զ���������ʾ
 * 2��ָ�������ڣ���Ƕ����ʾ
 * 3��ָ�������ڵ�ʱ�򣬵���show����������Ƕ����ʾ
 *
 * QDilaog��ʾ��ʽ:
 * 1����ָ�������ڣ�ֱ�ӵ���show������ʾ���Զ���������ʾ
 * 2��ָ�������ڣ�������show����������ʾ
 * 3��ָ��������, ����show����, ��Ȼ�Զ���������ʾ
 * 4��ֱ�ӵ���exec��������ģ̬���ڷ�ʽ��ʾ
*/

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(640, 480);
    QPushButton* pb = new QPushButton("Dailog", this);
    pb->show();

    _dialog = new QDialog(this);
    connect(pb, SIGNAL(clicked()), this, SLOT(showDialog()));
    initDialog();
}
void Widget::initDialog()
{
    QGridLayout* grid = new QGridLayout(_dialog);
    QHBoxLayout* hBox = new QHBoxLayout;
    QPushButton* ok = new QPushButton("ȷ��");
    QPushButton* cancel = new QPushButton("ȡ��");
    QLabel* userLabel = new QLabel("�û�:");
    QLineEdit* userEdit = new QLineEdit;
    QLabel* passwdLabel = new QLabel("����:");
    QLineEdit* passwdEdit = new QLineEdit;

    grid->addWidget(userLabel, 0, 0, 1, 1);
    grid->addWidget(userEdit, 0, 1, 1, 2);
    grid->addWidget(passwdLabel, 1, 0, 1, 1);
    grid->addWidget(passwdEdit, 1, 1, 1, 2);

    grid->addLayout(hBox, 2, 0, 1, 3);
    hBox->addSpacing(80);
    hBox->addWidget(ok);
    hBox->addWidget(cancel);

    passwdEdit->setEchoMode(QLineEdit::Password);

    connect(cancel, SIGNAL(clicked()), _dialog, SLOT(reject()));
    connect(ok, SIGNAL(clicked()), _dialog, SLOT(accept()));

}

void Widget::showDialog()
{

    int ret = _dialog->exec();
    qDebug() << ret << endl;
}

Widget::~Widget()
{

}
