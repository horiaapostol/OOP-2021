#include "Dodge.h"

Dodge::Dodge() :Car() {
	this->name = "Dodge";
	this->fuel_capacity = 70;
	this->fuel_consumption = 21;
	this->sunny_average_speed = 235.8;
	this->rain_average_speed = 160.1;
	this->snow_average_speed = 85.6;
};
Dodge::~Dodge() {};

std::string Dodge::get_name() {
	return this->name;
}
double Dodge::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Dodge::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Dodge::get_average_speed(Weather weather_type) {
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


