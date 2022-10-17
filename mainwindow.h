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
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QToolBox *toolBox;

    QToolBar* editToolBar;

    QStatusBar* statusBar;

    QMenuBar* menu_bar;
    QPushButton* btnInsert;
    QPushButton* btnDelete;
    QPushButton* btnSearch;
    QMdiArea* mdiArea;
    QLineEdit* lneInserir;

    QMenu* arquivoMenu;
    QMenu* editarMenu;
    QMenu* alinharMenu;
    QMenu* novoMenu;
    QMenu* windowsMenu;
    QMenu* configuracoesMenu;
    QMenu* ajudaMenu;
    QMenu* alinhamentoMenu;

    QAction* newAct;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createMenus();
    void createToolBox();
    void createStatusBar();
    void createToolBar();
    void createAction();
    private slots:
     void abrirArquivo(void);
     void on_actionLinkedList_triggered();
protected:
     QBase* createLinkedList(void);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
