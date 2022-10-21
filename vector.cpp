#include "vector.h"
#include "vectornode.h"
#include <iostream>
#include <QThread>
Vector::Vector()
{
    this->v={};
}
void Vector::insert(int x){
   vectorNode* tmp=new vectorNode(x);
   int size=v.size();
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
void Vector::bubbleSort(){
int size=v.size();
for( int i=0;i<size;i++){
    for( int j=0;j<size-i-1;j++){
        QThread::msleep(1000);
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
void Vector::insertionSort(){
        int key;
        int size=v.size();
        int j;
        for (int i = 1; i < size; i++){
            QThread::msleep(1000);
            v[i]->setCond(1);

            key=v[i]->getData();
            j = i - 1;
            v[j]->setCond(1);
            this->repaint();
            while (j >= 0 && v[j]->getData() > key)
            {
                v[j]->setCond(2);
                v[j+1]->setData(v[j]->getData());
                this->repaint();
                v[j]->setCond(0);
                j = j - 1;
            }

            v[j + 1]->setData(key);
            this->repaint();
        }
}
void Vector::qSort(std::vector<vectorNode*> vec,int low,int high){
        int i=low;
        int j=high;
        int pivot =v[(i + j)/2]->getData();
        while (i <= j)
        {
            QThread::msleep(1000);
            while (v[i]->getData()<pivot){
                v[i]->setCond(1);
                this->repaint();

                i++;
            }
            while (v[j]->getData()>pivot){
                v[j]->setCond(1);
                this->repaint();

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
        if (j > low)
            qSort(v, low, j);
        if (i < high)
            qSort(v, i, high);
        v[i]->setCond(0);
        v[j]->setCond(0);
}
void Vector::quickSort(){
    int size=v.size();
    qSort(v,0,size-1);
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
    int length=v.size();
    vectorNode* tmp=new vectorNode[length];
    for(int i=0;i<length;i++){
        tmp[i].setData(v[i]->getData());
    }
    for(int width=1;width<length;width=2*width){
        for(int i=0;i<length;i+=2*width){
            QThread::msleep(1000);
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
void Vector::createRand(int size){
    int temp;
    srand(time(NULL));
    for(int i=0;i<size;i++){
        temp=rand()%(2*size);
        insert(temp);
    }
}
