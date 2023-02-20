#include "vector.h"
#include "qapplication.h"
#include "qdatetime.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
#include "step.h"
#include "vectornode.h"
#include <iostream>
#include <QThread>
#include <QTimer>
Vector::Vector()
{
    this->v={};
    QTimer* timer=new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(processEvents()));
    timer->start(50);
}
Vector::Vector(int size){
    this->v.resize(size);
    QTimer* timer=new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(processEvents()));
    timer->start(50);
}
Vector::~Vector(){
    v.clear();
    steps.clear();

}
void Vector::insert(int x){
   setLastAlgorithm(algorithms::inserting);
   vectorNode* tmp=new vectorNode(x);
   int size=v.size();
   if(x<0){
       return;
   }
   if(size>0){
   int xX=v[size-1]->getX();
   int y=v[size-1]->getY();
   tmp->SetX(xX+20);
   tmp->SetY(y);
   this->v.push_back(tmp);
   scene()->addItem(tmp);

}
   else{
      this->v.push_back(tmp);
      scene()->addItem(tmp);
   }


}

void Vector::remove(int x){
     setLastAlgorithm(algorithms::deleting);
    int index;
    for(int i=0;i<v.size();i++){
        v[i]->setCond(conditions::Checking);
        this->repaint();
        if(v[i]->getData()==x){
           v[i]->setCond(conditions::Suits);
            this->repaint();
            index=i;
            delete v[i];
            break;
        }
         v[i]->setCond(conditions::Nothing);
    }
    for(int i=index;i<v.size();i++){
        v[i]->SetX( v[i]->getX()-20);
    }
}
int Vector::search(int x){
     setLastAlgorithm(algorithms::searching);
    for(int i=0;i<v.size();i++){
        QThread::msleep(300);
        v[i]->setCond(conditions::Checking);
        this->repaint();
        if(v[i]->getData()==x){
            v[i]->setCond(conditions::Suits);
             this->repaint();
            return i;
        }
         v[i]->setCond(conditions::Nothing);
    }
    return -1;
}
void Vector::processEvents(void){

    QApplication::processEvents();
}
void Vector::wait(int interval){
    QElapsedTimer* timer = new QElapsedTimer();
    timer->start();

    while(timer->elapsed() < interval) {
        QApplication::processEvents();
    }
    delete timer;
}
void Vector::bubbleSort(){
setLastAlgorithm(algorithms::bubbleSort);
if(clearPreviousSteps_()){
getBubbleSortSteps();
setFirstStep();
}
if(!getStepRegime()){
    for(int i = 1 ;i < steps.size();i++){
        if(isStop()){
              return;
       }
        wait(getDelay());
        setNextStep();
    }
}
}


void Vector::getBubbleSortSteps(){
    if(clearPreviousSteps_()){
    steps.clear();
    curStep = 0;
    }
    else{
        curStep ++;
    }
    int size=v.size();

    for( int i=0;i<size;i++){
        for( int j=0;j<size-i-1;j++){
             std::vector<vectorNode> temp;
             for(int ii=0;ii<size;ii++){
                 if(steps.size()==0)
                    temp.push_back(vectorNode(*v[ii]));
                 else{
                     temp.push_back(steps[steps.size()-1][ii]);
                 }
             }
            temp[j].setCond(conditions::Checking);
            temp[j+1].setCond(conditions::Checking);
            steps.push_back(temp);
            if((temp[j+1]).getData()<(temp[j]).getData()){
                steps.push_back(temp);
                temp[j].setCond(conditions::Suits);
                temp[j+1].setCond(conditions::Suits);
                swap(temp[j],temp[j+1]);
                 steps.push_back(temp);
                temp[j].setCond(conditions::Nothing);
                temp[j+1].setCond(conditions::Nothing);
            }
            temp[j].setCond(conditions::Nothing);
            temp[j+1].setCond(conditions::Nothing);
            steps.push_back(temp);
        }
    }
}
void Vector::insertionSort(){
    setLastAlgorithm(algorithms::insertionSort);
    if(clearPreviousSteps_()){
    getInsertionSortSteps();
    setFirstStep();
    }
    if(!getStepRegime()){
        for(int i = 1 ;i < steps.size();i++){
            if(isStop()){
                  return;
           }
            wait(getDelay());
            setNextStep();
        }

    }
}
void Vector::getInsertionSortSteps(){
    if(clearPreviousSteps_()){
    steps.clear();
    curStep = 0;
    }
    int key;
    int size=v.size();
    int j;
    for (int i = 1; i < size; i++){
        std::vector<vectorNode> temp;
        for(int ii=0;ii<size;ii++){
            if(steps.size()==0)
               temp.push_back(vectorNode(*v[ii]));
            else{
                temp.push_back(steps[steps.size()-1][ii]);
            }
        }

        temp[i].setCond(conditions::Checking);

        key=temp[i].getData();
        j = i - 1;
        temp[j].setCond(conditions::Checking);
         steps.push_back(temp);
        while (j >= 0 && temp[j].getData() > key)
        {

            temp[j].setCond(conditions::Nothing);
            temp[j+1].setData(temp[j].getData());
            steps.push_back(temp);
            j = j - 1;
        }
        temp[j + 1].setData(key);
        steps.push_back(temp);

    }
}

void Vector::qSort(int low,int high){

        int i=low;
        int j=high;
        std::vector<vectorNode> temp;
        for(int ii=0;ii<v.size();ii++){
            if(steps.size()==0)
               temp.push_back(vectorNode(*v[ii]));
            else{
                temp.push_back(steps[steps.size()-1][ii]);
            }
        }
        int pivot =temp[(i + j)/2].getData();

        temp[(i+j)/2].setCond(conditions::Checking);
        steps.push_back(temp);
        while (i <= j)
        {


            while (temp[i].getData()<pivot){
                temp[i].setCond(conditions::Suits);
                i++;
            }
            while (temp[j].getData()>pivot){
                temp[j].setCond(conditions::Suits);
                j--;
            }
            steps.push_back(temp);
            temp[i].setCond(conditions::Nothing);
            temp[j].setCond(conditions::Nothing);
            if (i <= j)
            {
                temp[i].setCond(conditions::Suits);
                temp[j].setCond(conditions::Suits);
                this->repaint();

                swap(temp[i],temp[j]);
                temp[i].setCond(conditions::Nothing);
                temp[j].setCond(conditions::Nothing);
                steps.push_back(temp);
                i++;
                j--;
            }

        }

        temp[(i+j)/2].setCond(conditions::Nothing);
         steps.push_back(temp);
        if (j > low){
            qSort(low, j);
        }
        if (i < high)
            qSort(i, high);

}
void Vector::quickSort(){
    setLastAlgorithm(algorithms::quickSort);
    if(clearPreviousSteps_()){
    getQuickSortSteps();
    setFirstStep();
}
    int size=v.size();

    if(!getStepRegime()){

        for(int i = 1 ;i < steps.size();i++){
            if(isStop()){
                  return;
           }
            wait(getDelay());
            setNextStep();
        }

    }


}
void Vector::getQuickSortSteps(){
if(clearPreviousSteps_()){
steps.clear();
curStep = 0;
}
qSort(0,v.size()-1);
for(std::size_t i=0;i<v.size();i++){
    steps[steps.size()-1][i].setCond(conditions::Nothing);
}
}


void Vector::merge(std::vector<vectorNode> vec,vectorNode* tmp,int bot, int mid, int top){
    int i=bot;
    int j=mid+1;
    int cur=bot;
    while(i<=mid&&j<=top){
        if(vec[i].getData()<=vec[j].getData()){
            tmp[cur].setData(vec[i].getData());
            cur++;
            i++;
        }
        else{
            tmp[cur].setData(vec[j].getData());
            cur++;
            j++;
        }

    }
    while(i<vec.size()&&i<=mid){
        tmp[cur].setData(vec[i].getData());
        cur++;
        i++;
    }
    vector<vectorNode> temp(steps[steps.size()-1]);
    for(int i=bot;i<=top;i++){
      temp[i].setData(tmp[i].getData());

    }
    steps.push_back(temp);
}

void Vector::mergeSort(){
    setLastAlgorithm(algorithms::mergeSort);
    getMergeSortSteps();
    setFirstStep();
        for(std::size_t i = 1 ;i < steps.size();i++){
            if(isStop()){
                  return;
           }
            wait(getDelay());
            setNextStep();
        }


}
void Vector::getMergeSortSteps(){
    if(clearPreviousSteps_()){
    steps.clear();
    mergeSort_();
    }
    for(std::size_t i = 0;i<v.size();i++){
        steps[steps.size()-1][i].setCond(conditions::Nothing);
    }
}
void Vector::mergeSort_(){
    int length=v.size();
    std::vector<int> v1;
    std::vector<vectorNode> temp;


    vectorNode* tmp=new vectorNode[length];
    for(std::size_t i=0;i<length;i++){
        if(steps.size()==0)
            tmp[i].setData(v[i]->getData());
        else{
            tmp[i].setData(steps[steps.size()-1][i].getData());
        }

    }
    for(int width=1;width<length;width=2*width){
        for(int i=0;i<length;i+=2*width){
            temp.clear();
            for(int ii=0;ii<v.size();ii++){
                if(steps.size()==0)
                   temp.push_back(vectorNode(*v[ii]));
                else{
                    temp.push_back(steps[steps.size()-1][ii]);
                }
            }

            int bot=i;
            int mid=i+width-1;
            int top=std::min(length-1,i+2*width-1);
            for(int i=bot;i<=mid;i++){
                temp[i].setCond(conditions::Checking);
            }
            for(int i=mid;i<top;i++){
                temp[i].setCond(conditions::Suits);
            }
            steps.push_back(temp);
            merge(temp,tmp,bot,mid,top);


            for(int i=bot;i<=mid;i++){
                temp[i].setCond(conditions::Nothing);
            }
            for(int i=mid;i<top;i++){
                temp[i].setCond(conditions::Nothing);
            }

        }
    }

    delete[] tmp;
}

void Vector::createRand(int size){
    int temp;
    srand(time(NULL));
    int len=v.size();
    for(int i=0;i<len;i++){
        delete v[i];
    }
    steps.clear();
    v.clear();
    curStep = 0;
    setclearPreviousSteps_(true);
    for(int i=0;i<size;i++){
        temp=rand()%(2*size);
        insert(temp);
    }
}
vector<vector<vectorNode>> Vector::getSteps(){
    return (steps);
}
void Vector::setFirstStep(){
    for(std::size_t i=0;i<v.size();i++){
        v[i]->setData((steps[0][i].getData()));
    }

    scene()->update();
    this->repaint();
}
void Vector::setNextStep(){
    if(curStep<steps.size()-1){
        for(std::size_t i=0;i<v.size();i++){
            v[i]->setData(steps[curStep+1][i].getData());
            v[i]->setCond(steps[curStep+1][i].getCond());
        }
        curStep+=1;
    }

    scene()->update();
    this->repaint();
}
void Vector::setPrevStep(){
    if(curStep>0){
        for(std::size_t i=0;i<v.size();i++){
            v[i]->setData(steps[curStep-1][i].getData());
            v[i]->setCond(steps[curStep-1][i].getCond());
        }
        curStep-=1;
    }

    scene()->update();
    this->repaint();
}

int Vector::getCurStep(void){
    return curStep;
}
