#include<iostream>
#include<string>
#include<sstream>
void readPapers(std::string str){
    int words=0;
    int punct=0;
    for(std::string::size_type index=0;index!=str.size();++index){
        if(str[index]=='.'||str[index]==','||str[index]=='"'){
            punct++;
            str[index]=' ';
        }
    }
    std::stringstream ss(str);
    std::string word;
    while(ss>>word){
        words++;
    }
    std::cout<<words<<","<<punct<<std::endl;;

}
int main() {
    std::string content;
    std::getline(std::cin, content, '\n');
    readPapers(content);
    return 0;
}