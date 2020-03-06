#include "ship.h"
#include "cruiseship.h"
#include "cargoship.h"
/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #4
	Due: 3/06/20
*/
#include <iostream>
#include <fstream>
#include <string>

void sailShip(Ship &ship);

int main()
{
	//file i/o and init variables
	std::string name;
	double load, luxury, upper, lower;
	int passengers, tonnage, flashpoint, tot;
	std::fstream something;
	something.open("ships.txt");
	something >> name >> load >> luxury >> upper >> lower >> passengers;
	CruiseShip cruiseship(name, load, luxury, upper, lower);
	something >> name >> load >> tot >> luxury >> tonnage >> flashpoint;
	CargoShip cargoship(name, load, tot, luxury);

	//do cruiseship stuff
	cruiseship.fuel();
	cruiseship.load(passengers);
	sailShip(cruiseship);

	//do cargoship stuff
	cargoship.fuel(flashpoint);
	cargoship.load(tonnage);
	sailShip(cargoship);
}

void sailShip(Ship &ship)
{
	ship.sail();
}
