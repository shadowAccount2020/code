#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *);
public slots:
    void drawPixmap();
private:
    QPixmap* _pixmap;

};

#endif // WIDGET_H
