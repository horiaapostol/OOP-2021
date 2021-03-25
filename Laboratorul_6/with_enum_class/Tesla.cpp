#include "Tesla.h"

Tesla::Tesla() :Car() {
	this->name = "Tesla";
	this->fuel_capacity = 10;
	this->fuel_consumption = 1.2;
	weather[static_cast<int>(Weather::Sunny)] = 218.7;
	weather[static_cast<int>(Weather::Rain)] = 145.1;
	weather[static_cast<int>(Weather::Snow)] = 120;
};
Tesla::~Tesla() {};

std::string Tesla::get_name() {
	return this->name;
}
double Tesla::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Tesla::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Tesla::get_average_speed(int weather_type) {
	return this->weather[weather_type];
}