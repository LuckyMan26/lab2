#include "node.h"

Node::Node(QObject *parent)
    : QObject{parent}
{

}
Node::Node(QObject *parent,int data=-1,Node* nxt=nullptr)
    : QObject{parent}
{
   this->data=data;
    this->next=nxt;
}
