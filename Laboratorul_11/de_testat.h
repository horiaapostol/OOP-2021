//
// Created by horia on 14/05/2021.
//

#ifndef UNTITLED_DE_TESTAT_H
#define UNTITLED_DE_TESTAT_H

#endif //UNTITLED_DE_TESTAT_H

#include <iostream>
#include <cstdarg>

using namespace std;
template <class T>
class Sort
{
    T* v;
    T n;
public:
    Sort(int numar_elemente, ...) {
        n = numar_elemente;
        this->v = new T[n];
        va_list args;
                va_start(args, numar_elemente);
        for (int i = 0; i < this->n; ++i)
            this->v[i] = va_arg(args, T);
                va_end(args);
    }

    void InsertSort()
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
