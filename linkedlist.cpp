#include <iostream>
#include <QGraphicsItem>
#include <QPainter>
#include <QThread>
#include "linkedlist.h"
#include "node.h"
LinkedList::LinkedList(Node* head):
    QBase()
{
this->head=head;
scene()->addItem(head);
}

void LinkedList::insert(int n){

    Node* temp=new Node(n);
    Node* curr=head;
    if(curr==nullptr){
        head=temp;
        scene()->addItem(head);
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
int LinkedList::search(int x){
    Node* temp=head;
    int index=0;
    while(temp){
        QThread::msleep(300);
        temp->setCond(1);
        this->repaint();
        temp->setCond(0);
        if(temp->getData()==x){
            temp->setCond(2);
            this->repaint();
            temp->setCond(0);
            return index;
        }

        index++;
        temp=temp->next;
    }
    return -1;

}
void LinkedList::remove(int x){
    Node* temp=head;
    Node* prev=nullptr;
    int index=0;

    while(temp){
        QThread::msleep(300);
        temp->setCond(1);
        this->repaint();
        temp->setCond(0);
        if(temp->getData()==x){
            if(temp==head){
                temp->setCond(2);
                this->repaint();
                delete temp;
                return;
            }
            else{
            temp->setCond(2);
            this->repaint();
            temp->setCond(0);
            prev->next=temp->next;
            if(temp->next){
                Node* tmp=temp->next;
                while(tmp){
                    int x=tmp->getX();
                    int y=tmp->getY();
                    tmp->SetX(x-70);
                    tmp->SetY(y);
                    this->repaint();
                    tmp=tmp->next;
                }
            }
            delete temp;
            }
        }
        index++;
        prev=temp;
        temp=temp->next;
    }
}
