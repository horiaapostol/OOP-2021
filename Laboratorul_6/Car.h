#pragma once
#include"Weather.h"
#include "string"

class Car{
protected:
	double fuel_capacity;
	double fuel_consumption;
	double sunny_average_speed;
	double rain_average_speed;
	double snow_average_speed;
public:
	virtual std::string get_name() = 0;
	virtual double get_fuel_capacity() = 0;
	virtual double get_fuel_consumption() = 0;
	virtual double get_average_speed(Weather) = 0;
};

