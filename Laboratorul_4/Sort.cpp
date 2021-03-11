#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Sort.h"
#include "cstdlib"
#include "ctime"
#include "iostream"

Sort::Sort(int numar_elemente, int min, int max) {
	this->size = numar_elemente;
	this->elem = new int[this->size];
	srand(time(NULL));
	for (int i = 0; i < this->size; ++i)
		this->elem[i] = min + std::rand() % (max - min + 1);
}
Sort::Sort(std::initializer_list<int> args) {
	this->size = args.size();
	this->elem = new int[this->size];
	for (int i = 0; i != this->size; ++i)
		elem[i] = args.begin()[i];
}
Sort::Sort(std::vector<int> vector, unsigned int size) {
	this->size = size;
	this->elem = new int[this->size];
	for (int i = 0; i < this->size; ++i)
		elem[i] = vector.at(i);
}
Sort::Sort(int numar_elemente, ...) {
	this->size = numar_elemente;
	this->elem = new int[this->size];
	va_list args;
	va_start(args, numar_elemente);
	for (int i = 0; i < this->size; ++i)
		elem[i] = va_arg(args, int);
	va_end(args);
}
Sort::Sort(char *my_string) {
	std::vector<int> temp;
	char *p = strtok(my_string, ",");
	while (p != NULL) {
		int numar = 0;
		for (unsigned int i = 0; i< strlen(p); ++i)
			numar = numar * 10 + (p[i] - '0');
		temp.push_back(numar);
		p = strtok(NULL, ",");
	}
	this->size = temp.size();
	this->elem = new int[this->size];
	for (int i = 0; i < this->size; ++i)
		elem[i] = temp.at(i);
}
void Sort::InsertSort(bool ascendent) {
	for (int i = 0; i < this->size; ++i) {
		int element = this->elem[i];
		int j = i - 1;
		for (; j >= 0 && ((ascendent && this->elem[j] > element) || (!ascendent && this->elem[j] < element)); --j)
			this->elem[j + 1] = this->elem[j];
		this->elem[j + 1] = element;
	}
}
void Sort::QuickSort(int stanga, int dreapta, bool ascendent) {
	if (stanga < dreapta) {
		int mijloc = (stanga + dreapta) / 2;
		int temp = this->elem[stanga];
		this->elem[stanga] = this->elem[mijloc];
		this->elem[mijloc] = temp;
		int i = stanga, j = dreapta, count = 0;
		while (i < j) {
			if ((ascendent && this->elem[i] > this->elem[j]) || (!ascendent && this->elem[i] < this->elem[j])) {
				int temp = this->elem[i];
				this->elem[i] = this->elem[j];
				this->elem[j] = temp;
				count = 1 - count;
			}
			i += count;
			j -= 1 - count;
		}
		QuickSort(stanga, i - 1, ascendent);
		QuickSort(i + 1, dreapta, ascendent);
	}
}
void Sort::BubbleSort(bool ascendent) {
	bool sortat = false;
	while (!sortat) {
		sortat = true;
		for (int i = 0; i < this->size - 1; ++i)
			if ((ascendent && this->elem[i] > this->elem[i + 1]) || (!ascendent && this->elem[i] < this->elem[i + 1])) {
				this->elem[i] ^= this->elem[i + 1];
				this->elem[i + 1] ^= this->elem[i];
				this->elem[i] ^= this->elem[i + 1];
				sortat = false;
			}
	}
}
void Sort::Print() {
	for (int i = 0; i < this->size; ++i)
		std::cout << this->elem[i] << ' ';
	std::cout << '\n';
}
int Sort::GetElementsCount() {
	if (this->elem != NULL)
		return this->size;
	return 0;
}
int Sort::GetElementFromIndex(int index) {
	if (this->elem != NULL) 
		return this->elem[index];
	return 0;
}