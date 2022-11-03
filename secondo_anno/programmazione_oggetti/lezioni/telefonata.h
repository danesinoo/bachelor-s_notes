#ifndef TELEFONATA_H
#define TELEFONATA_H
#include "orario.h"
class telefonata {
    private:
        orario inizio, fine;
        const int num;
    public:
        telefonata(const orario&, const orario&, const int);
        orario Inizio() const;
        orario File() const;
        int Numero() const;
        bool operator==(const telefonata&) const;
};

ostream& operator<<(ostream&, const telefonata&);
#endif

