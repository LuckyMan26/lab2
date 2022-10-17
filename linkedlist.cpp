#include <iostream>
#include <QGraphicsItem>
#include "linkedlist.h"
#include "node.h"
LinkedList::LinkedList(Node* head):
    QBase()
{
this->head=head;
}

void LinkedList::insert(int n){

    Node* temp=new Node(n);
    Node* curr=head;
    if(curr==nullptr){
        head=temp;
    }
    else{
    while(curr->next){
        curr=curr->next;
    }
    int x=curr->getX();
    int y=curr->getY();
    temp->SetX(x+70);
    temp->SetY(y);
    scene()->addItem(temp);
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
