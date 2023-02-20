#include "qtnode.h"

#include <QPainter>
#include <iostream>
#include <QGraphicsSceneMouseEvent>

qTNode::qTNode(int data, qTNode* parent)
{
this->data=data;
this->left=0;
this->right=0;
setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
setParentItem(parent);
}

qTNode::qTNode(int data,qTNode* l,qTNode* r){
    this->data=data;
    this->left=l;
    this->right=r;
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
    setParentItem(nullptr);

}
qTNode::~qTNode(){
  //  delete left;
  //  delete right;
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

        if(parentItem() == 0) painter->drawLine(QLineF(QPointF(20,10),QPointF(getX()+20, getY())));

        QPointF Qpai = mapFromItem(this,0,50);
        if(left){
            QPointF Qesq = mapFromItem(left,20,30);
            QLineF line(QPointF(Qpai.x()+20,Qpai.y()),Qesq);
            painter->drawLine(line);
        }
        if(right){
            QPointF Qdir = mapFromItem(right,20,30);
            QLineF line(QPointF(Qpai.x()+20,Qpai.y()),Qdir);
            painter->drawLine(line);
        }

        painter->setPen(QPen(Qt::black, 0));
        painter->drawEllipse(0,10,40,40);

        QRect rect = QRect(0,10,40,40);
        painter->drawText(rect,Qt::AlignCenter,QString::number(data));


}
QRectF qTNode::boundingRect() const
{
    if(left != 0 && right == 0) return QRectF(left->getX(),0,qAbs(left->getX())+40,left->getY()+50);
    if(left == 0 && right != 0) return QRectF(0,0,right->getX()+40,right->getY()+50);
    if(left != 0 && right != 0) return QRectF(left->getX(),0,qAbs(left->getX())+right->getX()+40,(right->getY() > left->getY())?right->getY()+50:left->getY()+50);
    return QRectF(0,0,40,50);
}
int qTNode::getData(){
    return data;
}
void qTNode::setData(int x){
    data=x;
}
void qTNode::SetX(qreal x){
    this->x=x;
    this->setX(x);
}
void qTNode::SetY(qreal y){
     this->y=y;
     this->setY(y);
}
int qTNode::getX(){
    return x;
}
int qTNode::getY(){
    return y;
}
int qTNode::getHeight(){
    return height;
}
void qTNode::setHeight(int x){
    this->height=x;
}
