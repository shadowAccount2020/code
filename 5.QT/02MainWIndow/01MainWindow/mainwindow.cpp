#include "mainwindow.h"
#include <QMenuBar>
#include<QToolBar>
#include<QStatusBar>
#include<QTextEdit>//���Ա༭�����ı�
#include<QDockWidget>

MainWindow::MainWindow(QWidget *parent) //�̳���Qwidget
    : QMainWindow(parent)
{
    QTextEdit*edit = new QTextEdit(this);
    QDockWidget*dock =  new QDockWidget(this);
    this->resize(640,480);
    initmenubar();
    inittoolbar();
    this->statusBar()->showMessage("start",5000);//5s֮����ʧ,״̬��
    this->setCentralWidget(edit);//�������봰��
    this->addDockWidget(Qt::LeftDockWidgetArea,dock);

}

void MainWindow::initmenubar()//�˵���
{
    QMenuBar *menubar = this->menuBar();
    QMenu* fileMenu = new QMenu("File(&F)",menubar);//�����&F�����Զ�ʵ�ֿ�ݼ����ܣ�alt+f
    fileMenu->addAction("new file");//�ڲ˵����±����ӹ���
    fileMenu->addAction(QIcon("E:/favicon.png"),"open file");//ʵ���ڲ˵����±ߵ��ӹ����������ͼ��
    fileMenu->addAction("close",this,SLOT(close()));//��ͬ��addActionʵ�ֵĹ��ܣ����Ϊ���Ӳۺ���
    fileMenu->addSeparator();//���ӷָ���
    fileMenu->addAction(QIcon("E:/favicon.png"),"close",this,SLOT(close()));
    fileMenu->addAction(QIcon("E:/favicon.png"),"save",this,SLOT(saveSLOT()),QKeySequence("Ctrl+s"));

    fileMenu->addMenu("son menu")->addAction("default1");
    fileMenu->addMenu("son menu")->addAction("default2");


    menubar->addMenu(fileMenu);//addMenu�ķ���ֵΪQMenu
    menubar->addMenu("help(&H)");//�������QMenu* fileMenu = new QMenuһ����������ʵ�ֲ˵�����Щ����
}

void MainWindow::inittoolbar()//toolbar
{
    QToolBar *toolbar =  this->addToolBar("toolbar");
    toolbar->addAction("new file");//�ڲ˵����±����ӹ���
    toolbar->addAction(QIcon("E:/favicon.png"),"open file");//ʵ���ڲ˵����±ߵ��ӹ����������ͼ��
    toolbar->addAction("close",this,SLOT(close()));//��ͬ��addActionʵ�ֵĹ��ܣ����Ϊ���Ӳۺ���
    toolbar->addSeparator();//���ӷָ���
    toolbar->addAction(QIcon("E:/favicon.png"),"close",this,SLOT(close()));
    toolbar->addAction(QIcon("E:/favicon.png"),"save",this,SLOT(saveSLOT()));
}


MainWindow::~MainWindow()
{

}
