#include<iostream>
#include<cstring>
using namespace std;
class Date
{
public:
   Date(int d = 0, int m = 0, int y = 0); //构造函数
   int get_day() const; // 返回day
   int get_month() const; //返回month
   int get_year() const; // 返回year
   static void set_default(int, int, int); //设置default_date
   static int get_default_day(); //返回缺省day
   static int get_default_month(); //返回缺省month
   static int get_default_year(); //返回缺省year
   Date & add_year(int n); //加n年
   Date & add_month(int n); //加n月，考虑超过12月
   Date & add_day(int n); //加n天，考虑进位月和年，考虑闰年
private:
   int day, month, year;
   static Date default_date; //初始化为 1901年1月1日
};
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int isLeap(int y){
    if((y%4==0&&y%100!=0)||y%400==0){
        return 1;
    }
    return 0;
};
int total_days(int d,int m,int y){
    int sum=d;
    for(int i=1;i<=m;i++){
        sum+=days[i];
        if(i==2) sum++;
    }
    for(int i=1;i<=y;i++){
        sum+=365;
        if(isLeap(i)) sum++;
    }
    return sum;
};
int AddToYear(int total){
    
};
Date::Date(int d,int m,int y){
    day=d;
    month=m;
    year=y;
}
Date Date::default_date(1,1,1901);
void Date::set_default(int d,int m,int y){
    default_date=Date(d,m,y);
} 
int Date::get_default_day(){
    return default_date.day;
}
int Date::get_default_month(){
    return default_date.month;
}
int Date::get_default_year(){
    return default_date.year;
}
int Date::get_day() const{
    return day;
}
int Date::get_month() const{
    return month;
}
int Date::get_year() const{
    return year;
}
Date & Date::add_year(int n){
    year+=n;
    return *this;
}
Date & Date::add_month(int n){
    month+=n;
    month=month%12;
    return *this;
}
Date & Date::add_day(int n){
    day+=n;
    return *this;
}
int main()
{
   char type[110];
   int day,mon,year;
   int addday,addmon,addyear;
   while(cin>>type)
   {
      if(strcmp(type,"Date") == 0)
      {
         cin>>day>>mon>>year;
         Date mydate(day,mon,year);
         cin>>addday>>addmon>>addyear;
         mydate.add_day(addday).add_month(addmon).add_year(addyear);
         cout << mydate.get_day() << " " << mydate.get_month() << " " << mydate.get_year() << endl;
      }
      else if(strcmp(type,"defaultDate") == 0) 
      {
          cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;
      }
      else if(strcmp(type,"setdefaultDate") == 0)
      {
         cin>>day>>mon>>year;
         Date::set_default(day,mon,year);
         cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;
      }
   }
   return 0;
}
