#include<iostream>
#include<string>
using namespace std;
class Vehicle{
protected:
    string name;
    string color;
public:
    Vehicle(string n,string c){
        name=n;
        color=c;
    }
    virtual void display()=0;
};
class Car:public Vehicle{
private:
    int cover;
public:
    Car(string n,string c,int t);
    void display();
};
Car::Car(string n,string c,int t):Vehicle(n,c){
    cover=t;
}
void Car::display(){
    cout<<"Car name:"<<name<<" "<<"Car color:"<<color<<" "<<"Car passenger:"<<cover<<endl;
}
class Truck:public Vehicle{
private:
    double capacity;
public:
    Truck(string n,string c,double ca):Vehicle(n,c){
        capacity=ca;
    }
    void display();
};
void Truck::display(){
    cout<<"Truck name:"<<name<<" "<<"Truck color:"<<color<<" "<<"Truck capacity:"<<capacity<<endl;
}
int main(){
    Vehicle *p;
    char type;
    char name[110],color[110];
    int pas;
    double cap;
    while(cin>>type)
    {
        cin>>name>>color;
        if(type == 'C'){
            cin>>pas;
            Car car(name,color,pas);
            p = &car;
            p->display();
        }
        else if(type == 'T'){
            cin>>cap;
            Truck truck(name,color,cap);
            p = &truck;
            p->display();
        }
    }
    return 0;
}
