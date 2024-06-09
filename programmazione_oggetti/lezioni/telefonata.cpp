#include "telefonata.h"

telefonata::telefonata(const orario& i, const orario& f, const int n)
    : inizio(i), fine(f), num(n) {};

orario telefonata::Inizio() const { return inizio; }

orario telefonata::Fine() const { return fine; }

orario telefonata::Numero const { return num; }

bool telefonata::operator==(const telefonata& t) const {
    return inizio == t.inizio && fine == t.fine && num == t.num;
}

ostream& operator<<(ostream& s, const telefonata& t) {
    return s << "INIZIO " << t.Inizio() << " FINE : << t.Fine()
        << " NUMERO CHIAMATO " << t.Numero();
}


