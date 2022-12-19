#include "music.h"
#include <iostream>

u32 music::value = 10;
u32 song::value = 20;
u32 album::value = 30;

int main() {
  music m;
  song s;
  album a;
  std::cout << "music value: " << m.get_value() << std::endl;
  std::cout << "song value: " << s.get_value() << std::endl;
  std::cout << "album value: " << a.get_value() << std::endl;
  return 0;
}
