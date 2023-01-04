#include <ios>
#include <iostream>
using namespace std;

int F(ios &ref) {
  if (dynamic_cast<istream *>(&ref)) {
    if (dynamic_cast<ostream *>(&ref))
      return 0;
    return -1;
  } else if (dynamic_cast<ostream *>(&ref))
    return 1;
  else
    return 9;
}

class D : public ios {};

int main() {
  istream &b = cin;
  ostream &c = cout;
  stringstream d;
  ifstream e("pippo");
  ofstream f("pluto");
  D g;
  cout << F(b) << ' ' << F(c) << ' ' << F(d) << ' ' << F(e) << ' ' << F(f)
       << ' ' << F(g) << endl;
  return 0;
  // stampa: -1 1 0 -1 1 9
}
