#include<iostream>
using namespace std;
class Student{
public:
    friend class Teacher;
    Student(){};
private:
    int number,score;
};
class Teacher{
private:
    Student a;
public:
    Teacher(int i,int j);
    void display();
};
Teacher::Teacher(int i,int j){
    a.number=i;
    a.score=j;
}
void Teacher::display(){
    cout<<"No="<<a.number<<" "<<"Score="<<a.score<<endl;
}
int main(){
    Teacher t1(10001,98);
    cout<<"第一个学生的信息:"<<endl;
    t1.display();
    Teacher t2(10002,99);
    cout<<"第二个学生的信息:"<<endl;
    t2.display();
}