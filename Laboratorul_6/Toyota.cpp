#include "Toyota.h"

Toyota::Toyota() :Car() {
	this->name = "Toyota";
	this->fuel_capacity = 55;
	this->fuel_consumption = 10.2;
	this->sunny_average_speed = 153.2;
	this->rain_average_speed = 127.9;
	this->snow_average_speed = 112.5;
};
Toyota::~Toyota() {};

std::string Toyota::get_name() {
	return this->name;
}
double Toyota::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Toyota::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Toyota::get_average_speed(Weather weather_type) {
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