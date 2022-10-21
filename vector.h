#ifndef VECTOR_H
#define VECTOR_H

#include "qbase.h"
#include <vector>
#include "vectornode.h"
class vectorNode;
class Vector: public QBase
{
    std::vector<vectorNode*> v;
    void qSort(std::vector<vectorNode*> vec,int low,int high);
    void merge(std::vector<vectorNode*> vec,vectorNode* tmp,int low, int mid, int high);
public:
    Vector();
    void insert(int x);
    int search(int x);
    void remove(int x);
    void bubbleSort();
    void insertionSort();
    void quickSort();
    void mergeSort();

    void createRand(int size);

    void scaleView(qreal scaleFactor);

    void zoomIn(void);
    void zoomOut(void);
    void update(void);

};

#endif // VECTOR_H
