#ifndef NODE_H
#define NODE_H

#include <QObject>

class Node : public QObject
{
    Q_OBJECT
public:
    explicit Node(QObject *parent = nullptr);
    Node(QObject *parent = nullptr,int data=-1,Node* next=nullptr);

private:
    int data;
    Node* next;
signals:

};

#endif // NODE_H
