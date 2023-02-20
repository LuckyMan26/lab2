#ifndef VECTOR_H
#define VECTOR_H

#include "qbase.h"
#include <vector>
#include "vectornode.h"

using namespace std;
class vectorNode;
class Vector: public QBaseSortable
{
    std::vector<vectorNode*> v;
    void qSort(int low,int high);
    void merge(std::vector<vectorNode> vec,vectorNode* tmp,int low, int mid, int high);
    vector<vector<vectorNode>> steps;

    int curStep=0;
public:
    Vector();
    Vector( int size);
    ~Vector();
    void insert(int x);
    int search(int x);
    void remove(int x);
private slots:

    void bubbleSort();
    void insertionSort();
    void quickSort();
    void mergeSort();
    void processEvents(void);
    void createRand(int size);

    void scaleView(qreal scaleFactor);

    void zoomIn(void);
    void zoomOut(void);
    void update(void);
    std::vector<std::vector<vectorNode>> getSteps();
    void setFirstStep();
    void setNextStep();
    void setPrevStep();
    void setSteps();

private:
    void wait(int interval);
    void getBubbleSortSteps();
    void getInsertionSortSteps();
    void getQuickSortSteps();
    void getMergeSortSteps();

    void mergeSort_();
    int getCurStep(void);
};

#endif // VECTOR_H
