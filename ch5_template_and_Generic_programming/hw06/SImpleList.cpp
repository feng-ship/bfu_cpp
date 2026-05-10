#include<iostream>
#include<list>
#include<functional>
#include<string>
using namespace std;
struct Student{
    int no;
    string name;
};
void Input(list<Student> &li){
    int n;
    cin>>n;
    Student stu[n];
    for(int i=0;i<n;i++){
        cin>>stu[i].no>>stu[i].name;
        li.push_back(stu[i]);
    }
}
void Show(const list<Student> &li){
    for(list<Student>::const_iterator it1=li.begin();it1!=li.end();it1++){
        cout<<it1->no<<", "<<it1->name<<endl;
    }
}
int main(){
    list<Student> li;
    Input(li);
    Show(li);
    return 0;
}