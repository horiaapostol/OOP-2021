#include "Dodge.h"

Dodge::Dodge() :Car() {
	this->name = "Dodge Demon";
	this->fuel_capacity = 70;
	this->fuel_consumption = 21;
	weather[static_cast<int>(Weather::Sunny)] = 235.8;
	weather[static_cast<int>(Weather::Rain)] = 160.1;
	weather[static_cast<int>(Weather::Snow)] = 85.6;
};
Dodge::~Dodge() {};

std::string Dodge::get_name() {
	return this->name;
}
double Dodge::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Dodge::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Dodge::get_average_speed(int weather_type) {
	return this->weather[weather_type];
}


