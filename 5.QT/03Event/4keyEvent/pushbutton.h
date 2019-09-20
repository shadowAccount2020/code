#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>

class PushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButton(const QString & text, QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *e);
signals:

public slots:
};

#endif // PUSHBUTTON_H
