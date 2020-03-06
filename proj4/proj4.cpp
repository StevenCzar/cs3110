#include "ship.h"
#include "cruiseship.h"
#include "cargoship.h"
#include <iostream>
#include <fstream>
#include <string>

void sailShip(Ship &ship);

int main()
{
	std::string name;
	double load, luxury, upper, lower;
	int passengers, tonnage, flashpoint, tot;
	std::fstream something;
	something.open("ships.txt");
	something >> name >> load >> luxury >> upper >> lower >> passengers;
	CruiseShip *cruiseship = new CruiseShip(name, load, luxury, upper, lower);
	something >> name >> load >> tot >> luxury >> tonnage >> flashpoint;
	CargoShip *cargoship = new CargoShip(name, load, tot, luxury);

	cruiseship->fuel();
	cruiseship->load(passengers);
	sailShip(cruiseship);

	cargoship->fuel(flashpoint);
	cargoship->load(tonnage);
	sailShip(cargoship);
}

void sailShip(Ship &ship)
{
	ship.sail();
}
