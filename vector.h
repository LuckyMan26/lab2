#ifndef VECTOR_H
#define VECTOR_H

#include "qbase.h"
#include <vector>
#include "vectornode.h"

using namespace std;
class vectorNode;
class Vector: public QBase
{
    std::vector<vectorNode*> v;
    void qSort(std::vector<vectorNode*>& vec,int low,int high);
    void merge(std::vector<vectorNode*> vec,vectorNode* tmp,int low, int mid, int high);
    vector<vector<int>> vec;
    int curStep=0;
public:
    Vector();
    void insert(int x);
    int search(int x);
    void remove(int x);
private slots:
    void bubbleSort();
    void insertionSort();
    void quickSort();
    void mergeSort();

    void createRand(int size);

    void scaleView(qreal scaleFactor);

    void zoomIn(void);
    void zoomOut(void);
    void update(void);
    std::vector<std::vector<int>> getSteps();
    void setFirstStep();
    void setNextStep();
    void setPrevStep();
private:
    void bubbleSort(std::vector<int> v1);
    void insertionSort(std::vector<int> v1);
    void quickSort(std::vector<int> v1);
    void qSort(std::vector<int>& v1,int low,int high);
    void merge(std::vector<int>& vec,int* tmp,int low, int mid, int high);
};

#endif // VECTOR_H
