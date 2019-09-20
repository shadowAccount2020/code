#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QFile;
class QTextEdit;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void newSlot   ();
    void openSlot  ();
    void saveSlot  ();
    bool saveAsSlot();
    void wrapSlot(bool);
    void closeSlot ();
private:
    void initMenuBar();
private:
    QFile* _file;
    QTextEdit* _edit;
    QString _curPath;
};

#endif // MAINWINDOW_H
