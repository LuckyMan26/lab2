#include "mainwindow.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int b=2;
    int c=3;
    b+=c;
    c+=b;
    std::cout<<b<<std::endl;
    w.show();
    return a.exec();
}
