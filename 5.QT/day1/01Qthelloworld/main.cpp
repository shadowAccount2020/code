#include <QApplication>//继承自QObject，QObject是QT中最基本的一个类
#include <QtWidgets> //QT中最基本的一个窗口类，很多类都继承自这个
#include <QPushButton>//按钮类
#include <QDebug>//QT中用于打印的

int main(int argc , char **argv)
{
    QApplication app(argc,argv);//消息的控制流，以及主程序的一些设置，不管多少个窗口，这只能有一个，单实例
    QWidget widget;
    widget.move(300,400);//设置位置
    widget.resize(600,600);//设置大小
    QPushButton pb;
    pb.setParent(&widget);//嵌套到父窗口上显示
    pb.setText("Close");

    QObject::connect(&pb,SIGNAL(clicked()),&widget,SLOT(close()));

    widget.show();//以顶级窗口方式显示
    qDebug() << pb.size() << endl;//放到这里写才行，放到widget.show()前面打印结果是不对的，会是默认值，放到后面才是显示之后的
    return app.exec();//是一个死循环，消息循环，消息泵
}
