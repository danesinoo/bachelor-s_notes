#include <iostream>
using namespace std;

template <class X> X &fun(X &ref) { return ref; }

int main() {
  B b;
  fun<A>(b);      // B <= A
  B *p = new D(); // D <= B
  C c;
  try {                           // se non va a catch
    dynamic_cast<B &>(fun<A>(c)); // C <= A
    cout << "topolino";
  } catch (bad_cast) { // not C <= A && not A <= B
    cout << "pippo ";
  }
  if (!(dynamic_cast<D *>(new B()))) // not B <= D, tautologia
    cout << "pluto ";
  return 0;
}
// D <= B <= A

/*
 * 1) il programma compila correttamente senza procurare errori a runtime
 * 2) il programma stampa "pippo pluto"
 */

/*          condizione 1		  correzione 2
 * A <= B	falso				  falso
 * A <= C	possibile			  falso
 * A <= D	falso				  falso
 * B <= A	vero				  vero
 * B <= C	possibile			  possibile
 * B <= D	falso				  falso
 * C <= A	possibile			  vero
 * C <= B	possibile			  falso
 * C <= D	possibile			  falso
 * D <= A	vero				  vero
 * D <= B	vero				  vero
 * D <= C	possibile			  possibile
 */

// D <= B <= A
// C <= A
// not C <= B
