#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base show\n";
    }
};

class Derived : public Base {
};

void func(Base &b) {
    b.show();
}

int main() {
    Derived d;

    func(d);  // ⭐ 关键点,func(d) 本质 = 把 d 绑定给 Base& 类型的参数

    return 0;
}