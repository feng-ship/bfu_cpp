#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Student{
private:
    string no;
    int math;
    int eng;
public:
    Student(string n="-1",int m=-1,int e=-1);
    void show();
};
Student::Student(string n,int m,int e){
    no=n;
    math=m;
    eng=e;
}
void Student::show(){
    cout<<no<<","<<math<<","<<eng<<","<<endl;
}
int main(){
    Student s;
    string n;
    int m;
    int e;
    fstream fs;
    fs.open("Users\\xiaohan\\bfu_cpp\\student.dat",ios::in|ios::out|ios::trunc|ios::binary);
    if(!fs.is_open()){
        cout<<"打开失败"<<endl;
        exit(0);
    }
    for(int i=0;i<10;i++){
        n="00"+to_string(i);
        m=rand()%101;
        e=rand()%101;
        cout<<n<<","<<m<<","<<e<<endl;
        fs.write((char *)new Student(n,m,e),sizeof(s));
    }
    int a;
    char c[200];
    while(true){
        cout<<"输入一个学生序号(0-9),-1退出:";
        cin>>a;
        if(a==-1){
            break;
        }else if(a>9||a<0){
            continue;
        }
        fs.seekg(a*sizeof(s),ios::beg);//移动文件指针
        fs.read((char *)&s,sizeof(s));
        s.show();
    }
    fs.close();
    return 0;
}