#pragma once
#include "Car.h"
#include "string"

class Toyota : virtual public Car {
private:
	std::string name;
public:
	Toyota();
	~Toyota();
	std::string get_name();
	double get_fuel_capacity();
	double get_fuel_consumption();
	double get_average_speed(int);
};

