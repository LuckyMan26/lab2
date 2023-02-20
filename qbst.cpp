#include "qbst.h"
#include <iostream>
qBst::qBst():
    QBase()
{
this->root= new qTNode(-1,nullptr,nullptr);
}
qBst::qBst(qTNode* r){
    this->root=r;
}
void qBst::insert(int data,qTNode* cur){
if(cur){
    if(cur->getData() > data){
        if(cur->left)
            insert(data,cur->left);
        else{
            cur->left = new qTNode(data,cur);
            scene()->addItem(cur->left);
        }
    }
    if(cur->getData()<=data){
        if(cur->right)
            insert(data,cur->right);
        else{
            cur->right = new qTNode(data,cur);
            scene()->addItem(cur->right);
        }
    }
}

}
void qBst::insert(int x){
if(!root){
    qTNode* node=new qTNode(x, nullptr);
    root=node;
    scene()->addItem(root);
}
else{
    insert(x,root);
    if(typeOfJustify==0){
        justifyStandart(root,3);
    }
    else{
        justifyComplete(root,3);
    }
}
}
int qBst::search(int x){
search(x,root);
return -1;
}
void qBst::search(int x,qTNode* cur){
        wait(getDelay());
        cur->setCond(1);
        this->repaint();
        if(cur->getData()==x){
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
remove(x,&root,&root);
if(typeOfJustify == 0) justifyStandart(root,3);
else justifyComplete(root,3);
std::cout<<"hello\n";
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

       while (current && current->left != nullptr)
           current = current->left;

       return current;
}
void qBst::remove(int x,qTNode** cur,qTNode** parent){
    if ((*cur) != 0)
    {
            if((*cur)->getData() == x) {

                if ((*cur)->left == 0 && (*cur)->right == 0){
                    delete (*cur);
                    (*cur) = 0;
                }else{
                 if ((*cur)->left == 0 && ((*cur)->right!=0)) {
                    if((*cur) == root){
                        (*cur)->right->setParentItem(0);
                    }
                    else{
                          (*cur)->right->setParentItem((*parent));
                    }
                    (*cur)->right->SetX((*cur)->getX());
                    (*cur)->right->SetY((*cur)->getY());

                    qTNode* temp = *cur;
                    *cur = (*cur)->right;
                        delete temp;
                }else if ((*cur)->right == 0 && ((*cur)->left!=0)) {
                    if((*cur) == root){
                        (*cur)->left->setParentItem(0);
                    }
                    else{
                          (*cur)->left->setParentItem((*parent));

                    }
                    (*cur)->left->SetX((*cur)->getX());
                    (*cur)->left->SetY((*cur)->getY());
                    qTNode* temp = *cur;
                    *cur = (*cur)->left;
                    delete temp;
                }else if((*cur)->left!=0 && (*cur)->right!=0){
                qTNode* temp = minValueNode((*cur)->right);
                (*cur)->setData(temp->getData());
                remove( temp->getData(),&(*cur)->right,cur);
            }
            }
            }
            else{
            if (x < (*cur)->getData()){
                    remove(x,&(*cur)->left,cur);
                }
            else if (x > (*cur)->getData()){

                    remove(x,&(*cur)->right,cur);
            }
            }
}

}
int qBst::height(qTNode* node){
    int Height=0;
    if(node){
        int left_height;
        if(node->left){
            left_height = height(node->left) + 1;
        }
        else{
             left_height = 0;
        }
        int right_height;
        if(node->right){
            right_height = height(node->right)+1;
        }
        else{
            right_height = 0;
        }
        Height = std::max(left_height,right_height);
    }
    return Height;
}
void qBst::justifyComplete(qTNode* node,int x){
    if(node){
        int nodeHeight = height(node);
        int displacementDegree = pow(2,nodeHeight);
        if(x==1) node->SetX(20*displacementDegree);
        if(x==2) node->SetX(-20*displacementDegree);

        if(node->parentItem() != 0) node->SetY(50);

        justifyComplete(node->right,1);
        justifyComplete(node->left,2);
    }
    }
int qBst::quantNode(qTNode* node){
    int count = 0;
    if(node){
       count = count + quantNode(node->right);
       count = count + quantNode(node->left);
       count++;
    }
    return count;
}
void qBst::justifyStandart(qTNode* node,int x){
    if(node){
        int quantNode_ = 0;
        if(x == 1) quantNode_ = quantNode(node->left);
        if(x == 2) quantNode_ = quantNode(node->right);

        if(node->parentItem() != 0) node->SetY(50);

        if(x==1) node->SetX(40*(quantNode_+1));
        if(x==2) node->SetX(-40*(quantNode_+1));

        justifyStandart(node->right,1);
        justifyStandart(node->left,2);
    }
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
