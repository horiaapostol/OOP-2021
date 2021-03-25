#include "Dacia.h"

Dacia::Dacia() :Car() {
	this->name = "Dacia";
	this->fuel_capacity = 50.1;
	this->fuel_consumption = 5.1;
	this->sunny_average_speed = 125.2;
	this->rain_average_speed = 101.9;
	this->snow_average_speed = 82.3;
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

double Dacia::get_average_speed(Weather weather_type) {
	switch (weather_type) {
	case Weather::Sunny:
		return this->sunny_average_speed;
		break;
	case Weather::Rain:
		return this->rain_average_speed;
		break;
	case Weather::Snow:
		return this->snow_average_speed;
		break;
	default:
		return this->sunny_average_speed;
		break;
	}
}



