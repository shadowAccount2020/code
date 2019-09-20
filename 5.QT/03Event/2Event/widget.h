#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    bool event(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // WIDGET_H
