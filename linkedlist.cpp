#include "linkedlist.h"
#include <iostream>
LinkedList::LinkedList(Node* head,QObject *parent)
    : QObject{parent},
      head{head}
{

}
LinkedList::LinkedList()
{
this->head=nullptr;
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
