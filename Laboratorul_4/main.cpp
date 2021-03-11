#include "Sort.h"
#include "iostream"
#include "cassert"

int main() {
	Sort lista_1(6, 1, 10);
	Sort lista_2{ 3, 7, 9, 3, 11 };
	Sort lista_3({ 8, 1, 2, 3, 4, 5, 10 }, 7);
	Sort lista_4(6, 0, 9, 1, 2, 3, 7);
	char s[100] = "2,3,1,5,9";
	Sort lista_5(s);

	std::cout << "Lista de elemente random: ";
	lista_1.Print();
	std::cout << "Lista cu initializare: ";
	lista_2.Print();
	std::cout << "Lista care copiaza elementele dintr-un vector ";
	lista_3.Print();
	std::cout << "Lista cu va_args: ";
	lista_4.Print();
	std::cout << "Lista de elemente din string: ";
	lista_5.Print();

	assert(lista_2.GetElementFromIndex(0) == 3);
	assert(lista_3.GetElementFromIndex(6) == 10);
	assert(lista_4.GetElementFromIndex(2) == 1);
	assert(lista_5.GetElementFromIndex(3) == 5);

	assert(lista_1.GetElementsCount() == 6);
	assert(lista_2.GetElementsCount() == 5);
	assert(lista_3.GetElementsCount() == 7);
	assert(lista_4.GetElementsCount() == 6);
	assert(lista_5.GetElementsCount() == 5);

	lista_1.BubbleSort(1);
	lista_2.InsertSort(1);
	lista_3.QuickSort(0, lista_3.GetElementsCount()-1, 1);
	lista_4.BubbleSort(1);
	lista_5.QuickSort(0, lista_5.GetElementsCount()-1, 1);

	std::cout << "\nListele sortate ascendent:\n";

	std::cout << "Lista de elemente random: ";
	lista_1.Print();
	std::cout << "Lista cu initializare: ";
	lista_2.Print();
	std::cout << "Lista care copiaza elementele dintr-un vector ";
	lista_3.Print();
	std::cout << "Lista cu va_args: ";
	lista_4.Print();
	std::cout << "Lista de elemente din string: ";
	lista_5.Print();


	lista_1.BubbleSort(0);
	lista_2.InsertSort(0);
	lista_3.QuickSort(0, lista_3.GetElementsCount() - 1, 0);
	lista_4.BubbleSort(0);
	lista_5.QuickSort(0, lista_5.GetElementsCount() - 1, 0);

	std::cout << "\nListele sortate descendent:\n";

	std::cout << "Lista de elemente random: ";
	lista_1.Print();
	std::cout << "Lista cu initializare: ";
	lista_2.Print();
	std::cout << "Lista care copiaza elementele dintr-un vector ";
	lista_3.Print();
	std::cout << "Lista cu va_args: ";
	lista_4.Print();
	std::cout << "Lista de elemente din string: ";
	lista_5.Print();
}