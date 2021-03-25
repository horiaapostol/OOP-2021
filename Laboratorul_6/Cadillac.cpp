#include "Cadillac.h"

Cadillac::Cadillac() :Car(){
	this->name = "Cadillac";
	this->fuel_capacity = 66;
	this->fuel_consumption = 13.8;
	this->sunny_average_speed = 178.1;
	this->rain_average_speed = 141.3;
	this->snow_average_speed = 107.6;
};
Cadillac::~Cadillac() {};

std::string Cadillac::get_name() {
	return this->name;
}
double Cadillac::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Cadillac::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Cadillac::get_average_speed(Weather weather_type) {
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


