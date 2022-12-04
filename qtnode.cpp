#include "qtnode.h"

#include <QPainter>
#include <iostream>
#include <QGraphicsSceneMouseEvent>

qTNode::qTNode()
{
this->data=-1;
this->left=nullptr;
this->right=nullptr;
}

qTNode::qTNode(int data,qTNode* l,qTNode* r){
    this->data=data;
    this->left=l;
    this->right=r;

}
void qTNode::setCond(int x){
    this->cond=x;
}
void qTNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(cond==Nothing){
    painter->setBrush(QColor(Qt::white));
    }
    else if(cond==Checking){
        painter->setBrush(QColor(Qt::red));
    }
    else if(cond==Suits){
        painter->setBrush(QColor(Qt::green));
    }


        if(left){

        QLineF line(QPointF(0,0+30),QPointF(0-30,0+50));
        painter->drawLine(line);
        }
        if(right){
            QLineF line(QPointF(0+40,0+30),QPointF(0+70,0+50));
            painter->drawLine(line);
        }

    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(0,10,40,40);

    QRect rect = QRect(0,10,40,40);
    painter->drawText(rect,Qt::AlignCenter,QString::number(data));



}
QRectF qTNode::boundingRect() const
{


    return QRectF(0,0,40,50);
}
int qTNode::getData(){
    return data;
}
void qTNode::setData(int x){
    data=x;
}
void qTNode::SetX(int x){
    this->x=x;
    this->setX(x);
}
void qTNode::SetY(int y){
    this->y=y;
     this->setY(y);
}
int qTNode::getX(){
    return x;
}
int qTNode::getY(){
    return y;
}
