#include "orario.h"

orario::orario(int h, int m, int s) {
    if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59)
        sec = 0;
    else
        sec = h * 60 * 60 + m * 60 + s;
}

int orario::Ore() const {
    return (sec / (60 * 60));
}

int orario::Minuti() const {
    return (sec / 60) % 60;
}

int orario::Secondi() const {
    return (sec % 60);
}

operator orario::int() {
    return sec;
}

void orario::StampaSecondi() {
    std::cout << sec << std::endl;
}

std::ostream& operator<<(std::ostream& os, const orario& o) {
    return os << ":" << o.Ore() << ":" << o.Minuti() << ":" << o.Secondi() << "\n";
}

orario operator+(const orario& o1, const orario& o2) {
    orario aux;
    aux = (o1.int() + o2.int()) % (24 * 60 * 60);
    return aux;
}

void orario::AvanzaUnOra() {
    sec = (sec + 60 * 60) % (24 * 60 * 60);
}

orario orario::UnOraPiuAvanti() const {
    return (sec + 60 * 60) % (24 * 60 * 60);
}

