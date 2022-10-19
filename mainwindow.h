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
    QMdiArea* mdiArea;
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
     void on_actionLinkedList_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
