#include<iostream>
#include<cstring>
using namespace std;
class String
{
private:
    char * s;
public:
    String();
    String(const char *);
    String(const String &);
    ~String();
    String & operator=(const char *);
    String & operator=(const String &);
    String operator+(const char *);
    String operator+(const String &);
    String & operator+=(const char *);
    String & operator+=(const String &);
    friend istream & operator>>(istream &, String &);
    friend ostream & operator<<(ostream &, const String &);
    friend bool operator==(const String &, const char *);
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const char *);
    friend bool operator!=(const String &, const String &);
};
String::String(){
    s=new char[1];
    s[0]='\0';
}
String::String(const char *s1){
    s=new char[strlen(s1)+1];
    strcpy(s,s1);
}
String::String(const String &s1){
    s=new char[strlen(s1.s)+1];
    strcpy(s,s1.s);
}
String::~String(){
    delete[] s;
}
String & String::operator=(const char *s1){
    delete[] s;
    s=new char[strlen(s1)+1];
    strcpy(s,s1);
    return *this;
}
String & String::operator=(const String &s1){
    delete[] s;
    s=new char[strlen(s1.s)+1];
    strcpy(s,s1.s);
    return *this;
}
String String::operator+(const char *s1){
    char *temp=new char[strlen(s)+strlen(s1)+2];
    strcpy(temp,this->s);
    strcat(temp," ");
    strcat(temp,s1);
    String result(temp);
    delete[] temp;
    return result;
}
String String::operator+(const String &s1){
    char *temp=new char[strlen(s)+strlen(s1.s)+2];
    strcpy(temp,this->s);
    strcat(temp," ");
    strcat(temp,s1.s);
    String result(temp);
    delete[] temp;
    return result;
}
String & String::operator+=(const char *s1){
    char *old_s=s;
    s=new char[strlen(old_s)+strlen(s1)+2];
    strcpy(s,old_s);
    strcat(s,s1);
    delete[] old_s;
    return *this;
}
String & String::operator+=(const String &s1){
    char *old_s=s;
    s=new char[strlen(old_s)+strlen(s1.s)+2];
    strcpy(s,old_s);
    strcat(s,s1.s);
    delete[] old_s;
    return *this;
}
istream & operator>>(istream &is, String &s1){
    char temp[1000];
    is>>temp;
    s1=temp;
    return is;
}
ostream & operator<<(ostream &os, const String &s1){
    os<<s1.s;
    return os;
}
bool operator==(const String &s1, const char *s2){
    return(strcmp(s1.s,s2)==0);
}
bool operator==(const String &s1, const String &s2){
    return(strcmp(s1.s,s2.s)==0);
}
bool operator!=(const String &s1, const char *s2){
    return!(strcmp(s1.s,s2)==0);
}
bool operator!=(const String &s1, const String &s2){
    return!(strcmp(s1.s,s2.s)==0);
}
int main()
{
    String s;
    s += "hello";
    cout<<s<<endl;
    String s1("String1");
    String s2("copy of ");
    s2 += "String1";
    cout << s1 << "\n" << s2 << endl;
    String s3;
    cin >> s3;
    cout << s3 << endl;
    String s4("String4"), s5(s4);
    cout << (s5 == s4) << endl;
    cout << (s5 != s4) << endl;
    String s6("End of "), s7("my string.");
    s6 += s7;
    cout << s6 << endl;
    return 0;
}


