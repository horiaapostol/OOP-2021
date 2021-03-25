#include "Ford.h"

Ford::Ford() :Car() {
	this->name = "Ford";
	this->fuel_capacity = 80;
	this->fuel_consumption = 8.9;
	weather[static_cast<int>(Weather::Sunny)] = 148.1;
	weather[static_cast<int>(Weather::Rain)] = 143.3;
	weather[static_cast<int>(Weather::Snow)] = 122.6;
};
Ford::~Ford() {};

std::string Ford::get_name() {
	return this->name;
}
double Ford::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Ford::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Ford::get_average_speed(int weather_type) {
	return this->weather[weather_type];
}
