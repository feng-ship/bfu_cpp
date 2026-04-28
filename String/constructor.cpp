#include <iostream>
#include <string>
using namespace std;
int main() {
    // 1. 默认构造
    string s1;
    cout << "s1 (default): [" << s1 << "]\n";

    // 2. C风格字符串构造
    string s2("Hello World");
    cout << "s2 (c-string): " << s2 << "\n";

    // 3. 拷贝构造
    string s3(s2);
    cout << "s3 (copy): " << s3 << "\n";

    // 4. 填充构造
    string s4(10, '*');
    cout << "s4 (fill): " << s4 << "\n";

    // 5. 子串构造
    string s5(s2, 6, 5);
    cout << "s5 (substring): " << s5 << "\n";

    // 6. C风格部分构造
    string s6("Beautiful Day", 9);
    cout << "s6 (c-string part): " << s6 << "\n";

    // 7. 迭代器范围构造
    string s7(s2.begin() + 6, s2.end());
    cout << "s7 (iterator range): " << s7 << "\n";

    // 8. C++11 初始化列表 (补充)
    string s8 = {'H', 'i'};
    cout << "s8 (initializer list): " << s8 << "\n";

    return 0;
}