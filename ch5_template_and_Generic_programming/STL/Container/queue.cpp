#include<iostream>
using namespace std;
template <class T>
class Queue;
template <class T>
class QueueItem{
private:
    T item;
    QueueItem *next;
public:
    QueueItem(T data,QueueItem *n=NULL);
    friend class Queue<T>;
};
template <class T>
QueueItem<T>::QueueItem(T data,QueueItem *n){
    item=data;
    next=n;
}
template <class T>
class Queue{
private:
    QueueItem<T> *front,*rear;
public:
    Queue();
    ~Queue();
    bool isempty();
    void enqueue(T data);
    void pop();
    static int count;
};
template <class T>
int Queue<T>::count=0;
template <class T>
Queue<T>::Queue(){
    front=NULL;
    rear=NULL;
}
template <class T>
bool Queue<T>::isempty(){
    return (front==NULL&&rear==NULL);
}
template <class T>
Queue<T>::~Queue(){
    while(!isempty()){
        QueueItem<T> *p=front;
        front=front->next;
        delete p;
    }
}
template <class T>
void Queue<T>::enqueue(T data){
    QueueItem<T> *p=new QueueItem<T>(data);
    if (isempty()){
        front=p;
        rear=p;
    }else{
        rear->next=p;
        rear=p;
    }
    count++;
}
template <class T>
void Queue<T>::pop(){
    if(isempty()){
        cout<<"队空,无法出队!"<<endl;
    }else{
        QueueItem<T> *p=front;
        front=front->next;
        if(front==NULL){
            rear=NULL;
        }
        cout<<"出队元素:"<<p->item<<endl;
        delete p;
        count--;
    }
}
int main(){
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<"队中元素个数:"<<Queue<int>::count<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<"队中元素个数:"<<Queue<int>::count<<endl;
    return 0;
}