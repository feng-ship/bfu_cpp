#include<iostream>
#include<cstring>
using namespace std;
class Student{
private:
    string name;
    int age;
public:
    Student(string n,int a){
        name=n;
        age=a;
    }
    friend class Teacher;
};
class Teacher{
public:
    void showstu(const Student &s){
        cout<<"name:"<<s.name<<",age:"<<s.age<<endl;
    }
};
int main(){
    Student s1("张三",18);
    Teacher t1;
    t1.showstu(s1);
    return 0;
}