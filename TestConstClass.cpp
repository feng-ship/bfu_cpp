#include<iostream>
#include<string>
using namespace std;
class TestConstClass{
private:
    string s;
public:
    void set(string n);
    string get() const;
};
void TestConstClass::set(string n){
    s=n;
}
string TestConstClass::get() const{
    return s;
}
void print (const TestConstClass &tcs) {
    cout << tcs.get()<<'\n';
}

int main() {
    string tmp;
    TestConstClass tcs;
    while(cin>>tmp){
        tcs.set(tmp);
        print(tcs);
    }
    return 0;
}
