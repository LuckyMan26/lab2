#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QObject>
#include "qbase.h"
class Node;

class LinkedList : public QBaseNonSortable
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
    void clear();
    std::vector<std::vector<int>> getSteps();
    void setFirstStep();
    void setNextStep();
    void setPrevStep();
    void operator=(const LinkedList l){
        this->head=l.head;
    }
signals:

};

#endif // LINKEDLIST_H
