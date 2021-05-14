#pragma once
#include <iostream>
#include <cstdarg>

using namespace std;
template <class T>
class Sort
{
	T* v;
	T n;
public:
	Sort::Sort(int numar_elemente, ...) {
		n = numar_elemente;
		this->v = new [this->n];
		va_list args;
		va_start(args, numar_elemente);
		for (int i = 0; i < this->n; ++i)
			this->v[i] = va_arg(args, int);
		va_end(args);
	}
	
	void sortInt.InsertSort()
	{
		int i, key, j;
		for (i = 1; i < this->n; i++)
		{
			key = this->v[i];
			j = i - 1;
			while (j >= 0 && this->v[j] > key)
			{
				this->v[j + 1] = this->v[j];
				j = j - 1;
			}
			this->v[j + 1] = key;
			
		}
	}
	void print() {
		for (int i = 0; i < n; i++) {
			cout << this->v[i] << " ";
		}
	}
};

