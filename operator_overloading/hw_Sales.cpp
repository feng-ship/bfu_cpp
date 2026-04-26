#include<iostream>
#include<string>
using namespace std;
class Sales_data {
    friend istream & operator>>(istream&, Sales_data &);
    friend ostream & operator<<(ostream &, const Sales_data &);
    friend bool operator==(const Sales_data &, const Sales_data &);
    friend bool operator!=(const Sales_data &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
public:
    Sales_data(): units_sold(0), revenue(0.0) {}
    Sales_data(const string & s, unsigned n, double r): bookNo(s), units_sold(n), revenue(r) {}
    string get_bookNo() const;
    Sales_data & operator+=(const Sales_data &);
private:
    double avg_price() const;  //均价，等于收入除以销量
    string bookNo;        //书号
    unsigned units_sold; //销量
    double revenue;      //收入
};
istream & operator>>(istream& is, Sales_data & data){
    is>>data.bookNo>>data.units_sold>>data.revenue;
    return is;
}
ostream & operator<<(ostream& os, const Sales_data & data){
    os<<data.bookNo<<" "<<data.units_sold<<" "<<data.revenue<<" "<<data.avg_price();
    return os;
}
string Sales_data::get_bookNo() const{
    return bookNo;
}
double Sales_data::avg_price() const{
    return revenue/units_sold;
}
bool operator==(const Sales_data &s1, const Sales_data &s2){
    return (s1.bookNo==s2.bookNo);
}
bool operator!=(const Sales_data &s1, const Sales_data &s2){
    return (s1.bookNo!=s2.bookNo);
}
Sales_data operator+(const Sales_data &s1, const Sales_data &s2){
    Sales_data temp;
    temp.bookNo=s1.bookNo;
    temp.units_sold=s1.units_sold+s2.units_sold;
    temp.revenue=s1.revenue+s2.revenue;
    return temp;
}
Sales_data& Sales_data::operator+=(const Sales_data &s2){
    units_sold+=s2.units_sold;
    revenue+=s2.revenue;
    return *this;
}
int main(){
    Sales_data item1,item2;
    while(cin>>item1>>item2){
        cout<<item1<<"\n"<<item2<<"\n";
        if(item1==item2)
        cout<<item1.get_bookNo()<<" equals "<<item2.get_bookNo()<<"\n";
        if(item1!=item2)
        cout<<item1.get_bookNo()<<" doesn't equal "<<item2.get_bookNo()<<"\n";
        cout<<(item1+item2)<<"\n";
        item1 += item2;
        cout<<item1<<"\n";
    }
    return 0;
}


