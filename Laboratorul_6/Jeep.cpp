#include "Jeep.h"

Jeep::Jeep() :Car() {
	this->name = "Jeep";
	this->fuel_capacity = 100;
	this->fuel_consumption = 28;
	this->sunny_average_speed = 162.1;
	this->rain_average_speed = 146.2;
	this->snow_average_speed = 132.6;
};
Jeep::~Jeep() {};

std::string Jeep::get_name() {
	return this->name;
}
double Jeep::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Jeep::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Jeep::get_average_speed(Weather weather_type) {
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
