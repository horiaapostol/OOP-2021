#include "Mazda.h"

Mazda::Mazda() :Car() {
	this->name = "Mazda";
	this->fuel_capacity = 51;
	this->fuel_consumption = 6.4;
	this->sunny_average_speed = 141.9;
	this->rain_average_speed = 123.3;
	this->snow_average_speed = 110.6;
};
Mazda::~Mazda() {};

std::string Mazda::get_name() {
	return this->name;
}
double Mazda::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Mazda::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Mazda::get_average_speed(Weather weather_type) {
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