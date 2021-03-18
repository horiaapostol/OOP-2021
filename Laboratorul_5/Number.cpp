#include "Number.h"
#include "iostream"
#include "string"
#include "stack"

Number::Number(const char* value, int base) 
	:value{ value }, base{ base }{};
Number::~Number() {};
Number::Number(const Number& d) {
	value = d.value;
	base = d.base;
}
Number::Number(const int& d) {
	std::string numar = std::to_string(d);
	value = _strdup(numar.c_str());
	base = 10;
}
Number::Number(const char* d) {
	value = _strdup(d);
	base = 10;
}
Number::Number(Number&& d) noexcept
	:value{ d.value }, base{ d.base }
{
	d.value = nullptr;  
	d.base = 0; 
};
namespace functii_auxiliare {
	template<typename T>
	void swap(T& a, T& b) {
		/*rvalues static cast*/
		T temp = std::move(a);
		a = std::move(b);
		b = std::move(temp);
	}
	int baza_b_in_baza_10(const char* a, const int b) {
		int rezultat = 0;
		bool negativ = false;
		if (a[0] == '-') {
			negativ = true;
			std::string temp = a;
			std::string numar_pozitiv = temp.substr(1);
			a = _strdup(numar_pozitiv.c_str());
		}
		for (int i = 0; a[i]; ++i) {
			if ('0' <= a[i] && a[i] <= '9')
				rezultat = rezultat * b + a[i] - '0';
			else
				rezultat = rezultat * b + a[i] - 'A' + 10;
		}
		if (negativ) {
			rezultat = -rezultat;
		}
		return rezultat;
	}
	const char* baza_10_in_baza_b(int numar_in_baza_10, int baza) {
		if (numar_in_baza_10 == 0)
			return "0";
		std::stack<char> stiva;
		std::string rezultat;
		bool negativ = false;
		if (numar_in_baza_10 < 0) {
			negativ = true;
			numar_in_baza_10 = -numar_in_baza_10;
		}
		while (numar_in_baza_10) {
			if (numar_in_baza_10 % baza < 10)
				stiva.push(numar_in_baza_10 % baza + '0');
			else
				stiva.push(numar_in_baza_10 % baza + 'A' - 10);
			numar_in_baza_10 /= baza;
		}
		while (!stiva.empty()) {
			rezultat += stiva.top();
			stiva.pop();
		}
		if (negativ) {
			std::string semn = "-";
			return _strdup((semn + rezultat).c_str());
		}
		return _strdup(rezultat.c_str());
	}
};
Number& Number::operator=(Number&& d) noexcept{
	functii_auxiliare::swap(this->value, d.value);
	functii_auxiliare::swap(this->base, d.base);
	return *this;
}
Number& Number::operator=(int d) {
	std::string numar = std::to_string(d);
	this->value = _strdup(numar.c_str());
	auto temp_base = this->base;
	this->base = 10;
	this->SwitchBase(temp_base);
	return *this;
}
Number& Number::operator=(const char* d) {
	this->value = _strdup(d);
	auto temp_base = this->base;
	this->base = 10;
	this->SwitchBase(temp_base);
	return *this;
}
Number operator+(const Number& a, const Number& b) {
	int first = functii_auxiliare::baza_b_in_baza_10(a.value, a.base);
	int second = functii_auxiliare::baza_b_in_baza_10(b.value, b.base);
	int baza_de_lucru = std::max(a.base, b.base);
	Number rez("0", baza_de_lucru);
	int rezultat = first + second;
	rez.value = functii_auxiliare::baza_10_in_baza_b(rezultat, baza_de_lucru);
	return rez;
}
Number operator-(const Number& a, const Number& b) {
	int first = functii_auxiliare::baza_b_in_baza_10(a.value, a.base);
	int second = functii_auxiliare::baza_b_in_baza_10(b.value, b.base);
	int baza_de_lucru = std::max(a.base, b.base);
	Number rez("0", baza_de_lucru);
	if (first == second)
		return rez;
	else if (first > second) {
		int rezultat = first - second;
		rez.value = functii_auxiliare::baza_10_in_baza_b(rezultat, baza_de_lucru);
		return rez;
	}
	else {
		int rezultat = second - first;
		std::string modul = functii_auxiliare::baza_10_in_baza_b(rezultat, baza_de_lucru);
		std::string semn = "-";
		rez.value = _strdup((semn + modul).c_str());
		return rez;
	}
}
void Number::operator+=(const Number& d) {
	int first = functii_auxiliare::baza_b_in_baza_10(this->value, this->base);
	int second = functii_auxiliare::baza_b_in_baza_10(d.value, d.base);
	int baza_de_lucru = std::max(this->base, d.base);
	Number rez("0", baza_de_lucru);
	int rezultat = first + second;
	rez.value = functii_auxiliare::baza_10_in_baza_b(rezultat, baza_de_lucru);
	this->base = baza_de_lucru;
	this->value = rez.value;
}
void Number::operator-=(const Number& d) {
	int first = functii_auxiliare::baza_b_in_baza_10(this->value, this->base);
	int second = functii_auxiliare::baza_b_in_baza_10(d.value, d.base);
	int baza_de_lucru = std::max(this->base, d.base);
	Number rez("0", baza_de_lucru);
	if (first == second) {
		this->base = baza_de_lucru;
		this->value = rez.value;
	}
	else if (first > second) {
		int rezultat = first - second;
		rez.value = functii_auxiliare::baza_10_in_baza_b(rezultat, baza_de_lucru);
		this->base = baza_de_lucru;
		this->value = rez.value;
	}
	else {
		int rezultat = second - first;
		std::string modul = functii_auxiliare::baza_10_in_baza_b(rezultat, baza_de_lucru);
		std::string semn = "-";
		rez.value = _strdup((semn + modul).c_str());
		this->base = baza_de_lucru;
		this->value = rez.value;
	}
}
void Number::operator!() {
	std::string numar = this->value;
	if (numar[0] == '-') {
		std::string numar_pozitiv = numar.substr(1);
		this->value = _strdup(numar_pozitiv.c_str());
	}
	else {
		std::string minus = "-";
		this->value = _strdup((minus + numar).c_str());
	}
}
bool Number::operator>(const Number& d) {
	int first_int = functii_auxiliare::baza_b_in_baza_10(this->value, this->base);
	int second_int = functii_auxiliare::baza_b_in_baza_10(d.value, d.base);
	return (first_int > second_int);
}
bool Number::operator<(const Number& d) {
	int first_int = functii_auxiliare::baza_b_in_baza_10(this->value, this->base);
	int second_int = functii_auxiliare::baza_b_in_baza_10(d.value, d.base);
	return (first_int < second_int);
}
bool Number::operator==(const Number& d) {
	int first_int = functii_auxiliare::baza_b_in_baza_10(this->value, this->base);
	int second_int = functii_auxiliare::baza_b_in_baza_10(d.value, d.base);
	return (first_int == second_int);
}
bool Number::operator>=(const Number& d) {
	int first_int = functii_auxiliare::baza_b_in_baza_10(this->value, this->base);
	int second_int = functii_auxiliare::baza_b_in_baza_10(d.value, d.base);
	return (first_int >= second_int);
}
bool Number::operator<=(const Number& d) {
	int first_int = functii_auxiliare::baza_b_in_baza_10(this->value, this->base);
	int second_int = functii_auxiliare::baza_b_in_baza_10(d.value, d.base);
	return (first_int <= second_int);
}
bool Number::operator!=(const Number& d) {
	int first_int = functii_auxiliare::baza_b_in_baza_10(this->value, this->base);
	int second_int = functii_auxiliare::baza_b_in_baza_10(d.value, d.base);
	return (first_int != second_int);
}
char Number::operator[](int index) {
	std::string numar = this->value;
	try {
		if (numar[0] == '-') {
			std::string temp = numar.substr(1);
			numar = temp;
		}
		if ((unsigned)index >= numar.size()) {
			throw("Out of range!");
		}
		return numar[index];
	}
	catch (const char* x) {
		std::cout << x;
	}
	return ' ';
}
void Number::operator--() {
	std::string numar = this->value;
	bool negativ = false;
	if (numar[0] == '-') {
		negativ = true;
		std::string temp = numar.substr(1);
		numar = temp;
	}
	if (numar.size() == 1)
		this->value = "0";
	else {
		std::string modificat = numar.substr(1);
		if (negativ) {
			this->value = _strdup(("-" + modificat).c_str());
		}
		else {
			this->value = _strdup(modificat.c_str());
		}
	}
}

void Number::operator--(int) {
	std::string numar = this->value;
	if ((numar[0] == '-' && numar.size() == 2) || numar.size() == 1) {
		this->value = "0";
	}
	else {
		std::string modificat = numar.substr(0, numar.size() - 1);
		this->value = _strdup(modificat.c_str());
	}
}
void Number::SwitchBase(int newBase) {
	try {
		if (newBase < 2 || newBase > 16)
			throw("Baza incorecta!");
		if (this->value[0] == '-' && newBase != 10) 
			throw(newBase);
		else {
			int numarul_in_baza_10 = functii_auxiliare::baza_b_in_baza_10(this->value, this->base);
			this->value = functii_auxiliare::baza_10_in_baza_b(numarul_in_baza_10, newBase);
			this->base = newBase;
		}
	}
	catch (const char* x) {
		std::cout << x << '\n';
	}
	catch(int newBase){
		std::cout << "Nu pot schimba un numar negativ in baza " << newBase << "!\n";
	}	
}
int Number::GetDigitsCount() {
	std::string modul = this->value;
	int numarul_de_caractere = modul.size();
	if (modul[0] == '-') {
		numarul_de_caractere--;
	}
	return numarul_de_caractere;
}
int Number::GetBase() {
	return this->base;
}
void Number::Print() {
	try {
		if (this->value[0] == '-' && this->base != 10) {
			throw(this->base);
		}
		else {
			std::cout << this->value << '\n';
		}
	}
	catch (...) {
		std::cout << "Numarul " << this->value + 1<<" afisat negativ in baza " << this->base << " poate fi reprezentat gresit!\n";
	}
}
