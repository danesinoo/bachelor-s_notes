#include <iostream>

// dichiarazione incompleta (alias forward declaration)
template<class T>
class Queue;

// dichiarazione del template di funzione operator<< <T>
template<class T>
// richiede la dichiarazione della classe Queue (vd riga 5)
std::ostream& operator<<(std::ostream& os, const Queue<T>&);

// dichiarazione incompleta non permessa
// template<class T> class Queue<T>::QueueItem;

// dichiarazione non necessaria
// template<class T> ostream& operator<< (ostream& os, const typename Queue<T>::QueueItem&) ;

template<class T> class Queue {
        // NON agisce da dichiarazione di template di funzione
        // per cui ha bisogno di un template di funzione (vd riga 9) 
        friend std::ostream& operator<< <T> (std::ostream& os, const Queue<T>&);
    private:
        class QueueItem {
            public:
                friend class Queue<T>;
                friend std::ostream& operator<< <T> (std::ostream& os, const Queue<T>&);
                // agisce da dichiarazione di template di funzione, ed è
                // permesso perchè la classe è annidata
                friend std::ostream& operator<< <T> (std::ostream& os, const typename Queue<T>::QueueItem&);
            private:
                T info;
                QueueItem* next;
        };
        QueueItem *primo, *ultimo;
    public:
        // ...
};
// definizione del template di funzione operator<< <T>
template<class T>
std::ostream& operator<< (std::ostream& os, const Queue<T>& q) {
    // ...
    return os;
}
// definizione del template di funzione operator<< <T>
template<class T>
std:: ostream& operator<< (std::ostream& os, const typename Queue<T>::QueueItem& qi) {
    // ...
    return os;
}

// la programmazione mediante funzioni generiche è più complessa, soprattutto
// per il c++
