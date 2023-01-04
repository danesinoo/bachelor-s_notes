/*
 * Definire un template di funzione Fun(T1*, T2&) che ritorna un booleano con il
 * seguente comportamento. Consideriamo una istanziozione implicita Fun(p, r)
 * dove supponiamo che i parametri di tipo T1 e t2 siano istanzioati a tipo
 * polimorfi. Allora Fun(p, r) ritorna true se e solotano se valgono le seguenti
 * condizioni:
 *
 * 1) i prarametri di tipo T1 e T2 sono istanziati allo stesso tipo;
 * 2) siano D1* il tipo dinamico di p e D2& il tio dinamico di r. Allora:
 *	(i)	D1 e D2 sono lo stesso tipo
 *	(ii) questo tipo è un sottotipo proprio della classe ios della gerarchia
 *di classi I/O (ios è la base astratta della cerarchia).
 */

#include <fstream>
#include <iostream>
#include <typeinfo>
using namespace std;

template <class T1, class T2> bool Fun(T1 *p, T2 &r) {
  return typeid(T1) == typeid(T2) && // verifica 1
         typeid(*p) == typeid(r) &&  // verifica 2(i)
         dynamic_cast<ios *>(p) != 0 &&
         dynamic_cast<ios *>(&r) != 0; // verifica 2(ii)
}

class C {
public:
  virtual ~C() {}
};

int main() {
  ifstream f("pippo");
  fstream g("pluto"), h("zagor");
  iostream *p = &h;
  C c1, c2;
  cout << Fun(&cout, cin) << "\n";  // stampa 0		1:	0
  cout << Fun(&cout, cerr) << "\n"; // stampa: 1	1:	1
  cout << Fun(p, h) << "\n";        // stampa: 0	1:	1 -> 0
  cout << Fun(&f, *p) << "\n";      // stampa: 0	1:	0
  cout << Fun(&g, h) << "\n";       // stampa: 1	1:	1 -> 0
  cout << Fun(&c1, c2) << "\n";     // stampa: 0	1:	1 -> 0
  return 0;
}
