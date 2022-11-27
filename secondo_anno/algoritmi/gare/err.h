#include <iostream>
#include "some.h"

#ifndef RESULT
#define RESULT

template <class T, class E>
class Result {
    private:
        Some<T> ok;
        Some<E> err;
        Result(bool, const T* const, const E* const);

    public:
        static Result Ok(const T& t) {  // crea un oggetto con flag == true
            return Result(true, &t, nullptr);
        }

        static Result Err(const E& e) { // crea un oggetto con flag == false
            return Result(false, nullptr, &e);
        }

        T unwrap();
        E unwrap_err();
        bool isOk() const;
        bool isErr() const;
};

template<class T, class E>
Result<T, E>::Result(bool f, const T* const t, const E* const e):
    ok(f ? t : nullptr), err(f ? nullptr : e) {}

template<class T, class E>
T Result<T, E>::unwrap() {
    if (this->isOk()) {
        return ok.unwrap();
    }
    else if (this->isErr()) {
        std::cerr << "unwrapping an Err<E>: " << err.unwrap() << std::endl;
    }
    else std::cerr << "moved value" << std::endl;
    exit(EXIT_FAILURE);
}


template<class T, class E>
E Result<T, E>::unwrap_err() {
    if (this->isErr()) {
        return err.unwrap();
    }
    else if (this->isOk()) {
        std::cerr << "unwrapping_err an Ok<T>: " << ok.unwrap() << std::endl;
    }
    else
        std::cerr << "moved value" << std::endl;
    exit(EXIT_FAILURE);
}

template<class T, class E>
bool Result<T, E>::isOk() const {
    return ok.isSome();
}

template<class T, class E>
bool Result<T, E>::isErr() const {
    return err.isSome();
}

#endif
