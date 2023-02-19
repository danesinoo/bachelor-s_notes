#pragma once
#define u32 unsigned int
#include <iostream>

// class music
// has one static variable a u32 value
// has some derived classes

class A {
public:
  virtual A *n() {
    std::cout << " A::n()";
    return this;
  }

  virtual void g() const { std::cout << " A::g()"; }
};

class B : public A {
public:
  A *n() override {
    std::cout << " B::n()";
    return this;
  }

  virtual void g() const override { std::cout << " B::g()"; }
};

class C : public A {};
