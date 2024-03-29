#ifndef QBASE_H
#define QBASE_H

#include <QObject>
#include <QGraphicsView>
enum algorithms{searching,inserting,deleting,bubbleSort,insertionSort,quickSort,mergeSort};
class QBase : public QGraphicsView
{
    Q_OBJECT
    bool step=false;
    bool stop=false;
    int delay=300;
    algorithms lastAlgorithms;
    bool clearPreviousSteps = true;
public:
    QBase();
    QGraphicsScene* getScene(void);
    virtual void insert(int n)=0;
    virtual int search(int n)=0;
    virtual void remove(int n)=0;

    virtual void createRand(int size)=0;
    void scaleView(qreal scaleFactor);

    void zoomIn(void);
    void zoomOut(void);
    void update(void);
    bool clearPreviousSteps_();
    void setclearPreviousSteps_(bool x);
    void makeStepRegime();
    void UnmakeStepRegime();
    bool getStepRegime();
    void setLastAlgorithm(algorithms algo);
    algorithms getLastAlgorithm();
    bool isStop(void);
    void Stop(void);
    void unStop(void);
    virtual void setFirstStep()=0;
    virtual void setNextStep()=0;
    virtual void setPrevStep()=0;

    void setDelay(int del);
    int getDelay();
    void wait(int interval);
signals:

};
class QBaseSortable : public QBase{
public:

    virtual void bubbleSort()=0;
    virtual void insertionSort()=0;
    virtual void quickSort()=0;
    virtual void mergeSort()=0;
};
class QBaseNonSortable : public QBase{};
#endif // QBASE_H
