#include "qbst.h"
#include <iostream>
qBst::qBst():
    QBase()
{
this->root=nullptr;
}
qBst::qBst(qTNode* r){
    this->root=r;
}
void qBst::insert(int data,qTNode* cur){
   if(cur){
   if(cur->getData() < data){
       if(cur->right){
           insert(data,cur->right);
       }
       else{
           qTNode* node=new qTNode(data);
           node->left=nullptr;
           node->right=nullptr;
           cur->right=node;
           int x=cur->getX();
           int y=cur->getY();
           node->SetX(x+40);
           node->SetY(y+30);
           scene()->addItem(node);
           return;
       }
   }
   else{
       if(cur->left){
            insert(data,cur->left);
       }
       else{
           qTNode* node=new qTNode(data);
           node->left=nullptr;
           node->right=nullptr;
           cur->left=node;
           int x=cur->getX();
           int y=cur->getY();
           node->SetX(x-40);
           node->SetY(y+30);
           scene()->addItem(node);
           return;
       }
   }
   }
}
void qBst::insert(int x){
if(!root){
    qTNode* node=new qTNode(x);
    root=node;
    getScene()->addItem(root);
}
else{
    insert(x,root);
}
}
int qBst::search(int x){
return -1;
}
void qBst::remove(int x){

}
void qBst::bubbleSort(){

}
void qBst::insertionSort(){

}
void qBst::mergeSort(){

}
void qBst::quickSort(){

}
void qBst::createRand(int size){

}
void qBst::setFirstStep(){

}
void qBst::setNextStep(){

}
void qBst::setPrevStep(){

}
std::vector<std::vector<int>> qBst::getSteps(){
    return {};
}
