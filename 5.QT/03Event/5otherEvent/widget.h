#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void closeEvent(QCloseEvent *);
};

#endif // WIDGET_H
