#include "ship.h"
#include <iostream>

Ship::Ship(string n, double f)
{
	name = n;
	fuel = f;
}

void Ship::fuel()
{
	std::cout << name << " " << fuel << std::endl;
}

void Ship::sail()
{
	std::cout << name << " sailing" << std::endl;
}