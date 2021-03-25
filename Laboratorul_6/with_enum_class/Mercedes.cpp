#include "Mercedes.h"

Mercedes::Mercedes() :Car() {
	this->name = "Mercedes";
	this->fuel_capacity = 80;
	this->fuel_consumption = 19.8;
	weather[static_cast<int>(Weather::Sunny)] = 168.9;
	weather[static_cast<int>(Weather::Rain)] = 131.4;
	weather[static_cast<int>(Weather::Snow)] = 117.8;

};
Mercedes::~Mercedes() {};

std::string Mercedes::get_name() {
	return this->name;
}
double Mercedes::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Mercedes::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Mercedes::get_average_speed(int weather_type) {
	return this->weather[weather_type];
}