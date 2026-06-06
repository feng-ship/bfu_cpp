#include<iostream>
#include<string>
using namespace std;
class voiceActor{
private:
    string Name;
    string Gender;
public:
    voiceActor(){};
    voiceActor(string n,string g){
        Name=n;
        Gender=g;
    }
    string get_name()const;
    string get_gender()const;
    friend class cartoon;
};
string voiceActor::get_name()const{
    return Name;
}
string voiceActor::get_gender()const{
    return Gender;
}
class cartoon{
private:
    string Name2;
    voiceActor voiceactor;
public:
    cartoon(string n,voiceActor v);
    string get_ca_name();
    string get_va_name();
    string get_va_gender();
};

cartoon::cartoon(string n,voiceActor v){
    Name2=n;
    voiceactor=v;
}
string cartoon::get_ca_name(){
    return Name2;
}
string cartoon::get_va_name(){
    return voiceactor.Name;
}
string cartoon::get_va_gender(){
    return voiceactor.Gender;
}
class seasonsCartoon:public cartoon{
private:
    int Number;
public:
    seasonsCartoon(string n1,voiceActor v,int t);
    int getNumber();
};
seasonsCartoon::seasonsCartoon(string n1,voiceActor v,int t):cartoon(n1,v){
    Number=t;
}
int seasonsCartoon::getNumber(){
    return Number;
}
void show(cartoon ca){
    cout<<"cartoon name: "<<ca.get_ca_name()<<endl;
    cout<<"voice actor: "<<ca.get_va_name()<<", "<<ca.get_va_gender();
}
void show(seasonsCartoon sc){
    cout<<"cartoon name: "<<sc.get_ca_name()<<endl;
    cout<<"voice actor: "<<sc.get_va_name()<<", "<<sc.get_va_gender()<<endl;
    cout<<"number of seasons: "<<sc.getNumber();
}
int main(){
    string name_of_voiceActor, gender_of_voiceActor; 
    cin>>name_of_voiceActor>>gender_of_voiceActor; // 输入配音演员的姓名和性别 
    const voiceActor va(name_of_voiceActor,gender_of_voiceActor); // 定义一个常配音演员对象 
    cout<<"voice actor: "<<va.get_name()<<", "<<va.get_gender()<<'\n'; // 输出配音演员的姓名和性别 

    string name_of_cartoon;
    cin>>name_of_cartoon; // 输入动画片的名字 
    const cartoon c(name_of_cartoon,va); // 构造一个常动画片对象 

    int number_of_seasons;
    cin>>number_of_seasons; // 输入季度动画片的季度数（比如第7季） 
    const seasonsCartoon sc(name_of_cartoon, va, number_of_seasons); // 构造一个常季度动画片对象 

    show(c); // 输出动画片的名字，所用的配音演员的名字和性别（参见输出样例） 
    cout<<"\n";
    show(sc); // 输出季度动画片的名字，所用的配音演员的名字、性别，以及季度数（参见输出样例）

    return 0;
}