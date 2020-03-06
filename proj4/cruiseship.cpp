/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #4
	Due: 3/06/20
*/
#include "cruiseship.h"
#include "ship.h"
#include <iostream>

//easy constructor
CruiseShip::CruiseShip(std::string n, double f, double lux, double up, double low):Ship(n,f)
{
	luxury = lux;
	upper_deck = up;
	lower_deck = low;
}

//overwritten function for sail
void CruiseShip::sail()
{
	std::cout << name << " " << num_luxury << " " << num_upper << " " << num_lower << std::endl;
}

//load percentage*total for each section
void CruiseShip::load(int total)
{
	num_luxury = total*luxury;
	num_upper = total*upper_deck;
	num_lower = total*lower_deck;
}