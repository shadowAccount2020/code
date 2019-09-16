#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>

class PushButton : public QPushButton
{
public:
    PushButton(const QString &text, QWidget *parent = nullptr);
    ~PushButton();
};

#endif // PUSHBUTTON_H
