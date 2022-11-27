#include <iostream>

template<class T>
class Btree;

template<class T>
class Btree<T>::nodo;

template<class T>
class Btree {
	private:
		class nodo {
			public:
				T info;
				nodo* l, r;
				nodo(const T& d, const nodo* const left, const nodo* const right);
				nodo(const nodo&);
				~nodo();
				nodo& operator=(const nodo*);
		};
		nodo* n;

	public:
		Btree(const T& t);
		Btree(const Btree& t);
		~Btree();
		Btree& operator=(const Btree&);
		T& key() const;
		nodo* left() const;
		nodo& right() const;
		bool isABR(int, int) const;
};

template<class T>
Btree<T>::nodo::nodo(const T& d, const nodo* const left, const nodo* const right): 
	info(d), l(left), r(right) {}

template<class T>
Btree<T>::nodo::nodo(const nodo& n) {
	*this = copy(n);
}

template<class T>
Btree<T>::nodo::~nodo() {
	destroy(*this);
}

template<class T>
nodo& Btree<T>::nodo::operator=(const nodo* n) {
	if (this != &n) {
		destroy(this);
		*this = copy(n);
	}
	return *this;
}



template<class T>
bool Btree<T>::isABR(int min, int max) const {
	if (!*this) return true;
	else if (this->key() >= min &&  this->key()<= max) {
		return isABR(this->left(), min, this->key()) && isABR(this->right(), this->key(), max);
	}
	else return false;
}
