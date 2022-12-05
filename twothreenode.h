#ifndef TWOTHREENODE_H
#define TWOTHREENODE_H


class TwoThreeNode
{
    int size;

public:
int key[3];
TwoThreeNode* first;
TwoThreeNode* second;
TwoThreeNode* third;
TwoThreeNode* fourth;
TwoThreeNode* parent;

    TwoThreeNode(int k);
    TwoThreeNode(int k,TwoThreeNode* f,TwoThreeNode* s,TwoThreeNode* t,TwoThreeNode* fourt_,TwoThreeNode* p);
    bool find(int elem);
    void sort();
    void insert(int elem);
    void remove(int k);
    void Convert2TwoThreeNode(int elem,TwoThreeNode* f,TwoThreeNode* s);
    bool is_leaf();
    int getSize();
    void setSize(int x);
};

#endif // TWOTHREENODE_H
