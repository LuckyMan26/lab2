#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractTableModel>
#include <QListView>
#include <QSplitter>
#include <QToolBar>
#include <QMenuBar>
#include <QWidget>
#include <QtGui>
#include <QMdiSubWindow>
#include "linkedlist.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    /*Coloca o MdiArea como sendo principal na janela*/

    windowMapper = new QSignalMapper(this);
    connect(windowMapper, SIGNAL(mapped(QWidget*)),this, SLOT(setActiveSubWindow(QWidget*)));
    //createAction();
    createMenus();
    createToolBox();
    createStatusBar();
    createToolBar();

    setWindowIcon(QIcon(tr(":/images/logotipo_base2.png")));
    setWindowTitle(tr("QWood"));


    ui->setupUi(this);
}
void MainWindow::createAction(){
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    //connect(newAct,SIGNAL(triggered), this, SLOT(close()));

}
void MainWindow::setActiveSubWindow(QWidget *window)
{
    if (!window) return;
    mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}
void MainWindow::createMenus()
{



}
void MainWindow::createToolBox()
{
    toolBox = new QToolBox;
    toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
}
void MainWindow::createStatusBar()
{
    statusBar =  new QStatusBar;
    setStatusBar(statusBar);
}
void MainWindow::createToolBar()
{
    editToolBar = addToolBar(tr("Principal"));

    /*Botões da Janela*/
    btnInsert = new QPushButton;
    btnDelete = new QPushButton;
    btnSearch = new QPushButton;
    /*Adiciona texto ao botões criado*/
    btnInsert->setText("Insert");
    btnDelete->setText("Delete");
    btnSearch->setText("Search");
    /*Adiciona os ícones nos botões*/

    btnInsert->setIcon(QIcon(":/images/inserir.png"));
    btnDelete->setIcon(QIcon(":/images/delete.png"));
    btnSearch->setIcon(QIcon(":/images/buscar.png"));
    /*Adiciona os eventos aos botões*/
   connect(btnInsert, SIGNAL(clicked()),this, SLOT(insertData()));
   connect(btnDelete, SIGNAL(clicked()),this, SLOT(this->close()));

    /*Entrada de Dados*/
    lneInserir = new QLineEdit;
    lneInserir->setMinimumSize(100,0);
    lneInserir->setMaximumWidth(200);
    lneInserir->setMaxLength(4);
    lneInserir->setStatusTip("Enter number");




    /*Adiciona os botões ao ToolBar "EDIT"*/
    editToolBar->addWidget(lneInserir);
    editToolBar->addWidget(btnInsert);
    editToolBar->addWidget(btnDelete);
    editToolBar->addWidget(btnSearch);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::insertData(int x)
{

    int value=lneInserir->text().toInt();
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->insert(value);
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}

QBase* MainWindow::createLinkedList(){

    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);
    windowMapper = new QSignalMapper(this);
    connect(windowMapper, SIGNAL(mapped(QWidget*)),this, SLOT(setActiveSubWindow(QWidget*)));

    LinkedList* l=new LinkedList();

    l->setWindowTitle("LinkedList");
    l->setMinimumSize(300,300);
    mdiArea->addSubWindow(l);

    l->show();

    return l;
}
void MainWindow::on_actionLinkedList_triggered()
{
   createLinkedList();
}

