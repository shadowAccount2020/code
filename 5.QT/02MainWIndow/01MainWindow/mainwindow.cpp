#include "mainwindow.h"
#include <QMenuBar>
#include<QToolBar>
#include<QStatusBar>
#include<QTextEdit>//可以编辑整个文本
#include<QDockWidget>

MainWindow::MainWindow(QWidget *parent) //继承自Qwidget
    : QMainWindow(parent)
{
    QTextEdit*edit = new QTextEdit(this);
    QDockWidget*dock =  new QDockWidget(this);
    this->resize(640,480);
    initmenubar();
    inittoolbar();
    this->statusBar()->showMessage("start",5000);//5s之后消失,状态栏
    this->setCentralWidget(edit);//设置中央窗口
    this->addDockWidget(Qt::LeftDockWidgetArea,dock);

}

void MainWindow::initmenubar()//菜单栏
{
    QMenuBar *menubar = this->menuBar();
    QMenu* fileMenu = new QMenu("File(&F)",menubar);//这里的&F可以自动实现快捷键功能，alt+f
    fileMenu->addAction("new file");//在菜单栏下边增加功能
    fileMenu->addAction(QIcon("E:/favicon.png"),"open file");//实现在菜单栏下边的子功能栏中添加图标
    fileMenu->addAction("close",this,SLOT(close()));//不同的addAction实现的功能，这个为增加槽函数
    fileMenu->addSeparator();//增加分隔线
    fileMenu->addAction(QIcon("E:/favicon.png"),"close",this,SLOT(close()));
    fileMenu->addAction(QIcon("E:/favicon.png"),"save",this,SLOT(saveSLOT()),QKeySequence("Ctrl+s"));

    fileMenu->addMenu("son menu")->addAction("default1");
    fileMenu->addMenu("son menu")->addAction("default2");


    menubar->addMenu(fileMenu);//addMenu的返回值为QMenu
    menubar->addMenu("help(&H)");//和上面的QMenu* fileMenu = new QMenu一样，都可以实现菜单的那些功能
}

void MainWindow::inittoolbar()//toolbar
{
    QToolBar *toolbar =  this->addToolBar("toolbar");
    toolbar->addAction("new file");//在菜单栏下边增加功能
    toolbar->addAction(QIcon("E:/favicon.png"),"open file");//实现在菜单栏下边的子功能栏中添加图标
    toolbar->addAction("close",this,SLOT(close()));//不同的addAction实现的功能，这个为增加槽函数
    toolbar->addSeparator();//增加分隔线
    toolbar->addAction(QIcon("E:/favicon.png"),"close",this,SLOT(close()));
    toolbar->addAction(QIcon("E:/favicon.png"),"save",this,SLOT(saveSLOT()));
}


MainWindow::~MainWindow()
{

}
