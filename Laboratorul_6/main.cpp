#include "iostream"
#include "Circuit.h"

int main() {
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Dacia());
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());
	c.AddCar(new Cadillac());
	c.AddCar(new Chevrolet());
	c.AddCar(new Dodge());
	c.AddCar(new Ferrari());
	c.AddCar(new Jeep());
	c.AddCar(new Tesla());
	c.Race();
	c.ShowFinalRanks();
	c.ShowWhoDidNotFinish(); 

	c.SetWeather(Weather::Sunny);
	c.SetLength(450);
	c.Race();
	c.ShowFinalRanks();
	c.ShowWhoDidNotFinish();

	c.SetWeather(Weather::Snow);
	c.SetLength(350);
	c.Race();
	c.ShowFinalRanks();
	c.ShowWhoDidNotFinish();

	c.SetWeather(Weather::Sunny);
	c.SetLength(1);
	c.Race();
	c.ShowFinalRanks();
	c.ShowWhoDidNotFinish();

	return 0;
}