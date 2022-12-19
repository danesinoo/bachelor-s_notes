#pragma once
#define u32 unsigned int

// class music
// has one static variable a u32 value
// has some derived classes

class music {
private:
  static u32 value;

public:
  music() {};
  virtual u32 get_value(u32 v = value) { return v; }
};

// class song
// is a derived class of music
// all instances of song have a value of 1

class song : public music {
private:
  static u32 value;

public:
  song() {};
  u32 get_value(u32 v = value) override { return music::get_value(v); }
};

class album : public music {
private:
  static u32 value;
  public:
  album() {};
  u32 get_value(u32 v = 0) override { return music::get_value(30); }
};
