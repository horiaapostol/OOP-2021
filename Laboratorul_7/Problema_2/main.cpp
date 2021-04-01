#include "Vector.h"
#include "iostream"
#define set(x, y) set(x, y, get_name(y))

class Compare {
public:
	template<typename T>
	bool operator()(const T& a, const T& b) {
		return a > b;
	}
};


int main() {
	Vector<int> my_vector;

	my_vector.push(10);
	my_vector.push(20);
	my_vector.push(30);
	my_vector.push(30);
	my_vector.push(15);
	my_vector.push(30);
	my_vector.push(40);
	my_vector.push(50);

	std::cout << "Vectorul initial: ";
	for (unsigned int i = 0; i < my_vector.count(); ++i) {
		std::cout << my_vector.get(i) << ' ';
	}
	std::cout << '\n';
	std::cout << "Lungimea vectorului initial: " << my_vector.count() << '\n';
	std::cout << "Ultimul element al vectorului initial: " << my_vector.pop() << '\n';

	my_vector.insert(25, 2);
	my_vector.insert(40, 3);
	my_vector.insert(50, 4);

	std::cout << "Vectorul dupa prima modificare: ";
	for (unsigned int i = 0; i < my_vector.count(); ++i) {
		std::cout << my_vector.get(i) << ' ';
	}
	std::cout << '\n';

	my_vector.remove(2);
	my_vector.remove(3);
	my_vector.set(90, 0);
	my_vector.set(70, 8);

	std::cout << "Vectorul dupa a doua modificare: ";
	for (unsigned int i = 0; i < my_vector.count(); ++i) {
		std::cout << my_vector.get(i) << ' ';
	}
	std::cout << '\n';

	my_vector.sort();
	std::cout << "Vectorul sortat crescator: ";
	for (unsigned int i = 0; i < my_vector.count(); ++i) {
		std::cout << my_vector.get(i) << ' ';
	}
	std::cout << '\n';

	my_vector.sort([](int a, int b) { return a < b; });
	std::cout << "Vectorul sortat descrescator: ";
	for (unsigned int i = 0; i < my_vector.count(); ++i) {
		std::cout << my_vector.get(i) << ' ';
	}
	std::cout << '\n';

	std::cout << "Prima aparitie a lui 30 este la indexul: " << my_vector.firstIndexOf(30) << '\n';
	std::cout << "Primul numar mai mic decat 30 este la indexul: " << my_vector.firstIndexOf(30, [](int a, int b) { return a < b; }) << '\n';
	std::cout << "Primul numar mai mare decat 30 este la indexul: " << my_vector.firstIndexOf(30, Compare()) << '\n';

	std::cout << "Exceptii:\n";

	Vector<char> test;

	test.pop();

	test.push('a');
	test.push('b');
	test.push('c');
	test.push('d');

	test.get(-1);
	test.get(20);
	test.remove(20);
	test.insert(10, 30);

	int my_test_index = 10;
	test.set('e', my_test_index);

	test.push('e');
	int another_bad_index = -7;
	test.set('f', another_bad_index);
}