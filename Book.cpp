#include<iostream>
#include<cstring>
using namespace std;
const int N=101;
class Book{
private:
    char* name;
    char* author;
    int sale;
public:
    Book();
    Book(const char* n,const char* a,int s);
    Book(const Book &b);
    void print() const;
    ~Book();
};
Book::Book(){
    const char* n="No name";
    const char* a="No author";
    name=new char[strlen(n)+1];
    strcpy(name,n);
    author=new char[strlen(a)+1];
    strcpy(author,a);
    sale=0;
}
Book::Book(const Book &b){
    name=new char[strlen(b.name)+1];
    strcpy(name,b.name);
    author=new char[strlen(b.author)+1];
    strcpy(author,b.author);
    sale=b.sale;
}
Book::Book(const char* n,const char* a,int s){
    name=new char[strlen(n)+1];
    strcpy(name,n);
    author=new char[strlen(a)+1];
    strcpy(author,a);
    sale=s;
}
void Book::print() const{
    cout<<"Name: "<<name<<"\tAuthor: "<<author<<"\tSale: "<<sale<<endl;
}
Book::~Book(){
    delete[] name;
    delete[] author;
}
int main(){
    char na[N],au[N];
    int s;
    cin.getline(na,N);
    cin.getline(au,N);
    cin>>s;
    if(strcmp(na,"-1")==0&&strcmp(au,"-1")==0&&s==-1){
        Book b1;
        b1.print();
        return 0;
    }
    if(strcmp(na,"0")==0&&strcmp(au,"0")==0&&s==0){
        Book bk1;
        Book bk2(bk1);
        bk2.print();
        return 0;
    }
    Book bk3(na,au,s);
    bk3.print();
    return 0;
}