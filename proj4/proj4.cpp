#include "ship.h"
#include "cruiseship.h"
#include "cargoship.h"
#include <iostream>
#include <fstream>
#include <string>

void sailShip(Ship &ship);

int main()
{
	string name;
	double load, luxury, upper, lower;
	int passengers, tonnage, flashpoint;
	fstream something;
	something.open("ships.txt");
	something >> name >> load >> luxury >> upper >> lower >> passengers;
	CruiseShip *cruiseship = new CruiseShip(name, load, luxury, upper, lower);
	something >> name >> load >> passengers >> luxury >> tonnage >> flashpoint;
	CargoShip *cargoship = new CargoShip(name, load, passengers, luxury);

	cruiseship->fuel();
	cruiseship->load();
	shipSail(cruiseship);

	cargoship->fuel(flashpoint);
	cargoship->load(tonnage);
	shipSail(cargoship);
}

void sailShip(Ship &ship)
{
	ship->sail();
}
