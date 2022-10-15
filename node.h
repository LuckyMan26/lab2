#ifndef NODE_H
#define NODE_H

#include <QObject>

class Node : public QObject
{

    Q_OBJECT;
    int data;

public:
     Node* next;
    explicit Node(QObject *parent);
    explicit Node(int dat=-1,Node* next=nullptr);
    int getData();

signals:

};

#endif // NODE_H
