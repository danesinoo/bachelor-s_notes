#ifndef BOLETTA_H
#define BOLLETTA_H
#include "telefonata.h" // non ho ancora telefonata.h
class bolletta {
    public:
        bolletta();
        bool Vuota() const;
        void Aggiungi_Telefonata(const telefonata&);
        void Togli_Telefonata(const telefonata&);
        telefonata Estrai_Una();
        bolletta& operator=(const bolletta&);
        ~bolletta();
    private:
        class nodo {    // classe annidata (o interna) di una classe (privata)
            public:
                nodo();
                nodo(const telefonata&, nodo*);
                telefonata info;
                nodo* next;
        };
        nodo* first; //puntatore al primo nodo della lista
        static nodo* copia(nodo *);
        static void distruggi(nodo *);
};
#endif

/* Linked List
 * struct {
 * dato nome_dato,
 * ptr next;
 * }
 *
 * L'ultimo nodo puanta a NULL
 */

/* Un membro di una classe può essere una classe
