#include "Chevrolet.h"

Chevrolet::Chevrolet() :Car() {
	this->name = "Chevrolet";
	this->fuel_capacity = 72.2;
	this->fuel_consumption = 19.5;
	this->sunny_average_speed = 190.9;
	this->rain_average_speed = 139.3;
	this->snow_average_speed = 104.7;
};

Chevrolet::~Chevrolet() {};

std::string Chevrolet::get_name() {
	return this->name;
}

double Chevrolet::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Chevrolet::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Chevrolet::get_average_speed(Weather weather_type) {
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




