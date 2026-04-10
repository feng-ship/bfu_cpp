#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base::show()" << endl;
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived::print()" << endl;
    }
};

int main() {
    Derived d;          // 派生类对象

    Base &b = d;        // ⭐ 关键：基类引用绑定派生类对象

    b.show();           // ✅ 可以调用（Base里的函数）

    // b.print();       // ❌ 编译错误（Base里没有这个函数）

    return 0;
}