/*
 * Veloce ripasso sulla regola dei tre (o regola del pollice)
 */

class Nodo {
    friend class Tree;
    private:
        Nodo(char c='*', Nodo* s=0, Nodo* d=0): info(c), sx(s), dx(d) {};
        char info;
        Nodo* sx;
        Nodo* dx;
};


class Tree {
    private:
        Nodo* root;
        static Nodo* copia(Nodo* r) {
            if (r == 0) return 0;
            // albero puntato da r è non vuoto;
            return new Nodo(r->info, copia(r->sx), copia(r->dx));
        }

        static void distruggi(Nodo* r) {
            if (r == 0) return;
            distruggi(r->sx);
            distruggi(r->dx);
            delete r;
        }
    public:
        Tree(): root(0) {}

        Tree& operator=(const Tree& t) {            // operatore di assegnamento
            if (this!= &t) {
                distruggi(root);
                root = copia(t.root);
            }
            return *this;
        }

        Tree(const Tree& t): root(copia(t.root)) {} // costruttore di copia
        
        ~Tree() {                                   // distruttore
            if(root) distruggi(root);
        }
};
