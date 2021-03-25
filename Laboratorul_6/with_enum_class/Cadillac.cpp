#include "Cadillac.h"

Cadillac::Cadillac() :Car(){
	this->name = "Cadillac";
	this->fuel_capacity = 66;
	this->fuel_consumption = 13.8;
	weather[static_cast<int>(Weather::Sunny)] = 178.1;
	weather[static_cast<int>(Weather::Rain)] = 141.3;
	weather[static_cast<int>(Weather::Snow)] = 107.6;
};
Cadillac::~Cadillac() {};

std::string Cadillac::get_name() {
	return this->name;
}
double Cadillac::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Cadillac::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Cadillac::get_average_speed(int weather_type) {
	return this->weather[weather_type];
}


