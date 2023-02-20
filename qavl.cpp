#include "qavl.h"
#include "qtnode.h"
#include <cmath>
int height(qTNode* n){
if(n==nullptr){
    return 0;
}
return n->getHeight();
}
qAVL::qAVL()
{
    this->root=nullptr;

}

qTNode* qAVL::left_rotate(qTNode* x)
{
    qTNode *y =  x->right;
    qTNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->setHeight( std::max(height(x->left),
                    height(x->right)) + 1);
    y->setHeight(std::max(height(y->left),
                    height(y->right)) + 1);

    return y;
}
qTNode* newNode(int key){
    qTNode* node = new qTNode(key);
    node->setHeight(1);
    node->left = nullptr;
    node->right = nullptr;
    return(node);
}
qTNode* qAVL::right_rotate(qTNode *y)
{
    qTNode *x = y->left;
    qTNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->setHeight(std::max(height(y->left),
                    height(y->right)) + 1);
    x->setHeight(std::max(height(x->left),
                    height(x->right)) + 1);

    return x;
}
int qAVL::getBalance(qTNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}
qTNode* qAVL::insert(int key,qTNode* node){
if(node==nullptr){
    return(newNode(key));
}
else if((node->getData()>key)){
    node->left=insert(key,node->left);
}
else if(node->getData()<key){
    node->right=insert(key,node->right);
}
else{
    return node;
}
node->setHeight(1+std::max(height(node->left),height(node->right)));
int balance=getBalance(node);
if(balance>1 && key<node->left->getData()){
    return right_rotate(node);
}
if(balance<-1 && key>node->right->getData()){
    return left_rotate(node);
}
if(balance>1 && key>node->left->getData()){
    node->left=left_rotate(node->left);
    return right_rotate(node);
}
if(balance<-1 && key<node->right->getData()){
    node->right=right_rotate(node->right);
    return left_rotate(node);
}
return node;
}
void qAVL::insert(int key){
root=insert(key,root);
}


qTNode* qAVL::minValueNode(qTNode* node){
qTNode* curr=node;
while(curr->left!=NULL){
    curr=curr->left;
}
return curr;
}
qTNode* qAVL::DelNode(qTNode* r,int key){
if(r==nullptr){
    return r;
}
if(key<r->getData()){
    r->left=DelNode(r->left,key);
}
if(key>r->getData()){
    r->right=DelNode(r->right,key);
}
else{
    if((r->left==NULL)||(r->right==NULL)){
        qTNode* temp=r->left ?
                     r->left :
                     r->right;
        if(temp==NULL){
            temp=r;
            r=NULL;
        }
        else{

            delete r;
            delete temp;
        }
    }
    else{
    qTNode* temp=minValueNode(r->right);

    r->setData(temp->getData());

    r->right=DelNode(r->right,temp->getData());
}
}
if(r==NULL){
    return r;
}
r->setHeight(1+std::max(height(r->left),height(r->right)));

int balance=height(r->left)-height(r->right);
if (balance > 1 &&getBalance(r->left) >= 0)
        return right_rotate(r);

    if (balance > 1 && getBalance(r->left) < 0)
    {
        r->left = left_rotate(r->left);
        return right_rotate(r);
    }

    if (balance < -1 && getBalance(r->right) <= 0)
        return left_rotate(r);

    if (balance < -1 && getBalance(r->right) > 0)
    {
        r->right = right_rotate(r->right);
        return left_rotate(r);
    }
    return r;
}
void qAVL::remove(int key){
this->DelNode(this->root,key);
}

qTNode* qAVL::search(qTNode* r,int key){
if(r){
if(r->getData()==key){
    return r;
}
 if(r->getData()<key){
   return(search(r->right,key));
}
else if(r->getData()>key){
    return(search(r->left,key));
}
}
else{

    return nullptr;
}
}
qTNode* qAVL::search(int key){
return this->search(this->root,key);
}

