#include<iostream>
#include<string>
#include<sstream>
#include<map>
using namespace std;
unsigned termFrequency(std::string str,std::map<std::string,unsigned>& mp){
    for(std::string::size_type index=0;index!=str.size();++index){
        if(str[index]=='.'||str[index]==','||str[index]=='"'){
            str[index]=' ';
        }
        if(isupper(str[index])){
            str[index]=tolower((unsigned char)str[index]);
        }
    }
    std::stringstream ss(str);
    std::string s;
    while(ss>>s){
        if(isdigit(s[0])) continue;
        mp[s]++;
    }
    return mp.size();
}
void alphabetSortedFrequency(std::map<std::string,unsigned>& mp){
    for(auto it=mp.begin();it!=mp.end();it++){
        std::cout<<it->first<<":"<<it->second<<std::endl;
    }
}
int main() {

    // 从标准输入获取文本串
    std::string content;
    std::getline(std::cin, content, '\n');

    map<string, unsigned> msu;

    // 要求termFrequency实现分词，去掉标点
    // 获取单词存放在map中，记录词频（出现次数）
    // 最后返回不重复的单词数量    
    unsigned nWords = termFrequency(content, msu);

    // 按首字母A-Z排序一行一词输出词频
    alphabetSortedFrequency(msu);

    return 0;
}
