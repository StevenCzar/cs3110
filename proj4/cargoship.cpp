/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #4
	Due: 3/06/20
*/
#include "cargoship.h"
#include "ship.h"
#include <iostream>

//Constructor for cargo ship
CargoShip::CargoShip(std::string n, double l, int c, double p):Ship(n, l)
{
	//init pointers to 0
	acb = new double(0);
	fcb = new double(0);
	total = c;
	foward = p;
}

//Destructor to free the pointers
CargoShip::~CargoShip()
{
	delete acb;
	acb = NULL;
	delete fcb;
	fcb = NULL;
}

//Calls the ship fuel action
void CargoShip::fuel(int f)
{
	Ship::fuel();
	std::cout << name << " " << f << std::endl;
}

//loads the cargo bays
void CargoShip::load(int t)
{
	//if t is too big, just make it the total capacity
	if(t > total)
	{
		t = total;
	}
	//nothing special here since multiplying results in double
	*fcb = t*foward;
	t -= t*foward;
	//typecast the remaining int as a double and store
	*acb = (double)t;
	std::cout << name << " " << *fcb << " " << *acb << std::endl;
}