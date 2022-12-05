#ifndef QAVL_H
#define QAVL_H

class qTNode;
class qAVL
{
    qTNode* root;
    qTNode* insert(int key,qTNode* node);
    qTNode* DelNode(qTNode* r,int key);
    qTNode* search(qTNode* r,int key);

public:
    qAVL();
    qTNode* left_rotate(qTNode *x);
    qTNode* right_rotate(qTNode *x);
    int getBalance(qTNode *N);
    void insert(int key);
    qTNode* minValueNode(qTNode* node);
    void remove(int key);
    qTNode* search(int key);

};

#endif // QAVL_H
