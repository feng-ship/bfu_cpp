#include<iostream>
#include<string>
using namespace std;
class Sport{
private:
    string Name;
    int Count;
public:
    Sport(){};
    Sport(string n,int c);
    friend class SportsMeeting;
    string getName()const;
    int getParticipantCount()const;
};
Sport::Sport(string n,int c){
    Name=n;
    Count=c;
}
string Sport::getName() const{
    return Name;
}
int Sport::getParticipantCount()const{
    return Count;
}
class SportsMeeting{
private:
    Sport s[20];//包含sport的数组，所以sport必须有无参构造函数
    int Total;
public:
    SportsMeeting();
    SportsMeeting(Sport *s,int t);
    void addSport(const Sport &sport);
    int getSportCount();
    Sport getSport(int t);
};
SportsMeeting::SportsMeeting(){
    Total=0;
}
SportsMeeting::SportsMeeting(Sport *s,int t){
    *s=s[0];
}
void SportsMeeting::addSport(const Sport &sport){
    s[Total]=sport;
    Total++;
}
int SportsMeeting::getSportCount(){
    return Total;
}
Sport SportsMeeting::getSport(int t){
    return s[t];
}
int main() {
    SportsMeeting freshmanSports;  // 新生运动会

    string sportName;              // 某项运动名称
    int participantCount;          // 参加某项运动的人数

    while (cin >> sportName >> participantCount && participantCount != 0) {
        freshmanSports.addSport(Sport(sportName, participantCount)); // 添加某项运动到新生运动会项目列表中 
        //注意：因为 main 函数中传入的是临时对象 Sport(sportName, participantCount)
        //非常量引用（Sport &）无法绑定到临时对象，必须使用常量引用（const Sport &）
    }

    int sportCount = freshmanSports.getSportCount(); // 新生运动会中的项目数 

    cout << sportCount << '\n';

    for (int i = 0; i < sportCount; i++) {  // 输出每个运动项目的名称和参加人数
        const Sport & sport = freshmanSports.getSport(i);
        cout << sport.getName() << ' '
             << sport.getParticipantCount() << '\n';
    }

    return 0;
}