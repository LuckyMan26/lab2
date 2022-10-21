#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBox>
#include <QtGui>
#include <QStack>
#include <QPushButton>
#include <QLineEdit>
#include <QMdiArea>
#include <QActionGroup>
#include "qbase.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSignalMapper *windowMapper;

    QToolBox *toolBox;

    QToolBar* editToolBar;

    QStatusBar* statusBar;

    QPushButton* btnInsert;
    QPushButton* btnDelete;
    QPushButton* btnSearch;
    QMdiArea* mdiArea=nullptr;
    QLineEdit* lneInserir;
    QPushButton* btnNxt;
    QPushButton* btnPrev;


    QAction* newAct;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createMenus();
    void createToolBox();
    void createStatusBar();
    void createToolBar();
    void createAction();
    void setActiveSubWindow(QWidget *window);
    private slots:
    void insertData(int x=0);
    void searchData(int x=0);
    void deleteData(int x=0);

    QBase* createLinkedList();
    QBase* createVector();

    void on_actionLinkedList_triggered();

    void on_actionVector_triggered();

    void on_actionBubbleSort_triggered();

    void on_actionInsertionSort_triggered();

    void on_actionQuickSort_triggered();

    void on_actionCreate_Random_triggered();

    void on_actionMergeSort_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
