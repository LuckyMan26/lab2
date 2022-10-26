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
    QPushButton* btnStop;
    QMdiArea* mdiArea=nullptr;
    QLineEdit* lneInserir;
    QPushButton* btnNxt;
    QPushButton* btnPrev;

    QMenu* mainMenu;
    QMenu* fileMenu;
    QMenu* sortingMenu;
    QMenu* createRandMenu;
    QAction* newAct;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createMenus();
    void createToolBox();
    void createStatusBar();
    void createToolBar();
    void createAction();
    void updateMenus();
    void setActiveSubWindow(QWidget *window);
    private slots:
    void insertData(int x=0);
    void searchData(int x=0);
    void deleteData(int x=0);
    void nxtStep();
    void prevStep();
    bool activeMdiChild(void);
    bool isLinkedListWindow(void);
    bool isVectorWindow(void);
    QBase* createLinkedList();
    QBase* createVector();
    void stop(void);
    void EnableMenus(void);
    void on_actionLinkedList_triggered();

    void on_actionVector_triggered();

    void on_actionBubbleSort_triggered();
    void disableMenus();
    void on_actionCreate_Random_triggered();

    void on_actionBubbleSort_2_triggered();

    void on_actionSteps_2_triggered();

    void on_actionInsertionSort_2_triggered();

    void on_actionQuickSort_2_triggered();

    void on_actionMergeSort_2_triggered();

    void on_actionStep_triggered();

    void on_actionSteps_triggered();

    void on_actionSteps_3_triggered();

    void on_actionDelay_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
