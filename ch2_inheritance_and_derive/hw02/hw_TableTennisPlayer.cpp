#include<iostream>
#include<cstring>
using namespace std;
class TableTennisPlayer{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string &, const string &, bool);
    string FirstName() const;
    string LastName() const;
    bool HasTable() const;
};
TableTennisPlayer::TableTennisPlayer(const string &fir, const string &la, bool b){
    firstname=fir;
    lastname=la;
    hasTable=b;
}
string TableTennisPlayer::FirstName() const{
    return firstname;
}
string TableTennisPlayer::LastName() const{
    return lastname;
}
bool TableTennisPlayer::HasTable() const{
    return hasTable;
}
class RatedPlayer:public TableTennisPlayer{
private:
    int rating;
public:
    RatedPlayer(int r,string f,string l,bool h);
    int Rating();
};
RatedPlayer::RatedPlayer(int r,string f,string l,bool h):TableTennisPlayer(f,l,h){
    rating=r;
}
int RatedPlayer::Rating(){
    return rating;
}
int main(){
    string firstname, lastname;
    bool hasTable;
    int rating;
    char flag;
    while(cin>>flag){
        if(flag=='T'){
            cin>>firstname>>lastname>>hasTable;
            TableTennisPlayer tp(firstname,lastname,hasTable);
            if(tp.HasTable())
            cout<<tp.FirstName()<<" "<<tp.LastName()<<" has a table.\n";
            else
            cout<<tp.FirstName()<<" "<<tp.LastName()<<" hasn't a table.\n";
        } else if(flag=='R'){
            cin>>firstname>>lastname>>hasTable>>rating;
            RatedPlayer rp(rating,firstname,lastname,hasTable);
            if(rp.HasTable())
            cout<<rp.FirstName()<<" "<<rp.LastName()<<" has a table. The rating is "<<rp.Rating()<<".\n";
            else
            cout<<rp.FirstName()<<" "<<rp.LastName()<<" hasn't a table. The rating is "<<rp.Rating()<<".\n";
        }
    }
    return 0;
}
