#ifndef ORARIO_H
#define ORARIO_H
#include <iostream>

class orario {
        private:
            int sec;
        public:
            orario(int =0, int =0, int =0);
            int Ore() const;
            int Minuti() const;
            int Secondi() const;
            operator int();
            void StampaSecondi() const;
            void AvanzaUnOra();
            orario UnOraPiuAvanti() const;
};

std::ostream& operator<<(std::ostream& os, const orario&);
orario operator+(const orario&, const orario&);
#endif
