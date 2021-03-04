#include "iostream"
#include "Math.h"
#include "cassert"

int main() {
	Math obiect;
	assert(obiect.Add(3, 4) == 7);
	assert(obiect.Add(3, 4, 5) == 12);
	assert(obiect.Add(3.2, 4.8) == 8);
	assert(obiect.Add(1.5, 2.5, 3.5) == 7);

	assert(obiect.Mul(3, 2) == 6);
	assert(obiect.Mul(3, 4, 2) == 24);
	assert(obiect.Mul(2.5, 2.5) == 6);
	assert(obiect.Mul(2.5, 2.5, 2.5) == 15);

	std::cout << obiect.Add("Foo", "Bar") << '\n';
	std::cout << obiect.Add(5, 1, 2, 3, 4, 5);
}