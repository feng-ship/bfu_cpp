#include<iostream>
#include<string>
using namespace std;
class Singer{
private:
    string name;
    char gender;
    int age;
    double score;
public:
    Singer();
    string getName();
    friend bool operator>(Singer& sing1,Singer& sing2);
    friend bool operator==(Singer& sing1,Singer& sing2);
    friend istream& operator>>(istream &is,Singer& sing);
    friend ostream& operator<<(ostream &os,Singer& sing);
};
Singer::Singer(){
}
string Singer::getName(){
    return name;
}
istream& operator>>(istream &is,Singer& sing){
    is>>sing.name>>sing.gender>>sing.age>>sing.score;
    return is;
}
ostream& operator<<(ostream &os,Singer& sing){
    os<<sing.name<<" "<<sing.gender<<" "<<sing.age<<" "<<sing.score;
    return os;
}
bool operator>(Singer& sing1,Singer& sing2){
    return (sing1.score>sing2.score);
}
bool operator==(Singer& sing1,Singer& sing2){
    return (sing1.score==sing2.score);
}
int main(){
    Singer s1,s2;
    cin>>s1>>s2;
    cout<<s1<<"\n"<<s2<<endl;
    if(s1>s2)
    cout<<s1.getName()<<"'s score is higher than "<<s2.getName()<<"'s.\n";
    else if(s1==s2)
    cout<<s1.getName()<<"'s score is equal to "<<s2.getName()<<"'s.\n";
    else
    cout<<s1.getName()<<"'s score is lower than "<<s2.getName()<<"'s.\n";
    return 0;
}