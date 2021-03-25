#include "Toyota.h"

Toyota::Toyota() :Car() {
	this->name = "Toyota";
	this->fuel_capacity = 55;
	this->fuel_consumption = 10.2;
	weather[static_cast<int>(Weather::Sunny)] = 153.2;
	weather[static_cast<int>(Weather::Rain)] = 127.9;
	weather[static_cast<int>(Weather::Snow)] = 112.5;
};
Toyota::~Toyota() {};

std::string Toyota::get_name() {
	return this->name;
}
double Toyota::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Toyota::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Toyota::get_average_speed(int weather_type) {
	return this->weather[weather_type];
}