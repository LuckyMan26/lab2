#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>

class Node : public QGraphicsItem
{

    int data;
    int x=0;
    int y=0;
public:
    Node* next;
    Node(int dat=-1,Node* next=nullptr,int x=0,int y=0);
    int getData();
    void SetX(int x);
    void SetY(int y);
    int getX();
    int getY();
protected:
  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option=nullptr, QWidget *widget=nullptr);

};

#endif // NODE_H
