#include "Jeep.h"

Jeep::Jeep() :Car() {
	this->name = "Jeep";
	this->fuel_capacity = 100;
	this->fuel_consumption = 28;
	weather[static_cast<int>(Weather::Sunny)] = 162.1;
	weather[static_cast<int>(Weather::Rain)] = 146.2;
	weather[static_cast<int>(Weather::Snow)] = 132.6;
};
Jeep::~Jeep() {};

std::string Jeep::get_name() {
	return this->name;
}
double Jeep::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Jeep::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Jeep::get_average_speed(int weather_type) {
	return this->weather[weather_type];
}
