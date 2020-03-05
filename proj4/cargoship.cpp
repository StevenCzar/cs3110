#include "cargoship.h"
#include "ship.h"
#include <iostream>

CargoShip::CargoShip(string n, double l, int c, double p):Ship(n, l)
{
	acb = new double;
	fcb = new double;
	total = c;
	foward = p;
}

CargoShip::~CargoShip()
{
	acb = NULL;
	delete acb;
	fcb = NULL;
	delete fcb;
}

CargoShip::fuel(int f)
{
	Ship::fuel();
	std::cout << name << " " << f << std::endl;
}

CargoShip::load(int t)
{
	if(t > total)
	{
		t = total;
	}

	*fcb = t*p;
	t -= t*p;
	*acb = t;

	std::cout << name << " " << *fcb << " " << *acb << std::endl;
}