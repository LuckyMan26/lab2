#include "twothreenode.h"
#include <iostream>
TwoThreeNode::TwoThreeNode(int k){
this->key[0]=k;
this->first=nullptr;
this->second=nullptr;
this->third=nullptr;
this->fourth=nullptr;
this->parent=nullptr;
size=1;
}
TwoThreeNode::TwoThreeNode(int k,TwoThreeNode* f,TwoThreeNode* s,TwoThreeNode* t,TwoThreeNode* fourt_,TwoThreeNode* p){
this->key[0]=k;
this->first=f;
this->second=s;
this->third=t;
this->fourth=fourt_;
this->parent=p;
size=1;
}

bool TwoThreeNode::find(int elem){
for(int i=0;i<size;i++){
    if(key[i]==elem){
        return true;
    }
}
return false;
}
void TwoThreeNode::sort(){
for(int i=0;i<size;i++){
    for(int j=0;j<size-i-1;j++){
        if(key[j]>key[j+1]){
            std::swap(key[j],key[j+1]);
        }
    }
}
}
void TwoThreeNode::insert(int elem){
key[size]=elem;
size++;
this->sort();
}
void TwoThreeNode::remove(int k){
if((size>=1)&&(key[0]==k)){
    key[0]=key[1];
    key[1]=key[2];
    size--;
}
else if((size==2)&&(key[1]==k)){
    key[1]=key[2];
    size--;
}
}
void TwoThreeNode::Convert2TwoThreeNode(int elem,TwoThreeNode* f,TwoThreeNode* s){
key[0]=elem;
size=1;
first=f;
second=s;
third=nullptr;
fourth=nullptr;
parent=nullptr;
}
bool TwoThreeNode::is_leaf(){
return (first == nullptr) && (second == nullptr) && (third == nullptr);
}
int TwoThreeNode::getSize(){
    return size;
}
void TwoThreeNode::setSize(int x){
    this->size=x;
}
