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
#include "qbst.h"

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
    enableBasicOperations();

    insertField->setEnabled(true);
    ui->setupUi(this);
    ui->actionCreate_Random->setEnabled(false);
    disableBasicOperations();
    disableSortings();

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
    btnGo = new QPushButton;

    btnInsert->setText("Insert");
    btnDelete->setText("Delete");
    btnSearch->setText("Search");
    btnNxt->setText("Next step");
    btnPrev->setText("Previous step");
    btnStop->setText("Stop");
    btnGo->setText("Go");
    btnInsert->setIcon(QIcon(":/images/inserir.png"));
    btnDelete->setIcon(QIcon(":/images/delete.png"));
    btnSearch->setIcon(QIcon(":/images/buscar.png"));
    btnNxt->setIcon(QIcon(":/images/green-right-arrow-transparent.png"));
    btnPrev->setIcon(QIcon(":/images/left_arrow.jpg"));
    btnStop->setIcon(QIcon(":/images/stop.png"));
    btnGo->setIcon(QIcon(":/images/go.jpg"));
    connect(btnInsert, SIGNAL(clicked()),this, SLOT(insertData()));
    connect(btnDelete, SIGNAL(clicked()),this, SLOT(deleteData()));
    connect(btnSearch, SIGNAL(clicked()),this, SLOT(searchData()));
    connect(btnStop, SIGNAL(clicked()),this, SLOT(stop()));
    connect(btnNxt,SIGNAL(clicked()),this,SLOT(nxtStep()));
    connect(btnPrev,SIGNAL(clicked()),this,SLOT(prevStep()));
    connect(btnGo,SIGNAL(clicked()),this,SLOT(go()));
    insertField = new QLineEdit;
    insertField->setMinimumSize(100,0);
    insertField->setMaximumWidth(200);
    insertField->setMaxLength(4);
    insertField->setStatusTip("Enter number");

    editToolBar->addWidget(insertField);
    editToolBar->addWidget(btnInsert);
    editToolBar->addWidget(btnDelete);
    editToolBar->addWidget(btnSearch);
    editToolBar->addWidget(btnNxt);
    editToolBar->addWidget(btnPrev);
    editToolBar->addWidget(btnStop);
    editToolBar->addWidget(btnGo);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::disableSortings(){
    ui->actionMergeSort->setEnabled(false);
    ui->actionBubbleSort->setEnabled(false);
    ui->actionInsertionSort->setEnabled(false);
    ui->actionQuickSort->setEnabled(false);
}
void MainWindow::enableSortings(){
    ui->actionMergeSort->setEnabled(true);
    ui->actionBubbleSort->setEnabled(true);
    ui->actionInsertionSort->setEnabled(true);
    ui->actionQuickSort->setEnabled(true);
}
void MainWindow::disableBasicOperations(){
    btnInsert->setEnabled(false);
    btnDelete->setEnabled(false);
    btnSearch->setEnabled(false);
    btnNxt->setEnabled(false);
    btnPrev->setEnabled(false);
    btnStop->setEnabled(false);

}
void MainWindow::enableBasicOperations(){
    btnInsert->setEnabled(true);
    btnDelete->setEnabled(true);
    btnSearch->setEnabled(true);
    btnNxt->setEnabled(true);
    btnPrev->setEnabled(true);
    btnStop->setEnabled(true);

}
void MainWindow::disableCreatingNewFiles(){
   ui->actionAVL->setEnabled(false);
   ui->actionBST->setEnabled(false);
   ui->actionLinkedList->setEnabled(false);
}
void MainWindow::enableCreatingNewFiles(){
   ui->actionAVL->setEnabled(true);
   ui->actionBST->setEnabled(true);
   ui->actionLinkedList->setEnabled(true);
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
    value=insertField->text().toInt();
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();

    for(int i=0;i<windows.size();i++){

         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         if(mdiArea->objectName()=="Sorting Algorithms"){
             if(value<0){
         QMessageBox* msg=new QMessageBox(this);
         msg->setText("Enter number > 0");
         QPushButton* btn=new QPushButton(this);
         btn->setText("Close");
         connect(btn,SIGNAL(clicked()),msg,SLOT(close()));
         msg->exec();
             }
         }
         child->insert(value);
    }

    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
    enableBasicOperations();
    if(isVectorWindow())
        enableSortings();
}
void MainWindow::searchData(int x)
{
    int value=0;

    value=insertField->text().toInt();
    disableBasicOperations();
    disableSortings();
    int res;
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    for(int i=0;i<windows.size();i++){
         QBase *child = qobject_cast<QBase *>(windows[i]->widget());
         res=child->search(value);
    }
    enableBasicOperations();
    if(isVectorWindow())
        enableSortings();

}
void MainWindow::deleteData(int x){
    int value=0;
    value=insertField->text().toInt();
    disableBasicOperations();
    disableSortings();
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
    enableBasicOperations();
    enableSortings();
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


QBase* MainWindow::createBST(){
    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);


    qBst* t=new qBst(nullptr);

    t->setWindowTitle("BST");
    t->setMinimumSize(300,300);
    mdiArea->addSubWindow(t);
    mdiArea->setObjectName("BST");
    t->show();
    enableBasicOperations();
    if(isVectorWindow())
        enableSortings();
    return t;
}
void MainWindow::on_actionBST_triggered()
{
    disableSortings();
    ui->actionCreate_Random->setEnabled(true);
    enableCreatingNewFiles();
    ui->actionDelay->setEnabled(true);
    createBST();
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
    if(isVectorWindow())
        enableSortings();
    return l;
}

QBase* MainWindow::createVector(){


    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);

    Vector* v=new Vector();


    v->setWindowTitle("Sorting Algorithms" );
    v->setMinimumSize(300,300);
    mdiArea->addSubWindow(v);
    mdiArea->setObjectName("Sorting Algorithms");
    v->show();
    enableBasicOperations();

    enableSortings();
    return v;
}
void MainWindow::on_actionLinkedList_triggered()
{
    disableSortings();
    ui->actionDelay->setEnabled(true);
    enableCreatingNewFiles();
    createLinkedList();
}
void MainWindow::on_actionVector_triggered()
{
    enableSortings();
    ui->actionCreate_Random->setEnabled(true);
    enableCreatingNewFiles();
    ui->actionDelay->setEnabled(true);
    createVector();
}

void MainWindow::on_actionInsertionSort_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    disableBasicOperations();
    disableSortings();
    btnStop->setEnabled(true);
    for(int i=0;i<windows.size();i++){
         QBaseSortable *child = dynamic_cast<QBaseSortable *>(windows[i]->widget());
         child->insertionSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
    enableBasicOperations();
    enableSortings();
    btnNxt->setEnabled(true);
    btnPrev->setEnabled(true);
    btnStop->setEnabled(false);
}


void MainWindow::on_actionQuickSort_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    disableBasicOperations();
    disableSortings();
    btnStop->setEnabled(true);

    for(int i=0;i<windows.size();i++){
         QBaseSortable *child = dynamic_cast<QBaseSortable *>(windows[i]->widget());
         child->quickSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
    enableBasicOperations();
    enableSortings();
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

void MainWindow::on_actionMergeSort_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    disableBasicOperations();
    disableSortings();
    btnStop->setEnabled(true);

    for(int i=0;i<windows.size();i++){
         QBaseSortable *child = dynamic_cast<QBaseSortable *>(windows[i]->widget());
         child->mergeSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
    enableBasicOperations();
    enableSortings();
    btnNxt->setEnabled(true);
    btnPrev->setEnabled(true);
    btnStop->setEnabled(false);
}
void MainWindow::on_actionBubbleSort_triggered()
{
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();

    srand(time(NULL));
    disableBasicOperations();
    disableSortings();
    btnStop->setEnabled(true);
    for(int i=0;i<windows.size();i++){
         QBaseSortable *child = dynamic_cast<QBaseSortable *>(windows[i]->widget());
         child->bubbleSort();
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
    enableBasicOperations();
    enableSortings();
    btnNxt->setEnabled(true);
    btnPrev->setEnabled(true);
    btnStop->setEnabled(false);
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
void MainWindow::go(){
    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    algorithms algo;
    int n=insertField->text().toInt();

    for(int i=0;i<windows.size();i++){
         QBaseSortable *child = dynamic_cast<QBaseSortable *>(windows[i]->widget());
         algo = child->getLastAlgorithm();
         child->unStop();
         child->setclearPreviousSteps_(false);
         switch (algo) {
         case algorithms::inserting:
                child->insert(n);
                break;
         case algorithms::deleting:
                child->remove(n);
                break;
         case algorithms::searching:
                child->search(n);
                break;
         case algorithms::bubbleSort:
                child->bubbleSort();
                break;
         case algorithms::insertionSort:
                child->insertionSort();
                break;
         case algorithms::quickSort:
                child->quickSort();
                break;
         case algorithms::mergeSort:
                child->mergeSort();
                break;
         default:
             break;
         }
    }
    for(int i=0;i<windows.size();i++){
        QBase *child = qobject_cast<QBase *>(windows[i]->widget());
        child->update();
    }
    disableBasicOperations();
    disableSortings();
    btnStop->setEnabled(true);
}



