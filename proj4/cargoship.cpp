#include "cargoship.h"
#include "ship.h"
#include <iostream>

CargoShip::CargoShip(std::string n, double l, int c, double p):Ship(n, l)
{
	acb = new double(0);
	fcb = new double(0);
	total = c;
	foward = p;
}

CargoShip::~CargoShip()
{
	delete acb;
	acb = NULL;
	delete fcb;
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
	std::cout << "hello" << std::endl;
	*fcb = t*foward;
	std::cout << "hello2" << std::endl;
	t -= t*foward;
	*acb = (double)t;
	std::cout << "hello3" << std::endl;
	std::cout << name << " " << fcb << " " << acb << std::endl;
}