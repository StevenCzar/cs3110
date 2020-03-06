#include "cargoship.h"
#include "ship.h"
#include <iostream>

CargoShip::CargoShip(string n, double l, int c, double p):Ship(n, l)
{
	double *acb;
	double *fcb;
	acb = new double(0);
	fcb = new double(0);
	total = c;
	foward = p;
}

CargoShip::~CargoShip()
{
	delete &acb;
	acb = NULL;
	delete &fcb;
	fcb = NULL;
}

void CargoShip::fuel(int f)
{
	Ship::fuel();
	std::cout << name << " " << f << std::endl;
}

void CargoShip::load(int t)
{
	if(t > total)
	{
		t = total;
	}

	fcb = t*foward;
	t -= t*foward;
	acb = t;

	std::cout << name << " " << fcb << " " << acb << std::endl;
}