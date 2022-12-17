#include <iostream>

class Vettore {
    private:
        int* a;
        unsigned int size;

    public:
        // blocchiamo la conversione implicita di un unsigned int a vettore
		// hello aksdhjf;lasdjkfalfkja;sdlfkasjdf;
        explicit Vettore(unsigned int dim=0, int dafault =0): 
            size(dim), a(dim>0 ? new int[dim]: nullptr) {
            if (dim == 0) a = 0;
            else 
                for (int i=0; i<size; i++) 
                    a[i] = dafault;
        }

        Vettore operator+(const Vettore& V) const {
            Vettore tmp(size + V.size);
            for (unsigned int i=0; i<size; i++)
                tmp.a[i] = a[i];
            for (unsigned int i=0; i<V.size; i++)
                tmp.a[size+i] = V.a[i];
            return tmp;
        }

        Vettore& append(const Vettore& v) {
            *this = *this + v;
            return *this;
        }

        bool operator==(const Vettore& v) {
            if (size != v.size) return false;
            for (unsigned int i=0; i<size; i++)
                if (a[i] != v.a[i])
                    return false;
            return true;
        }

        Vettore(const Vettore& v) {
            *this = v;
        }

        Vettore& operator=(const Vettore& v) {
            if (this != &v) {
                if (a != nullptr) delete[] a;
                a = new int[v.size];
                size = v.size;
                for (unsigned int i= 0; i<size; i++)
                    a[i] = v.a[i];
            }
            return *this;
        }

        ~Vettore() {
            delete[] a;
        }
};
