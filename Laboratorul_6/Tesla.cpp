#include "Tesla.h"

Tesla::Tesla() :Car() {
	this->name = "Tesla";
	this->fuel_capacity = 10;
	this->fuel_consumption = 1.2;
	this->sunny_average_speed = 218.7;
	this->rain_average_speed = 145.1;
	this->snow_average_speed = 120;
};
Tesla::~Tesla() {};

std::string Tesla::get_name() {
	return this->name;
}
double Tesla::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Tesla::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Tesla::get_average_speed(Weather weather_type) {
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