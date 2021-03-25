#pragma once
#include "Car.h"
#include "string"

class Mercedes : virtual public Car {
private:
	std::string name;
public:
	Mercedes();
	~Mercedes();
	std::string get_name();
	double get_fuel_capacity();
	double get_fuel_consumption();
	double get_average_speed(int);
};

