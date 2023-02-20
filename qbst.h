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
    void remove(int x,qTNode** cur,qTNode** parent);
    void removeSubTree(qTNode* cur);
    qTNode* minValueNode(qTNode* node);
    int quantNode(qTNode* node);
    int typeOfJustify = 0;
public:
    qBst();
    qBst(qTNode* r=nullptr);
    void insert(int x);
    int search(int x);
    void remove(int x);
    void createRand(int size);
    std::vector<std::vector<int>> getSteps();
    void setFirstStep();
    void setNextStep();
    void setPrevStep();
    void justifyComplete(qTNode* node, int x);
    void justifyStandart(qTNode* node,int x);
    int height(qTNode* node);

};

#endif // QBST_H
