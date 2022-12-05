#ifndef TWOTHREETREE_H
#define TWOTHREETREE_H

#include "twothreenode.h"
class TwoThreeNode;
class TwoThreeTree
{
    TwoThreeNode* root;
    TwoThreeNode* insert(TwoThreeNode* r,int elem);
    TwoThreeNode* search(TwoThreeNode* r,int k);
    TwoThreeNode* remove(TwoThreeNode* r,int elem);

public:
    TwoThreeTree();
    TwoThreeNode* split(TwoThreeNode* item);
    void  insert(int elem);
    TwoThreeNode * search_min(TwoThreeNode *p);
    TwoThreeNode* redistribute(TwoThreeNode *leaf);
    TwoThreeNode* merge(TwoThreeNode *leaf);
    TwoThreeNode* fix(TwoThreeNode* leaf);
    void remove(int elem);
    TwoThreeNode* search(int k);
};

#endif // TWOTHREETREE_H
