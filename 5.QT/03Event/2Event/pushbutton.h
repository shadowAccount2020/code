#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QWidget>
#include <QPushButton>

class PushButton : public QPushButton
{
public:
    PushButton(const QString & text, QWidget * parent = nullptr);
    bool event(QEvent *e);
};

#endif // PUSHBUTTON_H
