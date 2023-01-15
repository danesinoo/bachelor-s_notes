#pragma once
#define u32 unsigned int
#include <iostream>

// class music
// has one static variable a u32 value
// has some derived classes

class A {
  int a;

public:
  virtual void attack() const { std::cout << "A::attack()" << std::endl; }
};

class B : public A {
public:
  void attack() const override { std::cout << "B::attack()" << std::endl; }
};

class C : public A {
public:
  void attack() const override { std::cout << "C::attack()" << std::endl; }
};

template <typename T> T *Hello(T *t) { return new T(*t); }

A *Ptr(A *a) { return a; }
