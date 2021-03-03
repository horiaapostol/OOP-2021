#include "functii_globale.h"
#include "cstring"

int compara_nume(Student* first, Student* second) {
	/*Functie care primeste doi studenti ca parametri si returneaza:
	0 - daca numele studentilor este identic,
	1 - daca numele primului student este mai mare lexicografic,
	-1 - daca numele celui de-al doilea student este mai mare lexicografic.*/
	return strcmp(first->get_nume().c_str(), second->get_nume().c_str());
}

int compara_nota_matematica(Student* first, Student* second) {
	/*Functie care primeste doi studenti ca parametri si returneaza:
	0 - daca notele celor doi studenti la matematica sunt egale,
	1 - daca nota primului student la matematica este mai mare,
	-1 - daca nota celui de-al doilea student la matematica este mai mare.*/
	float first_nota_matematica = first->get_nota_matematica();
	float second_nota_matematica = second->get_nota_matematica();

	if (first_nota_matematica == second_nota_matematica)
		return 0;

	if (first_nota_matematica > second_nota_matematica)
		return 1;

	if (first_nota_matematica < second_nota_matematica)
		return -1;
}

int compara_nota_istorie(Student* first, Student* second) {
	/*Functie care primeste doi studenti ca parametri si returneaza:
	0 - daca notele celor doi studenti la istorie sunt egale,
	1 - daca nota primului student la istorie este mai mare,
	-1 - daca nota celui de-al doilea student la istorie este mai mare.*/
	float first_nota_istorie = first->get_nota_istorie();
	float second_nota_istorie = second->get_nota_istorie();

	if (first_nota_istorie == second_nota_istorie)
		return 0;

	if (first_nota_istorie > second_nota_istorie)
		return 1;

	if (first_nota_istorie < second_nota_istorie)
		return -1;
}

int compara_nota_engleza(Student* first, Student* second) {
	/*Functie care primeste doi studenti ca parametri si returneaza:
	0 - daca notele celor doi studenti la engleza sunt egale,
	1 - daca nota primului student la engleza este mai mare,
	-1 - daca nota celui de-al doilea student la engleza este mai mare.*/
	float first_nota_engleza = first->get_nota_engleza();
	float second_nota_engleza = second->get_nota_engleza();

	if (first_nota_engleza == second_nota_engleza)
		return 0;

	if (first_nota_engleza > second_nota_engleza)
		return 1;

	if (first_nota_engleza < second_nota_engleza)
		return -1;
}

int compara_media_generala(Student* first, Student* second) {
	/*Functie care primeste doi studenti ca parametri si returneaza:
	0 - daca mediile generale ale celor doi studenti sunt egale,
	1 - daca media generala a primului student este mai mare,
	-1 - daca media generala a celui de-al doilea student este mai mare.*/
	float first_media_generala = first->get_media_generala();
	float second_media_generala = second->get_media_generala();

	if (first_media_generala == second_media_generala)
		return 0;

	if (first_media_generala > second_media_generala)
		return 1;

	if (first_media_generala < second_media_generala)
		return -1;
}
