#include "ship.h"
#include <iostream>

Ship::Ship(string n, double f)
{
	name = n;
	gas = f;
}

void Ship::fuel()
{
	std::cout << name << " " << gas << std::endl;
}

void Ship::sail()
{
	std::cout << name << " sailing" << std::endl;
}