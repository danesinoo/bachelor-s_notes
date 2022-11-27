#include <iostream>
using namespace std;

class Z { 
    public:
        ostream& operator<<(ostream& os) const { return os << "Hello";}
        Z operator++() { return Z();}
        Z operator++(int) {
            cout << "Hello";
            return *this;
        }
        Z() {}
};

template <class T1, class T2=Z> 
class C {
    public:
        T1 x;
        T2* y;
};

template <class T1,class T2>
void fun (C<T1, T2>* q) {
    ++(q->y);
    if (true == false) 
        ++(q->x) << cout; 
    else 
        q->y;
    (q->x)++;
    if (*(q->y) == q->x) *(q->y) = q->x;
    T1* ptr = &(q->x);
    T2 t2 = q->x;
}

int main() {
    C<Z> c1; 
    fun (&c1); 
    C<int> c2; 
    fun(&c2);
}
