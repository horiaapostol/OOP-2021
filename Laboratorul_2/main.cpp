#include "iostream"
#include "Student.h"
#include "functii_globale.h"
#include "cassert"

int main() {
	Student first, second;
	Student third("Horia");

	first.set_nume("Vasile");
	second.set_nume("Dani");

	std::cout << third.get_nume() << " si " << second.get_nume() << " sunt amici.\n";

	first.set_nota_engleza(3.5);
	second.set_nota_engleza(4);
	assert(compara_nota_engleza(&first, &second) == -1);

	first.set_nota_matematica(2);
	assert(compara_nota_matematica(&first, &third) == 1);

	first.set_nota_istorie(4);
	std::cout << first.get_media_generala() << '\n';
	std::cout << second.get_media_generala() << '\n';	// o valoare fara sens..
	std::cout << third.get_media_generala() << '\n';	// avantajul initializarii.

	third.set_nume("Andrei");
	assert(compara_nume(&first, &third) == 1);

	first.set_nume("Dani");
	assert(compara_nume(&first, &second) == 0);
}