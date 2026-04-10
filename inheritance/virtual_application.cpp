#include<iostream>
using namespace std;
class Animal{
public:
    virtual void speak(){
        cout<<"say"<<endl;
    }
};
class Dog:public Animal{
public:
    void speak(){
        cout<<"汪汪汪"<<endl;
    }
};
class Cat:public Animal{
public:
    void speak(){
        cout<<"喵喵喵"<<endl;
    }
};
void sayhello(Animal* a){//或者：void sayhello(Animal &ref){ref.speak}
    a->speak();
}
int main(){
    Dog dog;
    Cat cat;
    sayhello(&dog);//或者:sayhello(dog);
    sayhello(&cat);
    return 0;
}
