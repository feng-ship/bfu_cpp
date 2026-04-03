#include<iostream>
#include<string>
using namespace std;
class Student{
private:
    string name;
    int score;
public:
    friend class Teacher;
    Student(){};
};
class Teacher{
private:
    Student stu[100];
    int count;
public:
    Teacher(){count=0;};
    void addstudent(string n,int s);
    void display();
};
void Teacher::addstudent(string n,int s){
    stu[count].name=n;
    stu[count].score=s;
    count++;
}
void Teacher::display(){
    for(int i=0;i<count;i++){
        cout<<stu[i].name<<":"<<stu[i].score<<endl;
    }
}
int main(){
    Teacher t1;
    t1.addstudent("张三",98);
    t1.addstudent("李四",78);
    t1.display();
    return 0;
}
