#include<iostream>
using namespace std;
class Date{
private:
    int year,month,day;
public:
    Date(int i,int j,int k);
    void display_date();
};
Date::Date(int i,int j,int k){
    year=i;
    month=j;
    day=k;
}
void Date::display_date(){
    cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
}
class Time{
private:
    int hour,minute,second;
public:
    Time(int p,int q,int r);
    void display_time();
};
Time::Time(int p,int q,int r){
    hour=p;
    minute=q;
    second=r;
}
void Time::display_time(){
    cout<<hour<<"时"<<minute<<"分"<<second<<"秒";
}
class Schedule{
private:
    Time time;
    Date date;
public:
    Schedule(int a,int b,int c,int d,int e,int f);
    void show();
};
Schedule::Schedule(int a,int b,int c,int d,int e,int f):date(a,b,c),time(d,e,f){
}
void Schedule::show(){
    date.display_date();
    time.display_time();
}
int main(){
    Schedule s1(2026,4,3,16,11,50);
    s1.show();
    return 0;
}

