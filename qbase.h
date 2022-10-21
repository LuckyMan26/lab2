#ifndef QBASE_H
#define QBASE_H

#include <QObject>
#include <QGraphicsView>
class QBase : public QGraphicsView
{
    Q_OBJECT
public:
    QBase();
    QGraphicsScene* getScene(void);
    virtual void insert(int n)=0;
    virtual int search(int n)=0;
    virtual void remove(int n)=0;
    virtual void bubbleSort()=0;
    virtual void insertionSort()=0;
    virtual void quickSort()=0;
    virtual void mergeSort()=0;
    virtual void createRand(int size)=0;
    void scaleView(qreal scaleFactor);

    void zoomIn(void);
    void zoomOut(void);
    void update(void);
signals:

};

#endif // QBASE_H
