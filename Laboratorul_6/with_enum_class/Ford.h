#pragma once
#include "Car.h"
#include "string"

class Ford : virtual public Car {
private:
	std::string name;
public:
	Ford();
	~Ford();
	std::string get_name();
	double get_fuel_capacity();
	double get_fuel_consumption();
	double get_average_speed(int);
};

