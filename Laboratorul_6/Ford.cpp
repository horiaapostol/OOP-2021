#include "Ford.h"

Ford::Ford() :Car() {
	this->name = "Ford";
	this->fuel_capacity = 80;
	this->fuel_consumption = 8.9;
	this->sunny_average_speed = 148.1;
	this->rain_average_speed = 143.3;
	this->snow_average_speed = 122.6;
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

double Ford::get_average_speed(Weather weather_type) {
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
