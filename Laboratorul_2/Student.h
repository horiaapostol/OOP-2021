#pragma once
#include "string"

class Student {
private:
	std::string nume;
	float nota_matematica, nota_istorie, nota_engleza;
public:
	Student();
	Student(std::string nume);
	void set_nume(std::string nume);
	void set_nota_matematica(float nota_matematica);
	void set_nota_engleza(float nota_engleza);
	void set_nota_istorie(float nota_istorie);
	std::string get_nume();
	float get_nota_matematica();
	float get_nota_engleza();
	float get_nota_istorie();
	float get_media_generala();
};

