#pragma once
#include "initializer_list"
#include "vector"
#include "cstdarg"
#include "cstring"

class Sort {
private:
    int *elem;
    int size;
public:
    Sort(int numar_elemente, int min, int max);
    Sort(std::initializer_list<int>);
    Sort(std::vector<int>, unsigned int size);
    Sort(int numar_elemente, ...);
    Sort(char *my_string);
    void InsertSort(bool ascendent = false);
    void QuickSort(int stanga, int dreapta, bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};

