#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void showOpenFile();
    void showSaveFile();
private:
    QString _filename;
};

#endif // WIDGET_H
