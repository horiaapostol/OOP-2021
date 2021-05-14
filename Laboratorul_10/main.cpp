#pragma once
#include "memory"
#include "functional"
#include "iostream"
#define get_name(my_variable) (#my_variable)


template <typename T>
bool sort_compare_default(T a, T b) {
	return a > b;
}


template <typename T>
bool find_compare_default(T a, T b) {
	return a == b;
}


template<class T, class Allocator = std::allocator<T>>
class Array {
private:
	Allocator allocator;
	T* elemente;
	unsigned int dimensiune;
	unsigned int capacitate;
public:
	Array() : dimensiune{ 0 }, capacitate{ 0 }, elemente{ nullptr } {};


	~Array() {
		this->allocator.deallocate(this->elemente, this->capacitate);
	}


	void push(const T& element) {
		if (this->dimensiune == 0) {
			this->elemente = this->allocator.allocate(1);
			this->allocator.construct(this->elemente, element);
			this->dimensiune++;
		}
		else {
			if (this->dimensiune == this->capacitate) {
				this->capacitate = this->capacitate * 2;
				std::unique_ptr<T[]> temp_pointer(this->elemente);
				this->elemente = this->allocator.allocate(this->capacitate);
				for (unsigned int i = 0; i < this->dimensiune; ++i) {
					this->elemente[i] = temp_pointer[i];
				}
			}
			this->elemente[this->dimensiune++] = element;
		}
	}


	T pop() {
		try {
			if (this->dimensiune <= 0) {
				throw this->dimensiune;
			}
			else {
				return this->elemente[this->dimensiune - 1];
			}
		}
		catch (...) {
			std::cout << "Vector has no elements!\n";
		}
		return *new T();
	}


	void remove(unsigned int index) {
		try {
			if (index < 0 or index > this->dimensiune) {
				throw this->dimensiune;
			}
			else {
				std::unique_ptr<T[]> temp_pointer(this->elemente);
				this->elemente = this->allocator.allocate(this->dimensiune - 1);
				unsigned int counter = 0;
				for (unsigned int i = 0; i < this->dimensiune; ++i) {
					if (i != index)
						this->elemente[counter++] = temp_pointer[i];
				}
				this->dimensiune--;
			}
		}
		catch (...) {
			std::cout << "Out of Range!\n";
			std::cout << "Cannot remove element from index!\n";
		}
	}


	void insert(const T& element_de_inserat, unsigned int index) {
		try {
			if (index < 0 or index > this->dimensiune) {
				throw this->dimensiune;
			}
			else {
				std::unique_ptr<T[]> temp_pointer(this->elemente);
				if (this->dimensiune == this->capacitate) {
					this->capacitate = this->capacitate * 2;
					this->elemente = this->allocator.allocate(this->capacitate);
				}
				else {
					this->elemente = this->allocator.allocate(this->dimensiune + 1);
				}
				unsigned int counter = 0;
				unsigned int i = 0;
				for (; i < index; ++i) {
					this->elemente[counter++] = temp_pointer[i];
				}
				this->elemente[counter++] = element_de_inserat;
				for (; i < this->dimensiune; ++i) {
					this->elemente[counter++] = temp_pointer[i];
				}
				this->dimensiune++;
			}
		}
		catch (...) {
			std::cout << "Out of range!\n";
			std::cout << "Cannot insert to index!\n";
		}
	}


	const T& get(unsigned int index) {
		try {
			if (index < 0 or index >= this->dimensiune) {
				throw this->dimensiune;
			}
			else {
				return this->elemente[index];
			}
		}
		catch (...) {
			std::cout << "Out of Range!\n";
			std::cout << "Cannot access element from index!\n";
		}
		return *new T();
	}


	unsigned int count() {
		return this->dimensiune;
	}


	void sort(std::function<bool(T, T)> my_compare = sort_compare_default<T>) {
		bool sortat = false;
		while (!sortat) {
			sortat = true;
			for (unsigned int i = 0; i < this->dimensiune - 1; ++i) {
				if (my_compare(this->elemente[i], this->elemente[i + 1])) {
					sortat = false;
					T temp = this->elemente[i];
					this->elemente[i] = elemente[i + 1];
					elemente[i + 1] = temp;
				}
			}
		}
	}


	void set(const T& element_de_adaugat, unsigned int index, const char* index_name = 0) {
		try {
			if (index < 0 or index >= this->dimensiune) {
				throw this->dimensiune;
			}
			else {
				this->elemente[index] = element_de_adaugat;
			}
		}
		catch (...) {
			std::cout << "Out of Range!\n";
			std::cout << "Hint: " << index_name << " should be a positive integer less than " << this->dimensiune << '\n';
		}
	}


	int firstIndexOf(const T& element_cautat, std::function<bool(T, T)> my_compare = find_compare_default<T>) {
		for (unsigned int i = 0; i < this->dimensiune; ++i) {
			if (my_compare(this->elemente[i], element_cautat))
				return (unsigned int)i;
		}
		return -1;
	}
};

int main() {

}