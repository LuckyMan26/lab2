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
void Vector::insert(int x){
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
    int index;
    for(int i=0;i<v.size();i++){
        v[i]->setCond(1);
        this->repaint();
        if(v[i]->getData()==x){
           v[i]->setCond(2);
            this->repaint();
            index=i;
            delete v[i];
            break;
        }
         v[i]->setCond(0);
    }
    for(int i=index;i<v.size();i++){
        v[i]->SetX( v[i]->getX()-20);
    }
}
int Vector::search(int x){
    for(int i=0;i<v.size();i++){
        QThread::msleep(300);
        v[i]->setCond(1);
        this->repaint();
        if(v[i]->getData()==x){
            v[i]->setCond(2);
             this->repaint();
            return i;
        }
         v[i]->setCond(0);
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

int size=v.size();
std::vector<int> v1=getIntVector();
 bubbleSort(v1);
if(!getStepRegime()){

for( int i=0;i<size;i++){
    for( int j=0;j<size-i-1;j++){
        if(isStop()){

            return;
        }
        curStep++;
        wait(getDelay());
        v[j]->setCond(1);
        v[j+1]->setCond(1);

        this->repaint();


        if((v[j+1])->getData()<(v[j])->getData()){
            v[j]->setCond(2);
            v[j+1]->setCond(2);
            swap(*v[j],*v[j+1]);

            this->repaint();

            v[j]->setCond(0);
            v[j+1]->setCond(0);
        }
        v[j]->setCond(0);
        v[j+1]->setCond(0);

    }

}
}
else{
    std::vector<int> v1;
    for(int i=0;i<size;i++){

        v1.push_back(v[i]->getData());
    }
    bubbleSort(v1);
}
}
void Vector::bubbleSort(std::vector<int> v1){
    int size=v1.size();


    for( int i=0;i<size;i++){
        for( int j=0;j<size-i-1;j++){
            vec.push_back(v1);
            if((v1[j+1])<(v1[j])){
                swap(v1[j],v1[j+1]);

            }

        }
    }
}
void Vector::insertionSort(){
std::vector<int> v1=getIntVector();
insertionSort(v1);
    if(!getStepRegime()){

        int key;
        int size=v.size();
        int j;
        for (int i = 1; i < size; i++){
            if(isStop()){
                return;
            }
             curStep++;
             wait(getDelay());
            v[i]->setCond(1);

            key=v[i]->getData();
            j = i - 1;
            v[j]->setCond(1);
            this->repaint();
            while (j >= 0 && v[j]->getData() > key)
            {


                 v[j]->setCond(0);
                v[j+1]->setData(v[j]->getData());

                j = j - 1;
            }
            v[j + 1]->setData(key);

        }
    }
    else{
        std::vector<int> v1;
        int size=v.size();
        for(int i=0;i<size;i++){
            v1.push_back(v[i]->getData());
        }
        insertionSort(v1);
    }
}
void Vector::insertionSort(vector<int> v1){
    int key;
    int size=v1.size();
    int j;
    vec.push_back(v1);
    for (int i = 1; i < size; i++){

        key=v1[i];
        j = i - 1;
        while (j >= 0 && v1[j] > key)
        {
            v1[j+1]=(v1[j]);
            j = j - 1;
        }

        v1[j + 1]=(key);
        vec.push_back(v1);
    }


}
void Vector::qSort(std::vector<vectorNode*>& vec,int low,int high){
        int i=low;
        int j=high;
        int pivot =v[(i + j)/2]->getData();
        v[(i+j)/2]->setCond(1);
        this->repaint();
        while (i <= j)
        {
            if(isStop()){
                return;
            }
            curStep++;
            wait(getDelay());
            while (v[i]->getData()<pivot){
                v[i]->setCond(2);
                this->repaint();
                i++;
            }
            while (v[j]->getData()>pivot){
                v[j]->setCond(2);

                j--;
            }

            v[i]->setCond(0);
            v[j]->setCond(0);
            if (i <= j)
            {
                v[i]->setCond(2);
                v[j]->setCond(2);
                this->repaint();

                swap(*v[i],*v[j]);
                this->repaint();
                v[i]->setCond(0);
                v[j]->setCond(0);
                i++;
                j--;
            }
        }

        v[(i+j)/2]->setCond(0);
        if (j > low){

            qSort(v, low, j);
        }
        if (i < high)
            qSort(v, i, high);
        if(i<v.size()&&i>-1){
        v[i]->setCond(0);
        }
        if((j<v.size())&&(j>-1)){
        v[j]->setCond(0);
        }
}
void Vector::quickSort(){
std::vector<int> v1=getIntVector();
quickSort(v1);
    if(!getStepRegime()){
          std::vector<int> v1;
        for(int i=0;i<v.size();i++){
            v1.push_back(v[i]->getData());
        }
        for(int i=0;i<v.size();i++){
           std::cout<<v1[i]<<std::endl;
        }
    int size=v.size();
    qSort(v,0,size-1);
    }
    else{
        std::vector<int> v1;
        int size=v.size();
        for(int i=0;i<size;i++){
            v1.push_back(v[i]->getData());
        }

        quickSort(v1);
    }
}

void Vector::quickSort(vector<int> v1){
     int size=v1.size();
     vec.push_back(v1);
      std::cout<<"Hello\n";
     qSort(v1,0,size-1);
     vec.push_back(v1);
     std::cout<<"Hello\n";
}
void Vector::qSort(vector<int>& v1,int low,int high){
    int i=low;
    int j=high;
    int pivot =v1[(i + j)/2];
    while (i <= j)
    {

        while (v1[i]<pivot){
            i++;
        }
        while (v1[j]>pivot){
            j--;
        }

        if (i <= j)
        {

            swap(v1[i],v1[j]);

            i++;
            j--;
        }
    vec.push_back(v1);
    }

    if (j > low){

        qSort(v1, low, j);
    }
    if (i < high){

        qSort(v1, i, high);
}
}
void Vector::merge(std::vector<vectorNode*> vec,vectorNode* tmp,int bot, int mid, int top){
    int i=bot;
    int j=mid+1;
    int cur=bot;
    while(i<=mid&&j<=top){
        if(vec[i]->getData()<=vec[j]->getData()){
            tmp[cur].setData(vec[i]->getData());
            cur++;
            i++;
        }
        else{
            tmp[cur].setData(vec[j]->getData());
            cur++;
            j++;
        }
    }
    while(i<vec.size()&&i<=mid){
        tmp[cur].setData(vec[i]->getData());
        cur++;
        i++;
    }

    for(int i=bot;i<=top;i++){
        v[i]->setData(tmp[i].getData());
    }
}

void Vector::mergeSort(){
std::vector<int> v1=getIntVector();
vec.push_back(v1);
int length=v.size();
int* tmp=new int[length];
for(int i=0;i<length;i++){
    tmp[i]=(v[i]->getData());
    v1.push_back(v[i]->getData());
}
for(int width=1;width<length;width=2*width){
    for(int i=0;i<length;i+=2*width){

        int bot=i;
        int mid=i+width-1;
        int top=std::min(length-1,i+2*width-1);
        merge(v1,tmp,bot,mid,top);
        vec.push_back(v1);

    }
}
delete[] tmp;
    if(!getStepRegime()){
    int length=v.size();
    std::vector<int> v1;

    vectorNode* tmp=new vectorNode[length];
    for(int i=0;i<length;i++){
        tmp[i].setData(v[i]->getData());

    }
    for(int width=1;width<length;width=2*width){
        for(int i=0;i<length;i+=2*width){
            if(isStop()){
                return;
            }
            curStep++;
            wait(getDelay());
            int bot=i;
            int mid=i+width-1;
            int top=std::min(length-1,i+2*width-1);
            for(int i=bot;i<=mid;i++){
                v[i]->setCond(1);
            }
            for(int i=mid;i<top;i++){
                v[i]->setCond(2);
            }
            this->repaint();
            merge(v,tmp,bot,mid,top);
            this->repaint();
            for(int i=bot;i<=mid;i++){
                v[i]->setCond(0);
            }
            for(int i=mid;i<top;i++){
                v[i]->setCond(0);
            }
        }
    }
    delete[] tmp;
    }
    else{
        int length=v.size();
        vector<int> v1;
        int* tmp=new int[length];
        for(int i=0;i<length;i++){
            tmp[i]=(v[i]->getData());
            v1.push_back(v[i]->getData());
        }

        vec.push_back(v1);
        for(int width=1;width<length;width=2*width){
            for(int i=0;i<length;i+=2*width){

                int bot=i;
                int mid=i+width-1;
                int top=std::min(length-1,i+2*width-1);
                merge(v1,tmp,bot,mid,top);
                vec.push_back(v1);

            }
    }
delete[] tmp;
}
}
void Vector::merge(vector<int>& v1,int* tmp,int bot,int mid,int top){
    int i=bot;
    int j=mid+1;
    int cur=bot;

    while(i<=mid&&j<=top){

        if(v1[i]<=v1[j]){
            tmp[cur]=(v1[i]);
            cur++;
            i++;
        }
        else{
            tmp[cur]=v1[j];
            cur++;
            j++;
        }
    }
    while(i<v1.size()&&i<=mid){
        tmp[cur]=(v1[i]);
        cur++;
        i++;
    }

    for(int i=bot;i<=top;i++){
        v1[i]=(tmp[i]);
    }
}
void Vector::createRand(int size){
    int temp;
    srand(time(NULL));
    int len=v.size();
    for(int i=0;i<len;i++){
        delete v[i];
    }
    std::cout<<len<<std::endl;
    v.clear();
    for(int i=0;i<size;i++){
        temp=rand()%(2*size);
        insert(temp);
    }
}
vector<vector<int>> Vector::getSteps(){
    return (vec);
}
void Vector::setFirstStep(){
    for(int i=0;i<v.size();i++){
        v[i]->setData(vec[0][i]);
    }
    for(int i=0;i<v.size();i++){
        std::cout<<v[i]->getData()<<std::endl;
    }
    scene()->update();
    this->repaint();
}
void Vector::setNextStep(){
    if(curStep<vec.size()-1){
        for(int i=0;i<v.size();i++){
            v[i]->setData(vec[curStep+1][i]);
        }
        curStep+=1;
    }
    for(int i=0;i<v.size();i++){
        std::cout<<v[i]->getData()<<std::endl;
    }
    scene()->update();
    this->repaint();
}
void Vector::setPrevStep(){
    if(curStep>0){
        for(int i=0;i<v.size();i++){
            v[i]->setData(vec[curStep-1][i]);
        }
        curStep-=1;
    }
    for(int i=0;i<v.size();i++){
        std::cout<<v[i]->getData()<<std::endl;
    }
    scene()->update();
    this->repaint();
}
std::vector<int> Vector::getIntVector(void){
    std::vector<int> v1;
    int size=v.size();
    for(int i=0;i<size;i++){
        v1.push_back(v[i]->getData());
    }
    return v1;
}
int Vector::getCurStep(void){
    return curStep;
}
