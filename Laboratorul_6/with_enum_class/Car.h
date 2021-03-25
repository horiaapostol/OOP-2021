#pragma once
#include"Weather.h"
#include "string"

class Car{
protected:
	double fuel_capacity;
	double fuel_consumption;
	double weather[3];
public:
	virtual std::string get_name() = 0;
	virtual double get_fuel_capacity() = 0;
	virtual double get_fuel_consumption() = 0;
	virtual double get_average_speed(int) = 0;
};

