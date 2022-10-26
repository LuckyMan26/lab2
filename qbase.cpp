#include <QFileDialog>
#include <QGraphicsItem>
#include <QWheelEvent>
#include <cmath>
#include "qapplication.h"
#include "qbase.h"
#include <iostream>
QBase::QBase()

{

    setScene(new QGraphicsScene);

    setStyleSheet("\nbackground-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(186, 186, 186), stop:1 rgba(255, 255, 255, 255));");

    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    setDragMode(QGraphicsView::ScrollHandDrag);

    setAttribute(Qt::WA_DeleteOnClose);

    //setRenderHint(QPainter::Antialiasing);

    setAlignment(Qt::AlignTop);
}
QGraphicsScene* QBase::getScene(void)
{
    return scene();
}

void QBase::scaleView(qreal scaleFactor)
{
    qreal factor;
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

void QBase::zoomIn(void)
{
    scaleView(qreal(1.2));
}

void QBase::zoomOut(void)
{
    scaleView(1 / qreal(1.2));
}
void QBase::makeStepRegime(){
    step=true;
}
void QBase::UnmakeStepRegime(){
    step=false;
}
bool QBase::getStepRegime(){
    return step;
}
void QBase::update(){
    scene()->update();
    scene()->setSceneRect(scene()->itemsBoundingRect());

}
bool QBase::isStop(void){
    return stop;
}
void QBase::Stop(void){
    stop=true;
}
void QBase::setDelay(int del){
    this->delay=del;
}
int QBase::getDelay(){
    return delay;
}
