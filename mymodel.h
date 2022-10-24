#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include "linkedlist.h"
class MyModel : public QAbstractTableModel
{
private:
     LinkedList list;
public:
    explicit MyModel(QObject *parent = nullptr);

    void setTable();
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
};

#endif // MYMODEL_H
