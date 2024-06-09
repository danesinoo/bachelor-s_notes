#include <iostream>

#ifndef RESULT
#define RESULT

template<class T, class E>
class Result;

template<class T, class E>
std::ostream& operator<<(std::ostream&, const Result<T, E>&);

template<class T, class E>
class Result {
	private:
		bool flag;
		void* ptr;
		Result(const T&);
		Result(const E&);
    public:
		static Result Ok(const T&);
		static Result Err(const E&);
        T unwrap();
		E unwrap_err();
        Result(const Result&);
		Result& operator=(const Result&);
        ~Result();
        bool isOk() const;
        bool isErr() const;
		friend std::ostream& operator<< <T, E>(std::ostream&, const Result<T, E>&);
};

template<class T, class E>
Result<T, E>::Result(const T& t): flag(true), ptr(new T) {
	*static_cast<T*>(ptr) = t;
}

template<class T, class E>
Result<T, E>::Result(const E& e): flag(false), ptr(new E) {
	*static_cast<E*>(ptr) = e;
}

template<class T, class E>
Result<T, E> Result<T, E>::Ok(const T& t) {
	return Result(t);
}

template<class T, class E>
Result<T, E> Result<T, E>::Err(const E& e) {
	return Result(e);
}

template<class T, class E>
T Result<T, E>::unwrap() {
	if (flag && ptr) {
		T tmp(*static_cast<T*>(ptr));
		delete static_cast<T*>(ptr), ptr = nullptr;
		return tmp;
	}
	else if (!flag)
		std::cerr << "Try to unwrap an Err(e) e: " << *static_cast<E*>(ptr) << '\n';
	else 
		std::cerr << "Try to unwrap a moved value\n";
	exit(EXIT_FAILURE);
}

template<class T, class E>
E Result<T, E>::unwrap_err() {
	if (!flag && ptr) {
		E tmp(*static_cast<E*>(ptr));
		delete static_cast<E*>(ptr), ptr = nullptr;
		return tmp;
	}
	else if (flag)
		std::cerr << "Try to unwrap_err an Ok(o), o: " << *static_cast<T*>(ptr) << '\n';
	else 
		std::cerr << "Try to unwrap a moved value\n";
	exit(EXIT_FAILURE);
}

template<class T, class E>
Result<T, E>::Result(const Result& r): flag(r.flag), ptr(nullptr) {}

template<class T, class E>
Result<T, E>& Result<T, E>::operator=(const Result& r) {
	return Result(r);
}

template<class T, class E>
Result<T, E>::~Result() {
	if (ptr) {
		if (flag) delete static_cast<T*>(ptr);
		else delete static_cast<E*>(ptr);
	}
}

template<class T, class E>
bool Result<T, E>::isOk() const {
	return flag && ptr;
}

template<class T, class E>
bool Result<T, E>::isErr() const {
	return !flag && ptr;
}

template<class T, class E>
std::ostream& operator<<(std::ostream& os, const Result<T, E>& r) {
	if (r.isOk())
		os << *static_cast<T*>(r.ptr); 
	else if (r.isErr())
		os << *static_cast<E*>(r.ptr); 
	else {
		std::cerr << "Value moved";
		exit(EXIT_FAILURE);
	}
	return os;
}
#endif
