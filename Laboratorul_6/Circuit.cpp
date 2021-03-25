#include "Circuit.h"
#include "Car.h"
#include "algorithm"
#include "iomanip"

Circuit::Circuit() : weather { Weather::Sunny }, length{ 0 }{};

Circuit::~Circuit() {};

void Circuit::SetLength(unsigned int length) {
	this->length = length;
}

void Circuit::SetWeather(Weather weather_type) {
	this->weather = weather_type;
}
void Circuit::AddCar(Car* new_car) {
	this->repository.push_back(new_car);
}

void Circuit::Race() {
	this->results.clear();
	for (auto i : this->repository) {
		double distanta_posibila = (100 * i->get_fuel_capacity()) / i->get_fuel_consumption();
		if (this->length > distanta_posibila) {
			this->results.push_back(std::make_pair(i->get_name(), -1));
		}	
		else {
			double viteza_actuala_in_kmh = i->get_average_speed(this->weather);
			double viteza_actuala_in_mps = viteza_actuala_in_kmh * 0.277777777777;
			double secunde_necesare = this->length / viteza_actuala_in_mps * 1000;
			this->results.push_back(std::make_pair(i->get_name(), secunde_necesare));
		}
	}
}

class Second{
public:
	template<typename T>
	bool operator()(const T& a, const T& b) {
		return a.second < b.second;
	}
};
void Circuit::ShowFinalRanks() {
	std::sort(this->results.begin(), this->results.end(), Second());
	switch (this->weather){
	case Weather::Sunny:
		std::cout << "Ranks for sunny weather, " << this->length << " kilometers:\n\n";
		break;
	case Weather::Rain:
		std::cout << "Ranks for rainy weather, " << this->length << " kilometers:\n\n";
		break;
	case Weather::Snow:
		std::cout << "Ranks for snowy weather, " << this->length << " kilometers:\n\n";
		break;
	default:
		break;
	}
	for (auto i : this->results) {
		if (i.second != -1) {
			double ore = (int)i.second / 3600;
			double minute = ((int)i.second % 3600) / 60;
			double secunde = ((int)i.second % 60);
			std::cout << i.first << " : "; 
			if (ore > 0)
				std::cout << ore << ':';
			if (minute < 10)
				std::cout << '0';
			std::cout << minute << ':';
			if (secunde < 10)
				std::cout << '0';
			std::cout << secunde << '\n';
		}
	}
	std::cout << '\n';
}

void Circuit::ShowWhoDidNotFinish() {
	std::cout << "Did not finish:\n";

	int count = 0;
	for (auto i : this->results) {
		if (i.second == -1) {
			std::cout << i.first << '\n';
			++count;
		}
	}
	if (count == 0) {
		std::cout << "None\n";
	}
	std::cout << '\n';
}