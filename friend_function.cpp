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
    friend void show_info(const Student &s);
};
void show_info(const Student &s){
    cout<<s.name<<":"<<s.age<<endl;
}
int main(){
    Student s1("张三",18);
    show_info(s1);
    return 0;
}
