#pragma once
#include "iostream"
#include "functional"
#include "initializer_list"

template <typename T>
bool compare(T a, T b) {
	return a > b;
}
template<class T>
class Sort {
	using value_type = T;
	using functor = std::function<bool(T, T)>;
	value_type* elem;
	uint64_t size;
	void quick_sort(uint64_t stanga, uint64_t dreapta, functor my_compare = compare<T>) {
		if (stanga < dreapta) {
			uint64_t mijloc = (stanga + dreapta) / 2;
			this->elem[stanga] ^= this->elem[mijloc];
			this->elem[mijloc] ^= this->elem[stanga];
			this->elem[stanga] ^= this->elem[mijloc];
			uint64_t i = stanga, j = dreapta, count = 0;
			while (i < j) {
				if (this->elem[i] > this->elem[j]) {
					this->elem[i] ^= this->elem[j];
					this->elem[j] ^= this->elem[i];
					this->elem[i] ^= this->elem[j];
					count = 1 - count;
				}
				i += count;
				j -= 1 - count;
			}
			quick_sort(stanga, i - 1, my_compare);
			quick_sort(i + 1, dreapta, my_compare);
		}
	};
public:
	Sort(std::initializer_list<value_type> args) {
		this->size = args.size();
		this->elem = new T[this->size];
		for (uint64_t i = 0; i != this->size; ++i)
			elem[i] = args.begin()[i];
	};
	void run(functor my_compare = compare<T>) {
		this->quick_sort(0, this->size + 1, my_compare);
	}
	void print() {
		for (uint64_t i = 0; i < this->size; ++i)
			std::cout << this->elem[i] << ' ';
		std::cout << '\n';
	};
};