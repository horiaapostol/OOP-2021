#include "Dacia.h"

Dacia::Dacia() :Car() {
	this->name = "Dacia";
	this->fuel_capacity = 50.1;
	this->fuel_consumption = 5.1;
	weather[static_cast<int>(Weather::Sunny)] = 125.2;
	weather[static_cast<int>(Weather::Rain)] = 101.9;
	weather[static_cast<int>(Weather::Snow)] = 82.3;
};
Dacia::~Dacia() {};

std::string Dacia::get_name() {
	return this->name;
}
double Dacia::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Dacia::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Dacia::get_average_speed(int weather_type) {
	return this->weather[weather_type];
}



