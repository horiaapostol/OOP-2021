#pragma once
#include "Car.h"
#include "string"

class Dodge : virtual public Car {
private:
	std::string name;
public:
	Dodge();
	~Dodge();
	std::string get_name();
	double get_fuel_capacity();
	double get_fuel_consumption();
	double get_average_speed(int);
};

