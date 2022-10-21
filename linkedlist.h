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
    int search(int x);
    void remove(int x);
    void bubbleSort();
    void insertionSort();
    void quickSort();
    void mergeSort();
    void createRand(int size);
    void operator=(const LinkedList l){
        this->head=l.head;
    }
signals:

};

#endif // LINKEDLIST_H
