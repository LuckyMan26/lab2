#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QTableView>
#include <QModelIndex>
#include "linkedlist.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;



    w.show();
    return a.exec();
}
