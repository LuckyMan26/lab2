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
    scene()->addItem(root);
}
else{
    insert(x,root);
}
}
int qBst::search(int x){
search(x,root);
return -1;
}
void qBst::search(int x,qTNode* cur){
         std::cout<<"Found"<<std::endl;
        wait(getDelay());
        cur->setCond(1);
        this->repaint();
        if(cur->getData()==x){
            std::cout<<"Found"<<std::endl;
            cur->setCond(2);
            this->repaint();
            return;
        }
        if(cur->getData()<x){
            if(cur->right){
            cur->setCond(0);

            search(x,cur->right);
            }
            if(!cur->right){
            cur->setCond(0);
            return;
            }

        }
        if(cur->getData()>x){
            if(cur->left){
            cur->setCond(0);
            search(x,cur->left);
            }
            if(!cur->left){
            cur->setCond(0);
            return;
            }

        }

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
