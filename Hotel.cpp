#include<iostream>
#include<string>
using namespace std;
const int N=100;
class Hotel{
private: 
    string name;
    int number;
    static int total;
public:
    void add(string s);
    static int getTotal(){
        return total;
    }
    string getName() const;
    void print();
};
int Hotel::total=0;
void Hotel::add(string s){
    name=s;
    total++;
    number=total;
}
string Hotel::getName() const{
    return name;
}
void Hotel::print(){
    cout<<number<<" "<<name<<" "<<total<<endl;
}
int main(){
    Hotel h[100];
    h[0].add("Susan");
    h[1].add("Peter");
    h[2].add("John");
    h[3].add("Mary");
    h[4].add("Alice");
    string name;
    cin>>name;

    for(int i=0;i<Hotel::getTotal();i++)
    {
        if(h[i].getName()==name)
        {
            h[i].print();
            break;
        }
    }

    return 0;
}