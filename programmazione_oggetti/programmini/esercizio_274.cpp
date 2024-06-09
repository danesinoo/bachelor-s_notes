#include <iostream>

class C {
    public: 
        C() {}
        C(const C& r) {std::cout << "*"; };
};

C f(C a) {
    C b(a);
    C c= b;
    return c;
}

int main() {
    C x;
    C y = f(f(x));
}
