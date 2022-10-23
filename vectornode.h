#ifndef VECTORNODE_H
#define VECTORNODE_H

#include <QGraphicsItem>
class vectorNode: public QGraphicsItem
{
    int data;
    int x=0;
    int y=0;
    enum conditions{
        Nothing,
        Checking,
        Suits
    };

    int cond=Nothing;
public:
    vectorNode(int data=-1);
    vectorNode(const vectorNode& node);
    void SetX(int x=0);
    void SetY(int y=0);
    int getX() const;
    int getY() const;
    int  getData() const;
    void setData(int x);
    void setCond(int x);
    bool operator > (vectorNode& v) {
        if(data>v.getData()){
            return true;
        }
        return false;
    }
    bool operator < (vectorNode& v){
        if(data<v.getData()){
            return true;
        }
        return false;
    }
    bool operator == (vectorNode& v){
        if(data==v.getData()){
            return true;
        }
        return false;
    }

    friend void swap(vectorNode& lhs, vectorNode& rhs){
        int data1=lhs.getData();
        int data2=rhs.getData();
        lhs.setData(data2);
        rhs.setData(data1);


    }

protected:
  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option=nullptr, QWidget *widget=nullptr);
};

#endif // VECTORNODE_H
