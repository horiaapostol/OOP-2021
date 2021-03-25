#include "Mercedes.h"

Mercedes::Mercedes() :Car() {
	this->name = "Mercedes";
	this->fuel_capacity = 80;
	this->fuel_consumption = 19.8;
	this->sunny_average_speed = 168.9;
	this->rain_average_speed = 131.4;
	this->snow_average_speed = 117.8;
};
Mercedes::~Mercedes() {};

std::string Mercedes::get_name() {
	return this->name;
}
double Mercedes::get_fuel_capacity() {
	return this->fuel_capacity;
}

double Mercedes::get_fuel_consumption() {
	return this->fuel_consumption;
}

double Mercedes::get_average_speed(Weather weather_type) {
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