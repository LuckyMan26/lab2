#include "mainwindow.h"
#include "delaywindow.h"
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
#include "dialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    mdiArea = new QMdiArea;
    windowMapper = new QSignalMapper(this);
   // connect(windowMapper, SIGNAL(mapped(QWidget*)),this, SLOT(setActiveSubWindow(QWidget*)));

    createMenus();
    createToolBox();
    createStatusBar();
    createToolBar();
    updateMenus();

    ui->setupUi(this);
    ui->actionCreate_Random->setEnabled(false);
    ui->actionDelay->setEnabled(false);
    ui->actionStep->setEnabled(false);
    ui->actionMergeSort_2->setEnabled(false);
    ui->actionBubbleSort_2->setEnabled(false);
    ui->actionInsertionSort_2->setEnabled(false);
    ui->actionQuickSort_2->setEnabled(false);
    ui->actionSteps->setEnabled(false);
    ui->actionSteps_2->setEnabled(false);
    ui->actionSteps_3->setEnabled(false);
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
    mainMenu=new QMenu();
    mainMenu=menuBar()->addMenu(tr("&Arquivo"));
    //mainMenu->addAction(newAct);
    fileMenu=mainMenu->addMenu(tr("&Novo"));
    mainMenu->addSeparator();
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
    if (mdiArea->isActiveWindow()){
        return true;
    }
    return false;
}
bool MainWindow::isLinkedListWindow(void){
    if (mdiArea->isActiveWindow()){
       if(mdiArea->objectName()=="LinkedList"){
           return true;
       }
    }
    return false;
}
bool MainWindow::isVectorWindow(void){
    if (mdiArea->isActiveWindow()){
       if((mdiArea->objectName()=="Sorting Algorithms")){
           return true;
       }
    }
    return false;
}

void MainWindow::updateMenus(void){
     bool hasMdiChild = (activeMdiChild());    
     bool isVector = isVectorWindow();
     btnInsert->setEnabled(hasMdiChild);
     btnDelete->setEnabled(hasMdiChild);
     btnSearch->setEnabled(hasMdiChild);
     btnNxt->setEnabled(false);
     btnPrev->setEnabled(false);
     btnStop->setEnabled(false);
     lneInserir->clear();
     lneInserir->setEnabled(hasMdiChild);


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
     updateMenus();
}
void MainWindow::searchData(int x)
{
    int value=0;
    disableMenus();
    value=lneInserir->text().toInt();
    std::cout<<value<<std::endl;
    int res;
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         res=child->search(value);
    }
    EnableMenus();

}
void MainWindow::deleteData(int x){
    int value=0;
    value=lneInserir->text().toInt();
    std::cout<<value<<std::endl;
    disableMenus();
    btnStop->setEnabled(false);
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->remove(value);
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
    EnableMenus();
}
void MainWindow::stop(void){
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->Stop();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}
void MainWindow::disableMenus(){

    btnInsert->setEnabled(false);
    btnDelete->setEnabled(false);
    btnSearch->setEnabled(false);
    btnNxt->setEnabled(false);
    btnPrev->setEnabled(false);
    btnStop->setEnabled(true);
    lneInserir->clear();
    lneInserir->setEnabled(false);
    ui->actionStep->setEnabled(false);
    ui->actionMergeSort_2->setEnabled(false);
    ui->actionBubbleSort_2->setEnabled(false);
    ui->actionInsertionSort_2->setEnabled(false);
    ui->actionQuickSort_2->setEnabled(false);
    ui->actionCreate_Random->setEnabled(false);
    ui->actionLinkedList->setEnabled(false);
    ui->actionSteps->setEnabled(false);
    ui->actionSteps_2->setEnabled(false);
    ui->actionSteps_3->setEnabled(false);
    ui->actionVector_2->setEnabled(false);
    ui->actionVector->setEnabled(false);
    ui->actionCreate_Random->setEnabled(false);
}
void MainWindow::EnableMenus(void){

    btnInsert->setEnabled(true);
    btnDelete->setEnabled(true);
    btnSearch->setEnabled(true);
    btnNxt->setEnabled(true);
    btnPrev->setEnabled(true);
    btnStop->setEnabled(true);
    lneInserir->clear();
    lneInserir->setEnabled(true);
    ui->actionStep->setEnabled(true);
    ui->actionMergeSort_2->setEnabled(true);
    ui->actionBubbleSort_2->setEnabled(true);
    ui->actionInsertionSort_2->setEnabled(true);
    ui->actionQuickSort_2->setEnabled(true);
    ui->actionCreate_Random->setEnabled(true);
    ui->actionLinkedList->setEnabled(true);
    ui->actionSteps->setEnabled(true);
    ui->actionSteps_2->setEnabled(true);
    ui->actionSteps_3->setEnabled(true);
    ui->actionVector_2->setEnabled(true);
    ui->actionVector->setEnabled(true);
    ui->actionCreate_Random->setEnabled(true);
}
QBase* MainWindow::createLinkedList(){

    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);


    LinkedList* l=new LinkedList();

    l->setWindowTitle("LinkedList");
    l->setMinimumSize(300,300);
    mdiArea->addSubWindow(l);
    mdiArea->setObjectName("LinkedList");
    l->show();
    updateMenus();
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
    mdiArea->setObjectName("Sorting Algorithms");
    v->show();
    updateMenus();
    return v;

}
void MainWindow::on_actionLinkedList_triggered()
{
    ui->actionStep->setEnabled(false);
    ui->actionMergeSort_2->setEnabled(false);
    ui->actionBubbleSort_2->setEnabled(false);
    ui->actionInsertionSort_2->setEnabled(false);
    ui->actionQuickSort_2->setEnabled(false);
    ui->actionCreate_Random->setEnabled(true);
    ui->actionLinkedList->setEnabled(false);
    ui->actionSteps->setEnabled(false);
    ui->actionSteps_2->setEnabled(false);
    ui->actionSteps_3->setEnabled(false);
    ui->actionDelay->setEnabled(true);
   createLinkedList();
}


void MainWindow::on_actionVector_triggered()
{
    ui->actionStep->setEnabled(true);
    ui->actionMergeSort_2->setEnabled(true);
    ui->actionBubbleSort_2->setEnabled(true);
    ui->actionInsertionSort_2->setEnabled(true);
    ui->actionQuickSort_2->setEnabled(true);
    ui->actionCreate_Random->setEnabled(true);
    ui->actionLinkedList->setEnabled(true);
    ui->actionSteps->setEnabled(true);
    ui->actionSteps_2->setEnabled(true);
    ui->actionSteps_3->setEnabled(true);
    ui->actionDelay->setEnabled(true);
    createVector();
}


void MainWindow::on_actionBubbleSort_triggered()
{

    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    QThread thread;
    srand(time(NULL));
    for(int i=0;i<windows.size();i++){

        if(isVectorWindow()){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());

         child->bubbleSort();
        }
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}


void MainWindow::on_actionInsertionSort_2_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    disableMenus();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->insertionSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
    EnableMenus();
    btnNxt->setEnabled(true);
    btnPrev->setEnabled(true);
    btnStop->setEnabled(false);
}


void MainWindow::on_actionQuickSort_2_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    disableMenus();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->quickSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
    EnableMenus();
    btnNxt->setEnabled(true);
    btnPrev->setEnabled(true);
    btnStop->setEnabled(false);
}


void MainWindow::on_actionCreate_Random_triggered()
{

    int value=0;

    Dialog dialog;

    dialog.exec();

    value=dialog.getSize();
    std::cout<<value<<std::endl;
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
    disableMenus();


    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->mergeSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
    EnableMenus();
    btnNxt->setEnabled(true);
    btnPrev->setEnabled(true);
    btnStop->setEnabled(false);
}


void MainWindow::on_actionBubbleSort_2_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();

    srand(time(NULL));
    disableMenus();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->bubbleSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
    EnableMenus();
    btnNxt->setEnabled(true);
    btnPrev->setEnabled(true);
    btnStop->setEnabled(false);
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

    }
    btnNxt->setEnabled(true);
    btnPrev->setEnabled(true);

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


void MainWindow::on_actionDelay_triggered()
{
    delayWindow dialog;
    int value;
    dialog.exec();
    value=dialog.getDelay();
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         child->setDelay(value);
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
}

