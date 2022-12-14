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
#include <QThread>
#include "linkedlist.h"
#include <iostream>
#include "vector.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{



    windowMapper = new QSignalMapper(this);
    connect(windowMapper, SIGNAL(mapped(QWidget*)),this, SLOT(setActiveSubWindow(QWidget*)));

    createMenus();
    createToolBox();
    createStatusBar();
    createToolBar();
    //updateMenus();
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

    btnInsert = new QPushButton;
    btnDelete = new QPushButton;
    btnSearch = new QPushButton;
    btnNxt=new QPushButton;
    btnPrev=new QPushButton;
    btnStop = new QPushButton;
    btnInsert->setText("Insert");
    btnDelete->setText("Delete");
    btnSearch->setText("Search");
    btnNxt->setText("Next step");
    btnPrev->setText("Previous step");
    btnStop->setText("Stop");
    btnInsert->setIcon(QIcon(":/images/inserir.png"));
    btnDelete->setIcon(QIcon(":/images/delete.png"));
    btnSearch->setIcon(QIcon(":/images/buscar.png"));
    btnNxt->setIcon(QIcon(":/images/green-right-arrow-transparent.png"));
    btnPrev->setIcon(QIcon(":/images/left_arrow.jpg"));
    btnStop->setIcon(QIcon(":/images/stop.png"));
    connect(btnInsert, SIGNAL(clicked()),this, SLOT(insertData()));
    connect(btnDelete, SIGNAL(clicked()),this, SLOT(deleteData()));
    connect(btnSearch, SIGNAL(clicked()),this, SLOT(searchData()));
    connect(btnStop, SIGNAL(clicked()),this, SLOT(stop()));
    connect(btnNxt,SIGNAL(clicked()),this,SLOT(nxtStep()));
    connect(btnPrev,SIGNAL(clicked()),this,SLOT(prevStep()));
    lneInserir = new QLineEdit;
    lneInserir->setMinimumSize(100,0);
    lneInserir->setMaximumWidth(200);
    lneInserir->setMaxLength(4);
    lneInserir->setStatusTip("Enter number");




    editToolBar->addWidget(lneInserir);
    editToolBar->addWidget(btnInsert);
    editToolBar->addWidget(btnDelete);
    editToolBar->addWidget(btnSearch);
    editToolBar->addWidget(btnNxt);
    editToolBar->addWidget(btnPrev);
    editToolBar->addWidget(btnStop);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::activeMdiChild(){
    if (QMdiSubWindow *activeSubWindow = mdiArea->activeSubWindow()){
        return true;
    }
    return false;
}
void MainWindow::updateMenus(){
     bool hasMdiChild = (activeMdiChild());
     btnInsert->setEnabled(hasMdiChild);
     btnDelete->setEnabled(hasMdiChild);
     btnSearch->setEnabled(hasMdiChild);
}
void MainWindow::nxtStep(){
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->setNextStep();
    }

    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}
void MainWindow::prevStep(){
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->setPrevStep();
    }

    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}
void MainWindow::insertData(int x)
{
    int value=0;

    value=lneInserir->text().toInt();
    std::cout<<"value"<<std::endl;
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
void MainWindow::searchData(int x)
{
    int value=0;

    value=lneInserir->text().toInt();
    std::cout<<value<<std::endl;
    int res;
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         res=child->search(value);
    }

}
void MainWindow::deleteData(int x){
    int value=0;
    value=lneInserir->text().toInt();
    std::cout<<value<<std::endl;
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->remove(value);
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}
/*void MainWindow::stop(){
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->stop();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}*/
QBase* MainWindow::createLinkedList(){

    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);


    LinkedList* l=new LinkedList();

    l->setWindowTitle("LinkedList");
    l->setMinimumSize(300,300);
    mdiArea->addSubWindow(l);

    l->show();
    return l;
}
QBase* MainWindow::createVector(){


    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);

    Vector* v=new Vector();


    v->setWindowTitle("Sorting Algorithms");
    v->setMinimumSize(300,300);
    mdiArea->addSubWindow(v);
    v->show();
    return v;

}
void MainWindow::on_actionLinkedList_triggered()
{
   createLinkedList();
}


void MainWindow::on_actionVector_triggered()
{
    createVector();
}


void MainWindow::on_actionBubbleSort_triggered()
{

    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    QThread thread;
    srand(time(NULL));
    for(int i=0;i<windows.size();i++){


         QBase *child = qobject_cast<QBase *>(windows[i]->widget());

         child->bubbleSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}


void MainWindow::on_actionInsertionSort_2_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->insertionSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}


void MainWindow::on_actionQuickSort_2_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->quickSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}


void MainWindow::on_actionCreate_Random_triggered()
{
    int value=0;
    value=lneInserir->text().toInt();
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->createRand(value);
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}


void MainWindow::on_actionMergeSort_2_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->mergeSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}


void MainWindow::on_actionBubbleSort_2_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();

    srand(time(NULL));
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->bubbleSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}


void MainWindow::on_actionSteps_2_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    QThread thread;
    srand(time(NULL));

    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->makeStepRegime();
         child->bubbleSort();

    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->setFirstStep();
    }

}


void MainWindow::on_actionStep_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    QThread thread;
    srand(time(NULL));

    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->makeStepRegime();
         child->insertionSort();

    }
    std::cout<<"Hello";
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->setFirstStep();
    }
}


void MainWindow::on_actionSteps_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    QThread thread;
    srand(time(NULL));

    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->makeStepRegime();
         child->quickSort();

    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->setFirstStep();
    }
}


void MainWindow::on_actionSteps_3_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    QThread thread;
    srand(time(NULL));

    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->makeStepRegime();
         child->mergeSort();

    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->setFirstStep();
    }
}

