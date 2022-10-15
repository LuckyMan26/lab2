#include "node.h"

Node::Node(QObject *parent)
    : QObject{parent}
{

}
Node::Node(int dat,Node* nxt)
{
this->data=dat;
this->next=nxt;

}
int Node::getData(){
    return this->data;
}

