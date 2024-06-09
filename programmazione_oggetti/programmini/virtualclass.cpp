#include <iostream>
using namespace std;

class A {
	double d;
};

class B: public A {};

class C: public A {};

class D: public B, public C {};

int main() {
	cout << sizeof(A) << '\n';
	cout << sizeof(B) << '\n';
	cout << sizeof(C) << '\n';
	cout << sizeof(D) << '\n';
}
