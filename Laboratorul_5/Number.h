#pragma once

class Number {
private:
	const char* value;
	int base;
public:
	Number(const char* value, int base);
	~Number();
	Number(const Number& d);
	Number(const int& d);
	Number(const char* d);
	Number(Number&& d) noexcept;

	Number& operator=(const Number&) = default;
	Number& operator=(Number&&) noexcept;
	Number& operator=(int);
	Number& operator=(const char*);

	friend Number operator+(const Number&, const Number&);
	friend Number operator-(const Number&, const Number&);
	
	void operator+=(const Number&);
	void operator-=(const Number&);
	void operator!();
	bool operator>(const Number&);
	bool operator<(const Number&);
	bool operator==(const Number&);
	bool operator>=(const Number&);
	bool operator<=(const Number&);
	bool operator!=(const Number&);
	char operator[](int index);
	void operator--();
	void operator--(int);

	void SwitchBase(int newBase);
	int GetDigitsCount();
	int GetBase();
	void Print();
};

