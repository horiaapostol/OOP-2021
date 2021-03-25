#pragma once
#include "Car.h"
#include "string"

class Chevrolet : virtual public Car {
private:
	std::string name;
public:
	Chevrolet();
	~Chevrolet();
	std::string get_name();
	double get_fuel_capacity();
	double get_fuel_consumption();
	double get_average_speed(int);
};


