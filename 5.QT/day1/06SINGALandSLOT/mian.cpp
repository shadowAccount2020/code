#include <QApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Teacher tea;
    Student stu;
    QObject::connect(&tea,SIGNAL(mysig()),&stu,SLOT(answer()));
    tea.teach();
    return a.exec();
}
