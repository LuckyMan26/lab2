#include "node.h"
#include <iostream>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

Node::Node(int dat,Node* nxt,int x,int y)
{

this->data=dat;
this->next=nxt;
this->x=x;
this->y=y;
this->setX(x);
this->setY(y);
setFlag(QGraphicsItem::ItemSendsScenePositionChanges);

}
int Node::getData(){
    return this->data;
}
void Node::SetX(int x){
    this->x=x;
    this->setX(x);
}
void Node::SetY(int y){
    this->y=y;
     this->setY(y);
}
int Node::getX(){
    return x;
}
int Node::getY(){
    return y;
}
void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){


    painter->setBrush(QColor(Qt::green));
    painter->drawEllipse(0,10,40,40);
    QRect rect = QRect(0,10,40,40);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));
    painter->drawText(rect,Qt::AlignCenter,QString::number(data));
    QLineF line(QPointF(0+40,25),QPointF(0+70,25));
    painter->drawLine(line);


}
QRectF Node::boundingRect() const
{
    return QRectF(0,0,40,50);
}
