#include <iostream>

#ifndef PTR_SAFE
#define PTR_SAFE

template<class T>
class ptr{
	private:
		T* data;

	public:
        ptr(const T&);
        ptr(const ptr&);
        ptr(const T* const);
        T unwrap();
        ~ptr();
        ptr& operator=(const ptr&);
        bool isPtr() const;
        bool isNone() const;
		const T& get() const;
		T& get_mut();
		void free() {
			delete data;
			data = nullptr;
		}
};

template<class T>
ptr<T>::ptr(const T* const t): data(t? new T: nullptr) {
    if (t) *data = *t;
}

template<class T>
ptr<T>::ptr(const T& t): data(new T) {
    *data = t;
}

template<class T>
ptr<T>::ptr(const ptr& s): data(new T) {
    *data = *(s.data);
}

template<class T>
ptr<T>::~ptr() {
    if (data) {
        delete data;
        data = nullptr;
    }
}

template<class T>
ptr<T>& ptr<T>::operator=(const ptr& s) {
    if (this != &s && s.data) {
        if (!this) *this = new T;
        *(this->data) = *(s.data);
    }
    return *this;
}

template<class T>
bool ptr<T>::isPtr() const {
    return data;
}

template<class T>
bool ptr<T>::isNone() const {
    return !data;
}

template<class T>
const T& ptr<T>::get() const {
	return *data;
}

template<class T>
T& ptr<T>::get_mut() {
	return *data;
}
#endif

