#include "Ferrari.h"

Ferrari::Ferrari() :Car() {
	this->name = "Ferrari";
	this->fuel_capacity = 110;
	this->fuel_consumption = 39;
	this->sunny_average_speed = 222.4;
	this->rain_average_speed = 152.3;
	this->snow_average_speed = 91.6;
};
Ferrari::~Ferrari() {};

std::string Ferrari::get_name() {
	return this->name;
}
double Ferrari::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Ferrari::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Ferrari::get_average_speed(Weather weather_type) {
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

