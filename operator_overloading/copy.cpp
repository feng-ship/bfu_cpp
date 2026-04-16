#include<iostream>
#include<cstring>
using namespace std;
class String{
private:
    char* str;
public:
//含有指针的，关注构造函数中的内存分配
    String(const char* s=""){
        str=new char[strlen(s)+1];
        strcpy(str,s);
    };
    //析构函数必须把指针指向空间释放
    ~String(){
        delete[] str;
    }
    void show(){
        cout<<str<<endl;
    }
    String& operator=(String& s1){
        delete[] str;
        str=new char[strlen(s1.str)+1];
        strcpy(str,s1.str);
        return *this;
    }
};
int main(){
    String s1("Hello World~");
    String s2;
    s2=s1;
    s2.show();
    return 0;
}