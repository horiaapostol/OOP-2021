#include "Student.h"

Student::Student() {
	/*Un constructor. Creeaza un student fara init.*/
}
Student::Student(std::string nume) {
	/*Un constructor. Creeaza un student.
	input: un nume;
	output: un student ale carui note sunt 1 din oficiu;
	invariant: numele studentului.*/
	this->nume = nume;
	this->nota_istorie = 1;
	this->nota_engleza = 1;
	this->nota_matematica = 1;
}
void Student::set_nume(std::string nume) {
	/*Metoda setter care modifica nuumele unui student*/
	this->nume = nume;
}

void Student::set_nota_matematica(float nota_matematica) {
	/*Metoda setter care modifica nota unui student
	la matematica*/
	this->nota_matematica = nota_matematica;
}

void Student::set_nota_engleza(float nota_engleza) {
	/*Metoda setter care modifica nota unui student
	la engleza*/
	this->nota_engleza = nota_engleza;
}

void Student::set_nota_istorie(float nota_istorie) {
	/*Metoda setter care modifica nota unui student
	la istorie*/
	this->nota_istorie = nota_istorie;
}

std::string Student::get_nume() {
	/*Metoda getter care returneaza numele unui student*/
	return this->nume;
}

float Student::get_nota_matematica() {
	/*Metoda getter care returneaza nota unui student
	la matematica*/
	return this->nota_matematica;
}

float Student::get_nota_engleza() {
	/*Metoda getter care returneaza nota unui student
	la engleza*/
	return this->nota_engleza;
}

float Student::get_nota_istorie() {
	/*Metoda getter care returneaza nota unui student
	la istorie*/
	return this->nota_istorie;
}

float Student::get_media_generala() {
	/*Metoda care returneaza media generala a unui student
	output: o valoare intreaga*/
	return (this->nota_matematica + this->nota_istorie + this->nota_engleza) / 3.0;
}