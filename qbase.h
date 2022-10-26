#ifndef QBASE_H
#define QBASE_H

#include <QObject>
#include <QGraphicsView>
#include "vectorNode.h"
class QBase : public QGraphicsView
{
    Q_OBJECT
    bool step=false;
    bool stop=false;
    int delay=300;
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

    void makeStepRegime();
    void UnmakeStepRegime();
    bool getStepRegime();

    bool isStop(void);
    void Stop(void);
    virtual std::vector<std::vector<int>> getSteps()=0;
    virtual void setFirstStep()=0;
    virtual void setNextStep()=0;
    virtual void setPrevStep()=0;

    void setDelay(int del);
    int getDelay();
signals:

};

#endif // QBASE_H
