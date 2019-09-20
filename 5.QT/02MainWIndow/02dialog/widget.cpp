#include "widget.h"
#include <QDialog>
#include <QDebug>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

/*
 * 普通窗口QWidget可以通过两种方式显示:
 * 1、不指定父窗口，直接调用show函数显示，以顶级窗口显示
 * 2、指定父窗口，来嵌套显示
 * 3、指定父窗口的时候，调用show函数，还是嵌套显示
 *
 * QDilaog显示方式:
 * 1、不指定父窗口，直接调用show函数显示，以顶级窗口显示
 * 2、指定父窗口，不调用show函数，不显示
 * 3、指定父窗口, 调用show函数, 仍然以顶级窗口显示
 * 4、直接调用exec函数，以模态窗口方式显示
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
    QPushButton* ok = new QPushButton("确认");
    QPushButton* cancel = new QPushButton("取消");
    QLabel* userLabel = new QLabel("用户:");
    QLineEdit* userEdit = new QLineEdit;
    QLabel* passwdLabel = new QLabel("密码:");
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
