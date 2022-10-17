#include "linkedlist.h"
#include <iostream>
LinkedList::LinkedList(Node* head,QObject *parent)
    : QObject{parent},
      head{head}
{

}

void LinkedList::append(int n){
    Node* temp=new Node(n);
    Node* curr=head;
    if(curr==nullptr){
        head=temp;
    }
    else{
    while(curr->next){
        curr=curr->next;
    }
    curr->next=temp;
    }

}
void LinkedList::print(){
    Node* curr=head;
    while(curr){
        std::cout<<curr->getData()<<" ";
        curr=curr->next;
    }
}
int LinkedList::getLength() const{
    Node* temp=this->head;
    int len=0;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}
