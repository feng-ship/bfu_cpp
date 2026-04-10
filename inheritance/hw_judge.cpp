#include<iostream>
#include<cmath>
using namespace std;
class Score{
private:
    string name;
    double s[4];
    double total;
    char grade; 
public:
    Score(char grade='B'){};
    void Input(){
        string n;
        int a1,a2,m,f;
        cin>>n>>a1>>a2>>m>>f;
        name=n;
        s[0]=a1;
        s[1]=a2;
        s[2]=m;
        s[3]=f;
    }
    void Evalauate(){
        total=(s[0]+s[1])*0.25+s[2]*0.25+s[3]*0.5;
        if(90<=total&&total<=100) grade='A';
        if(80<=total&&total<=89) grade='B';
        if(70<=total&&total<=79) grade='C';
        if(60<=total&&total<=69) grade='D';
        if(total<60) grade='E';
    }
    void Output(){
        if(0<=s[0]&&s[0]<=50&&0<=s[1]&&s[1]<=50&&0<=s[2]&&s[2]<=100&&0<=s[3]&&s[3]<=100){
            cout<<"name: "<<name<<", "<<"total: "<<total<<", "<<"grade: "<<grade<<endl;
        }else {
            cout<<"error"<<endl;
        }
    }
};
int main()
{
    Score *s1=new Score;
    s1->Input();
    s1->Evalauate();
    s1->Output();
    return 0;
}