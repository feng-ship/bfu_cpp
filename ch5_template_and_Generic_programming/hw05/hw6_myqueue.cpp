#include<iostream>
using namespace std;

template <typename T> class MyQueue; // 前置声明
template <typename T> ostream & operator<<(ostream &, const MyQueue<T> &); 

template <typename T> 
class QueueItem
{
public:
    QueueItem(const T & t) :item(t), next(0) {} 
private:
    T item; 
    QueueItem *next; 
    friend class MyQueue<T>; // 友元类    
    
    // 通过友元函数重载<<运算符模板函数，要写上<<后的<Type>
    friend ostream & operator<< <T> (ostream & os, const MyQueue<T> & q);
};


template <typename T>
ostream & operator<<(ostream & os, const MyQueue<T> & q){
    os << "< ";
    QueueItem<T> *p = q.head;
    while(p != NULL){
        os << p->item << " ";
        p = p->next;
    }
    os << ">";
    return os;
}

template <typename T> 
class MyQueue
{
public:
    MyQueue() : head(0), tail(0) {} // Empty MyQueue

    MyQueue(const MyQueue &Q) // 拷贝构造函数
        :head(0), tail(0) 
    { CopyElements(Q); }

    ~MyQueue() { Destroy(); }

    MyQueue & operator=(const MyQueue &);

    // return element from head of MyQueue
    T & Front() { return head->item; }
    const T & Front() const { return head->item; }
    void Push(const T &); // add element to back of MyQueue
    void Pop(); // remove element from head of MyQueue
    bool Empty() const { return head == 0; }
    void Display() const;
private:
    QueueItem<T> *head;
    QueueItem<T> *tail;
    void Destroy(); // delete all the elements
    void CopyElements(const MyQueue &);

    // 设置友元函数
    friend ostream & operator<< <T> (ostream & os, const MyQueue<T> & q);
};

template<class T>
void MyQueue<T>::Push(const T & t){
    QueueItem<T> *p=new QueueItem<T>(t);
    if(Empty()){
        head=p;
        tail=p;
    }else{
        tail->next=p;
        tail=p;
    }
}

template<class T>
void MyQueue<T>::Pop(){
    if(Empty()){
        cout<<"队空,无法出队!"<<endl;
    }else{
        QueueItem<T> *p=head;
        head=head->next;
        if(head==NULL){
            tail=NULL;
        }
        delete p;
    }
}


template<class T>
void MyQueue<T>::Display() const {
    QueueItem<T> *p = head;
    while(p != NULL){
        cout << p->item << " ";
        p = p->next;
    }
}


template<class T>
void MyQueue<T>::Destroy() {
    while(!Empty()) {
        Pop();
    }
}


template<class T>
void MyQueue<T>::CopyElements(const MyQueue & Q) {
    QueueItem<T> *p = Q.head;
    while(p != NULL) {
        Push(p->item);
        p = p->next;
    }
}


template<class T>
MyQueue<T> & MyQueue<T>::operator=(const MyQueue & rhs) {
    if(this != &rhs) { 
        Destroy();     
        CopyElements(rhs); 
    }
    return *this;
}

int main()
{
    MyQueue<int> qi;
    qi.Push(1);
    qi.Push(2);
    qi.Push(3);
    qi.Push(4);
    qi.Push(5);
    qi.Pop();
    qi.Display();
    cout<<"\n";
    cout<<qi;
    cout<<endl;

    MyQueue<int> qi2(qi);
    qi2.Display();
    cout<<endl;

    MyQueue<int> qi3;
    qi3 = qi;
    cout<<qi3;

    return 0;
}