#include "vectornode.h"
#include "qwidget.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
vectorNode::vectorNode(int data)
{
this->data=data;
}
int vectorNode::getX(){
   return x;
}
int vectorNode::getY(){
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
int vectorNode::getData(){
    return data;
}
void vectorNode::setData(int x){
   this->data=x;
}
void vectorNode::setCond(int x){
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

    QRect number(0,300-data*10,20,300);
    painter->drawRect(number);
    QRect rect = QRect(0,200-data*10,15,220);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));
    painter->drawText(rect,Qt::AlignCenter,QString::number(data));
}
QRectF vectorNode::boundingRect() const
{
    return QRectF(0,0,40,50);
}
