#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QObject>
#include "node.h"
class LinkedList : public QObject
{
    Q_OBJECT
    Node* head=nullptr;
public:
    explicit LinkedList(Node* head=nullptr,QObject *parent = nullptr);
    explicit LinkedList();
    void append(int n);
    void print();
signals:

};

#endif // LINKEDLIST_H
