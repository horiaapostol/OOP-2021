#include "Chevrolet.h"

Chevrolet::Chevrolet() :Car() {
	this->name = "Chevrolet";
	this->fuel_capacity = 72.2;
	this->fuel_consumption = 19.5;
	weather[static_cast<int>(Weather::Sunny)] = 190.9;
	weather[static_cast<int>(Weather::Rain)] = 139.3;
	weather[static_cast<int>(Weather::Snow)] = 104.7;
};

Chevrolet::~Chevrolet() {};

std::string Chevrolet::get_name() {
	return this->name;
}

double Chevrolet::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Chevrolet::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Chevrolet::get_average_speed(int weather_type) {
	return this->weather[weather_type];
}




