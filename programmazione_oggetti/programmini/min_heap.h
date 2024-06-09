#include "ptr.h"
#include "some.h"
#include <vector>
#define u32 unsigned int

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

template<class T>
class min_heap {
	private:
		class node {
			public:
				u32 distance;
				ptr<T> data;
				node(u32, const T&);
		};
		std::vector<node> storage;

		static node tmp;
		void swap(u32, u32) const;

		int dis(u32) const; // distance
		void heapify(u32) const;
		void rheapify(u32) const;

	public:
		min_heap(u32 =8);
		void push(const T&, u32);
		ptr<T> get_mut_min() const;
		ptr<T> pop();
};

template<class T>
min_heap<T>::node::node(u32 dis, const T& t):
	distance(dis), data(t) {};

namespace heap {
	enum Dir {
		N,
		L,
		R
	};

	u32 parent(u32 i) {
		return i/2;
	}

	u32 right(u32 i) {
		return i*2+1;
	}

	u32 left(u32 i) {
		return i*2;
	}
}

template<class T>
min_heap<T>::min_heap(u32 size): storage(size) {};

template<class T>
int min_heap<T>::dis(u32 i) const {
	if (i<storage.len())
		return storage[i].distance;
	else return -1;
}

template<class T>
void min_heap<T>::swap(u32 a, u32 b) const {
	if (a!=b) {
		tmp = storage[a];
		storage[a] = storage[b];
		storage[b] = tmp;
	}
}

template<class T>
void min_heap<T>::heapify(u32 pos) const {
	if (dis(heap::parent(pos))< dis(pos)) 
		return;
	swap(pos, heap::parent(pos));
	heapify(heap::parent(pos));
}

template<class T>
void min_heap<T>::rheapify(u32 pos) const {
	heap::Dir f=heap::N;
	if (dis(heap::right(pos))>-1 && dis(heap::right(pos)) < dis(pos)) {
		swap(pos, heap::right(pos));
		f = heap::R;
	}
	if (dis(heap::left(pos))>-1 && dis(heap::left(pos)) < dis(pos)) {
		swap(pos, heap::left(pos));
		f = heap::L;
	}
	switch (f) {
		case heap::N:
			break;
		case heap::L:
			return rheapify(heap::left(pos));
		case heap::R:
			return rheapify(heap::right(pos));
	}
}

template<class T>
void min_heap<T>::push(const T& t, u32 pos) {
	storage.push(node(pos, t));
	heapify(storage.len()-1);
}

template<class T>
ptr<T> min_heap<T>::get_mut_min() const {
	if (storage.len())
		return storage[0].data;
	else return ptr<T>(nullptr);
}

template<class T>
ptr<T> min_heap<T>::pop() {
	if (storage.len() > 0) {
		ptr<T> tmp = storage[0].data;
		storage[0] = storage[storage.len()-1];
		if (storage.len() > 1)
			rheapify();
		storage.pop();
		return tmp;
	}
	else return ptr<T>(nullptr);
}
#endif
