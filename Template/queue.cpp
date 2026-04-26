#include<iostream>
using namespace std;
template<class T>
class Queue{
private:
    QueueItem<T> *front,*rear; 
public:
    Queue();
    bool isempty();
    void enqueue(T data);
    void pop();
    static int counts;//计数
};
template<class T>
static int counts=0;
template<class T>
class QueueItem{
private:
    T item;
    QueueItem *next;
public:
    QueueItem(T data,QueueItem *n=NULL);
    friend class Queue<T>;
};
template<class T>
QueueItem<T>::QueueItem(T data,QueueItem *n){
    item=data;
    next=n;
}
template<class T>
Queue<T>::Queue(){
    front=NULL;
    rear=NULL;
}
template<class T>
bool Queue<T>::isempty(){
    return (front==NULL&&rear==NULL);
}
template<class T>
void Queue<T>::enqueue(T data){
    QueueItem<T> *p;
    p=new QueueItem<T>(data);
    if(isempty()){
        front=p;
        rear=p;
    }else{
        rear->next=p;
        rear=p;
    }
}
template<class T>
void Queue<T>::pop(){
    if(isempty()){
        cout<<"队空，不能出队"<<endl;
    }else{
        QueueItem<T> *p;//暂存原头指针
        p=front;
        front=front->next;
        // 关键修正：如果出队后队列空了，要把 rear 也置为 NULL
        if (front == NULL) {
            rear = NULL;
        }
        cout<<"出队元素:"<<p->item<<endl;
        delete p;
    }
}
int main(){
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<"队中元素个数:"<<q.counts<<endl;//或者：Queue<int>::counts<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<"队中元素个数:"<<q.counts<<endl;
    return 0;
}