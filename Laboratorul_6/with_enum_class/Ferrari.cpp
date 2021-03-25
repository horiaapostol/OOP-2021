#include "Ferrari.h"

Ferrari::Ferrari() :Car() {
	this->name = "Ferrari";
	this->fuel_capacity = 110;
	this->fuel_consumption = 39;
	weather[static_cast<int>(Weather::Sunny)] = 222.4;
	weather[static_cast<int>(Weather::Rain)] = 152.3;
	weather[static_cast<int>(Weather::Snow)] = 91.6;
};
Ferrari::~Ferrari() {};

std::string Ferrari::get_name() {
	return this->name;
}
double Ferrari::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Ferrari::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Ferrari::get_average_speed(int weather_type) {
	return this->weather[weather_type];
}

