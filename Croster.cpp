#include<iostream>
#include<string>
using namespace std;
class Date    
{
private:
    int Date_year;    //年
    int Date_month;    //月
    int Date_day;    //日
public:
    Date(int year=2000, int month=1, int day=1);
    void show() const;    //以“年-月-日”格式输出年月日
};
Date::Date(int year, int month, int day){
    Date_year=year;
    Date_month=month;
    Date_day=day;
}
void Date::show() const{
    cout<<Date_year<<"-"<<Date_month<<"-"<<Date_day<<endl;
}
class Croster    //名单类
{
private:
    string name;
    Date birthday;
public:
    Croster();
    Croster(string name,int year,int month,int day);
    Croster(string name, Date date);
    void show() const;//显示姓名和出生日期
};
Croster::Croster():name("NULL"),birthday(0,0,0){}
Croster::Croster(string name,int year,int month,int day){
    this->name=name;//同名区分，this指针指向当前对象
    birthday=Date(year,month,day);//调用Date类的构造函数创建一个临时对象，并将其赋值给birthday成员变量
}
Croster::Croster(string name, Date date){
    this->name=name;//同名区分，this指针指向当前对象
    birthday=date;//将传入的Date对象赋值给birthday成员变量
}
void Croster::show() const{
    cout<<"Name: "<<name<<", Birthday: ";
    birthday.show();
}
int main(){
    int num;
    while(cin>>num){//多轮输入用while循环，条件是输入成功
        if(num==-1) break;//输入-1结束程序
        switch(num){
            case 0:{
                Croster c1;
                c1.show();
                break;
            }
            case 1:{
                string name;
                int ye,mo,da;
                cin>>name;
                cin>>ye>>mo>>da;
                Croster c2(name,ye,mo,da);
                c2.show();
                break;
            }
            case 2:{
                string name;
                int ye,mo,da;
                cin>>name;
                cin>>ye>>mo>>da;
                Date date2(ye,mo,da);
                Croster c3(name,date2);
                c3.show();
                break;
            } 
        }
    }
    return 0;
}