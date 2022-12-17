#include <iostream>

// dichiarazione incompleta
template <class T>
class Albero;

template <class T>
std::ostream& operator<<(std::ostream&, const Albero<T>&);

template <class T>
class Albero {
    friend std::ostream& operator<< <T>(std::ostream&, const Albero&);
    private:
        T info;
        class nodo { // template di classe annidato associato
            public:
                T info;
                nodo* left, *mid, *right;
                nodo(const T& t, nodo* l=0, nodo* m=0, nodo* r=0):
                    info(t), left(l), mid(m), right(r) {};
        };
        nodo* root;

        static nodo* copy(nodo* p) {
            if (p==nullptr) return nullptr;
            //  p punta ad Albero non vuoto
            return new nodo(p->info, copy(p->left), copy(p->mid), copy(p->right));
        }
        static void destroy(nodo* p) {
            if (p!=nullptr) {
                destroy(p->left), destroy(p->mid), destroy(p->right);
                delete p;
            }
        }
        static bool rec_search(const T& t, nodo* p) {
            if (!p) return false;
            return t==p->info || rec_search(t, p->left) || 
                rec_search(t, p->mid) || rec_search(t, p->right);
        }

        static bool rec_eq(const nodo* p1, const nodo* p2) {
            if (!p1 && !p2) return true;
            // p1 | p2
            else if (!p1 || !p2) return false;
            // p1 && p2
            return p1->info == p2->info && rec_eq(p1->left, p2->left) &&
                rec_eq(p1->mid, p2->mid) && rec_eq(p1->right, p2->right);
        }

        static void rec_print(std::ostream& os, nodo* p) {
            if (!p) {
                os << p->info << " ";
            rec_print(os, p->left);
            rec_print(os, p->mid);
            rec_print(os, p->right);
            }
        }

    public:
        Albero(): root(nullptr) {}
        Albero(const Albero& a): root(copy(a.root)) {}
        Albero& operator=(const Albero& a) {
            if (this != &a) {
                destroy(root);
                root = copy(a.root);
            }
            return *this;
        }
        ~Albero() {
            if (root!=nullptr)
                destroy(root);
        }

        void insert(const T& t) {
            root = new nodo(t, copy(root), copy(root), root);
        }
        bool search(const T& t) const {
            return rec_search(t, root);
        }

        bool operator== (const Albero<T>& t) const {
            return rec_eq(root, t.root);
        }
};
        
template <class T>
std::ostream& operator<< (std::ostream& os, const Albero<T>& a) {
    Albero<T>::rec_print(os, a.root);
    return os;
}

int main() {
	Albero<int> hello;
	hello.insert(9);
	hello.insert(10);
	std::cout << hello;
}
