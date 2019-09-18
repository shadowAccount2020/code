#ifndef TEST_H
#define TEST_H
#include <QDebug>
class Teacher :public QObject //实现信号与槽功能，第一步先继承自QObject
{
    Q_OBJECT  //第二步声明这个宏
public:
    Teacher() {}
    void teach() {emit mysig();} //调用此函数就会发射信号

signals:        //QT中实现的，放在这个后面的都是信号
    void mysig();
};

class Student : public QObject
{
    Q_OBJECT
public:
    Student() {}

public slots:
    void answer()
    {
        qDebug() << __FUNCTION__ << endl;
    }
};


#endif // TEST_H
