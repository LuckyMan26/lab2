#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QObject>
#include "qbase.h"
class Node;

class LinkedList : public QBase
{
    Node* head=nullptr;
public:
    LinkedList(Node* head=nullptr);

    void insert(int n);
    void print();
    int getLength() const;
    void operator=(const LinkedList l){
        this->head=l.head;
    }
signals:

};

#endif // LINKEDLIST_H
