#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QObject>
#include "node.h"
class LinkedList : public QObject
{
    Q_OBJECT
    Node* head=nullptr;
public:
    LinkedList(Node* head=nullptr,QObject *parent = nullptr);

    void append(int n);
    void print();
    int getLength() const;
    void operator=(const LinkedList l){
        this->head=l.head;
    }
signals:

};

#endif // LINKEDLIST_H
