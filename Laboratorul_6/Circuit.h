#pragma once
#include "Car.h"
#include "Cadillac.h"
#include "Chevrolet.h"
#include "Dacia.h"
#include "Dodge.h"
#include "Ferrari.h"
#include "Ford.h"
#include "Jeep.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Tesla.h"
#include "Toyota.h"
#include "Weather.h"
#include "iostream"
#include "list"
#include "string"
#include "utility"
#include "vector"

class Circuit{
private:
	std::list<Car*> repository;
	std::vector<std::pair<std::string, double>> results;
	unsigned int length;
	Weather weather;
public:
	Circuit();
	 ~Circuit();
	void SetLength(unsigned int);
	void SetWeather(Weather);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};