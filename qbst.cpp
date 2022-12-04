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
root=remove(x,root);
this->repaint();
}
void qBst::removeSubTree(qTNode* cur){
    if(cur){

        if(cur->right){
            removeSubTree(cur->right);
        }
        if(cur->left){
            removeSubTree(cur->left);
        }
        delete cur;
        return;
    }
}
qTNode* qBst::minValueNode(qTNode* node){
     qTNode* current = node;

       while (current && current->left != NULL)
           current = current->left;

       return current;
}
qTNode* qBst::remove(int x,qTNode* cur){
    if (cur == NULL){
        return cur;
    }

        if (x < cur->getData())
           cur->left=remove(x,cur->left);

        else if (x > cur->getData())
            cur->right=remove(x,cur->right);


        else {
            if (cur->left == NULL and cur->right == NULL){
                this->repaint();

                return nullptr;
            }

            else if (cur->left == NULL) {
                qTNode* temp = cur->right;
                delete cur;
                this->repaint();
                return temp;
            }
            else if (cur->right == NULL) {
                qTNode* temp = cur->left;
                delete cur;
                this->repaint();
                return temp;
            }


             qTNode* temp = minValueNode(cur->right);

            cur->setData(temp->getData());

            cur->right = remove( temp->getData(),cur->right);
        }
        return cur;
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
