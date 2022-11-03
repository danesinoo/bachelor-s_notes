#include <iostream>
#include <bits/c++.h>

class C {
    public:
        int x;

        C(int a =0) { x=0; };

        void f(int& a) const { a = 4; };

        void m() { f(x); };
};

int main(void) {
    C tmp(8);
    tmp.m();
    std::cout << tmp.x << std::endl;
    return 0;
}
