#include "cruiseship.h"
#include <iostream>

CruiseShip::CruiseShip(std::string n, double l, double lux, double up, double low):Ship(n,f);
{
	luxury = lux;
	upper_deck = up;
	lower_deck = low;
}

void CruiseShip::sail()
{
	std::cout << name << " " << num_luxury << " " << num_upper << " " << num_lower << std::endl;
}

void CruiseShip::load(int total)
{
	num_luxury = total*luxury;
	num_upper = total*upper_deck;
	num_lower = total*lower_deck;
}