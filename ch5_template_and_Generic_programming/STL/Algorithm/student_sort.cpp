#include <iostream>
#include <list>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;
    int score;

    Student(string n, int a, int s)
        : name(n), age(a), score(s) {}
};

// 按年龄升序排序
class AgeCmp {
public:
    bool operator()(const Student& a, const Student& b) {
        return a.age < b.age;
    }
};

// 按成绩降序排序
class ScoreCmp {
public:
    bool operator()(const Student& a, const Student& b) {
        return a.score > b.score;
    }
};

int main() {
    list<Student> stuList;

    stuList.push_back(Student("Tom", 20, 85));
    stuList.push_back(Student("Alice", 18, 95));
    stuList.push_back(Student("Bob", 19, 90));

    // 按年龄排序
    stuList.sort(AgeCmp());

    cout << "按年龄排序：" << endl;
    for (auto s : stuList) {
        cout << s.name << " "
             << s.age << " "
             << s.score << endl;
    }

    cout << endl;

    // 按成绩排序
    stuList.sort(ScoreCmp());

    cout << "按成绩排序：" << endl;
    for (auto s : stuList) {
        cout << s.name << " "
             << s.age << " "
             << s.score << endl;
    }

    return 0;
}