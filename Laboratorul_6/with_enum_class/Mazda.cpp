#include "Mazda.h"

Mazda::Mazda() :Car() {
	this->name = "Mazda";
	this->fuel_capacity = 51;
	this->fuel_consumption = 6.4;
	weather[static_cast<int>(Weather::Sunny)] = 141.9;
	weather[static_cast<int>(Weather::Rain)] = 123.3;
	weather[static_cast<int>(Weather::Snow)] = 110.6;
};
Mazda::~Mazda() {};

std::string Mazda::get_name() {
	return this->name;
}
double Mazda::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Mazda::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Mazda::get_average_speed(int weather_type) {
	return this->weather[weather_type];
}