#ifndef QBST_H
#define QBST_H

#include "qbase.h"
#include "qtnode.h"
#include <vector>
class qTNode;
class qBst: public QBase
{
    qTNode* root;
    void insert(int data,qTNode* cur);
    void search(int x,qTNode* cur);
    qTNode* remove(int x,qTNode* cur);
    void removeSubTree(qTNode* cur);
    qTNode* minValueNode(qTNode* node);
public:
    qBst();
    qBst(qTNode* r=nullptr);
    void insert(int x);
    int search(int x);
    void remove(int x);
    void bubbleSort();
    void insertionSort();
    void quickSort();
    void mergeSort();
    void createRand(int size);
    std::vector<std::vector<int>> getSteps();
    void setFirstStep();
    void setNextStep();
    void setPrevStep();

};

#endif // QBST_H
