#ifndef QTNODE_H
#define QTNODE_H

#include <QGraphicsItem>
#include "vectornode.h"
class qTNode : public QGraphicsItem
{
    int data;
    qreal x,y;
    enum conditions{
        Nothing,
        Checking,
        Suits
    };
    int height;
    int cond=Nothing;
public:

    qTNode* left=nullptr;
    qTNode* right=nullptr;
    qTNode(int data, qTNode* parent);
    ~qTNode();
    qTNode(int data,qTNode* l,qTNode* r);
    int getData();
    void setData(int x);
    void setCond(int x);
    void SetX(qreal x);
    void SetY(qreal y);
    int getX();
    int getY();
    int getHeight();
    void setHeight(int x);
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // QTNODE_H
