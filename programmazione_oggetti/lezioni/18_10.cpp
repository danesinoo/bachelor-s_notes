#include "18_10.h"

bolletta::nodo::nodo() : next(0) {}

bolletta::nodo::nodo(const telefonata& t, nodo* s) : info(t), next(s) {}

bolletta::bolletta(): first(0) {}

bool bolletta::Vuota() const {
    return first == 0;
}

void bolletta::Aggiungi_Telefonata(const telefonata& t) {
    first = new nodo(t, first); // aggiunge in testa alla lista
}

void bolletta::Togli_telefonata(const telefonata& t) {
    nodo* p= first, *prec=nullptr;
    while(p && !(p->info == t) {
        prec = p;
        p = p->next;
    } // p==0 (not found) o p punta al nodo da rimuovere
    if (p) {    // ho trovato t
        if (prec==nullptr)  // p punta al primo nodo
            first = p->next;
        else    // p punta ad un nodo successivo al primo
            prec->next = p->next;
        delete p; // attenzione: deallocare!
    }
}

telefonata bolletta::Estrai_Una() {
    // precondizione: bolletta non vuota (!(first==0))
    nodo* p = first;
    first = first->next;
    telefonata aux = p->info;
    delete p;
    return aux;
}

static nodo* bolletta::copia(nodo* p) {
    if (!p) 
        return nullptr;
    return new nodo(p->info, copia(p->next));
}

bolletta::~bolletta() { distruggi(first); } // la distruzione implicita delle
                                            // variabili automatiche non si
                                            // sovrascrive, avviene come prima,
                                            // senza problema

static void bolletta::distruggi(nodo* p) {
    if (p)
        distruggi(p->next);
    delete p;
    // evita la ricorsione dalla fine, prima distrugge e poi invoca
    // tmp = p->next;
    // delete p
    // distruggi(tmp);
}

bolletta& bolletta::operator=(const bolletta& b) {
    if (this != &b) {
        distruggi(first);
        first = copia(b.first);
    }
    return *this;
}

