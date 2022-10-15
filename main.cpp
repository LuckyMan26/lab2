#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include "linkedlist.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LinkedList l(nullptr,nullptr);
    l.append(2);
    l.append(5);
    l.append(8);
    l.append(3);
    l.print();
    w.show();
    return a.exec();
}
