#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QTextEdit>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
        _file = new QFile(this);
        _edit = new QTextEdit(this);
        this->setCentralWidget(_edit);
        initMenuBar();

}

void MainWindow::initMenuBar()
{
    QMenuBar*  menuBar = this->menuBar();
    QMenu* fileMenu = menuBar->addMenu("文件(&F)");
    fileMenu->addAction("新建", this, SLOT(newSlot()), QKeySequence("Ctrl+N"));
    fileMenu->addAction("打开", this, SLOT(openSlot()), QKeySequence("Ctrl+O"));
    fileMenu->addAction("保存", this, SLOT(saveSlot()), QKeySequence("Ctrl+S"));
    fileMenu->addAction("另存为", this, SLOT(saveAsSlot()));
    fileMenu->addAction("关闭", this, SLOT(closeSlot()), QKeySequence("Ctrl+Q"));

    QMenu* styleMenu = menuBar->addMenu("格式(&S)");
    QAction* wrapAction = styleMenu->addAction("换行(W)", [&](bool isChecked){isChecked ? _edit->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere)
                                                                        : _edit->setWordWrapMode(QTextOption::NoWrap);});
    wrapAction->setCheckable(true);
    wrapAction->setChecked(true);

}
void MainWindow::wrapSlot(bool isChecked)
{
    isChecked ? _edit->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere)
              : _edit->setWordWrapMode(QTextOption::NoWrap);
}

void MainWindow::newSlot()
{
    if(_edit->document()->isModified())
    {
        int sb = QMessageBox::warning(this, "是否保存", "是否保存?"
                    , QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);

        switch (sb) {
            case QMessageBox::Save:
                if(_curPath.isEmpty())
                    if(saveAsSlot())
                        break;
                else
                    saveSlot();
            case QMessageBox::No:
                _edit->clear();
                _curPath.clear();
                break;
            default:
                break;
        }

    }
    else
    {
        _edit->clear();
        _curPath.clear();
    }
}

void MainWindow::openSlot()
{
    QString filename = QFileDialog::getOpenFileName(this, "打开", _curPath, "text (*.txt)");
    if(QFileInfo(filename).isFile())
    {   _curPath = filename;
        _file->setFileName(filename);
        _file->open(QIODevice::ReadOnly);
        _edit->setText(_file->readAll());
        _file->close();
    }
}

void MainWindow::saveSlot()
{
    if(_curPath.isEmpty())
        saveAsSlot();
    _file->open(QIODevice::WriteOnly | QIODevice::Truncate);
    _file->write(_edit->toPlainText().toUtf8());
    _file->close();
}

bool MainWindow::saveAsSlot()
{
    QString filename = QFileDialog::getSaveFileName(this, "另存为", _curPath, "text (*.txt)");
    if(QFileInfo(filename).isNativePath())
    {   _curPath = filename;
        _file->setFileName(filename);
        _file->open(QIODevice::WriteOnly | QIODevice::Truncate);
        _file->write(_edit->toPlainText().toUtf8());
        _file->close();
    }
    return filename.isEmpty();
}

void MainWindow::closeSlot()
{

}

MainWindow::~MainWindow()
{

}
