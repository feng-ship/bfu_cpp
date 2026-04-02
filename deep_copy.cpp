#include<iostream>
#include<cstring>
using namespace std;
class Student{
private:
    char* name;
public:
    //普通构造
    Student(const char *s){
        name=new char[strlen(s)+1];
        strcpy(name,s);
        cout<<"调用普通构造函数"<<endl;
    }
    //深拷贝构造
    Student(const Student &s){
        name=new char[strlen(s.name)+1];
        strcpy(name,s.name);
        cout<<"调用深拷贝构造函数"<<endl;
    }
    //析构函数
    ~Student(){
        delete[] name;
    }
    void show(){
        cout<<name<<endl;
    }
};
int main(){
    Student s1("张三");//调用普通构造
    Student s2=s1;//调用深拷贝
    s1.show();
    s2.show();
    return 0;
}