#include "vectornode.h"
#include "qwidget.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <iostream>
vectorNode::vectorNode(int data){
    this->data=data;
}
vectorNode::vectorNode(const vectorNode& node){
    this->data=node.getData();
    this->cond = node.getCond();
    SetX(node.getX());
    SetX(node.getY());
}
conditions vectorNode::getCond() const{
    return cond;
}
int vectorNode::getX() const{
   return x;
}
 int vectorNode::getY() const{
    return y;
}
void vectorNode::SetX(int x){
    this->x=x;
    setX(x);
}
void vectorNode::SetY(int y){
    this->y=y;
    setY(y);
}
 int vectorNode::getData() const{
    return data;
}
void vectorNode::setData(int x){
   this->data=x;
}
void vectorNode::setCond(conditions x){
    this->cond=x;
}

void vectorNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(cond==Nothing){
    painter->setBrush(QColor(Qt::white));
    }
    else if(cond==Checking){
        painter->setBrush(QColor(Qt::red));
    }
    else if(cond==Suits){
        painter->setBrush(QColor(Qt::green));
    }
    int width=widget->width();
    int height=widget->height();
    QRect number(QPoint(0,height-data*10),QSize(20,10*data));
    painter->drawRect(number);
    QRect rect = QRect(QPoint(0,height-data*10),QSize(20,10*data));
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));
    painter->drawText(rect,Qt::AlignCenter,QString::number(data));
}
QRectF vectorNode::boundingRect() const
{
    return QRectF(0,0,40,50);
}
