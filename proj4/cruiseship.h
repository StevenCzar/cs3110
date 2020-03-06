/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #4
	Due: 3/06/20
*/
#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include <string>
#include "ship.h"

class CruiseShip : public Ship
{
	private:
		double luxury, upper_deck, lower_deck;
		int num_luxury, num_upper, num_lower;
	public:
		CruiseShip(){}
		CruiseShip(std::string n, double f, double, double, double);
		//using the using for overwriting functions
		using Ship::sail;
		void sail();
		using Ship::load;
		void load(int);
};

#endif