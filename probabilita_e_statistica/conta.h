#include <iostream>

#ifndef CONTA
#define CONTA
template <class T>
class iter {
    private:
        T* campione;
        int size;
        bool flag;
        iter(unsigned int, bool);
    public:
        iter(unsigned int, T*);
        iter(const iter&);
        iter& operator=(const iter&);
        ~iter();
        iter<T> mapRef(void (const T&)) const;
        iter<T> map(T (const T&)) const;
        iter<T> map(T (const T&, const T&), const T&);
        iter<T>& mapMut(T (T&));
        iter<T> filter(bool (const T&)) const;
        T count() const;
};

template <class T>
iter<T>::iter(unsigned int s, bool f):
    campione(s>0 && f ? new T[s]:nullptr), size(s), flag(f) {}

template <class T>
iter<T>::iter(unsigned int s, T* ptr):
    campione(ptr), size(s), flag(false) {}

template <class T>
iter<T>::iter(const iter& it):
    campione(it.campione), size(it.size), flag(false) {
};

template <class T>
iter<T>& iter<T>::operator=(const iter& it) {
    if (this != &it) {
        if (flag == true) delete[] campione;
        campione = it.campione;
        size = it.size;
        flag = false;   // per questo falg non può essere costante (ma non può
                        // essere cambiata)
    }
    return *this;
}

template <class T>
iter<T>::~iter() {
    if (flag) {
        delete[] campione;
    }
}

template <class T>
iter<T> iter<T>::mapRef(void (*fn)(const T&)) const {
    for (unsigned int i=0; i<size; i++) 
        fn(campione[i]);
    return *this;
}

template <class T>
iter<T> iter<T>::map(T (*fn)(const T&)) const {
    iter tmp(size, true);
    for (int i=0; i<size; i++)
        tmp.campione[i] = (*fn)(campione[i]);
    return tmp;
}

template <class T>
iter<T> iter<T>::map(T (*fn)(const T&, const T&), const T& rhs) {
    iter tmp(size, true);
    for (unsigned int i=0; i<size; i++)
        tmp.campione[i] = (*fn)(campione[i], rhs);
    return tmp;
}

template <class T>
iter<T>& iter<T>::mapMut(T (*fn)(T&)) { // potrei mettere una (*fn)(const
                                           // T), ma tanto il T deve
                                           // essere modificabile e in questo
                                           // modo ci sono più funzioni che
                                           // posso passare
    for (unsigned int i=0; i<size; i++)
        campione[i] = (*fn)(campione[i]);
    return *this;
}

template <class T>
iter<T> iter<T>::filter(bool (*fn)(const T&)) const {
    iter tmp(size, false);
    unsigned int tmp_size = 0;
    for (unsigned int i=0; i<size; i++)
        if ((*fn)(campione[i]))
            tmp.campione[tmp_size++] = campione[i];
    iter aux(tmp_size, false);
    for (unsigned int i=0; i<size; i++)
        aux.campione[i] = tmp.campione[i];
    return aux;
}

template <class T>
T iter<T>::count() const {
    T tmp = 0;
    for (unsigned int i=0; i<size; i++) {
        tmp += campione[i];
    }
    return tmp;
}
#endif

/*
 * Devo approfondire il linguaggio funzionale per andare avanti
 *
 * Non ho idea se sto facendo scelte sensate o meno
 */
