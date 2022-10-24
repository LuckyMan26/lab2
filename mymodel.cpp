#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}
int MyModel::rowCount(const QModelIndex &parent) const
{
    int len=this->list.getLength();
    return parent.isValid() ? 0 : len;
}
int MyModel::columnCount(const QModelIndex &parent) const
{

    return parent.isValid() ? 0 : 2;
}
void MyModel::setTable(){
    int length=list.getLength();

}
