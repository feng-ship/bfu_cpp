#include<iostream>
#include<queue>
using namespace std;
class Queue;
class QueueItem{
private:
    int item;
    QueueItem *next;
public:
    QueueItem(int data,QueueItem *p=NULL);
    friend class Queue;
};
QueueItem::QueueItem(int data,QueueItem *p){
    item=data;
    next=p;
}
class Queue{
private:
    QueueItem *front;
    QueueItem *tail;
public:
    Queue();
    ~Queue();
    bool isempty();
    void enqueue(int data);
    int pop();
    static int count;
};
int Queue::count=0;
Queue::Queue(){
    front=NULL;
    tail=NULL;
}
bool Queue::isempty(){
    return (front==NULL&&tail==NULL);
}
Queue::~Queue(){
    while(!isempty()){
        QueueItem *p=front;
        front=front->next;
        delete p;
    }
}
void Queue::enqueue(int data){
    QueueItem *p=new QueueItem(data);
    if(isempty()){
        front=p;
        tail=p;
    }else{
        tail->next=p;
        tail=p;
    }
    count++;
}
int Queue::pop(){
    QueueItem *p=front;
    front=front->next;
    if(front==NULL){
        tail=NULL;
    }
    int ans=p->item;
    delete p;
    count--;
    return ans;
}
int main(){
    int N;
    cin>>N;
    Queue q;
    for(int i=1;i<=N;i++){
        q.enqueue(i);
    }
    while(Queue::count>=2){
        int rust=q.pop();
        cout<<rust<<" ";
        int temp=q.pop();
        q.enqueue(temp);
    }
    cout<<q.pop()<<endl;
    return 0;
}