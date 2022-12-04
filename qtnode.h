#ifndef QTNODE_H
#define QTNODE_H

#include <QGraphicsItem>
class qTNode : public QGraphicsItem
{
    int data;
    int x,y;
    enum conditions{
        Nothing,
        Checking,
        Suits
    };
    int cond=Nothing;
public:

    qTNode* left=nullptr;
    qTNode* right=nullptr;
    qTNode();
    ~qTNode();
    qTNode(int data=-1,qTNode* l=nullptr,qTNode* r=nullptr);
    int getData();
    void setData(int x);
    void setCond(int x);
    void SetX(int x);
    void SetY(int y);
    int getX();
    int getY();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // QTNODE_H
