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
    Derived d;

    Base *p = &d;   // ⭐ 关键：基类指针指向派生类对象

    p->show();      // ✅ 可以（Base里的函数）

    // p->print();  // ❌ 不行（Base里没有）

    return 0;
}