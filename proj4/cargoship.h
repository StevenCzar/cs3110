/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #4
	Due: 3/06/20
*/
#ifndef CARGO_SHIP_H
#define CARGO_SHIP_H
#include <string>
#include "ship.h"

class CargoShip : public Ship
{
	private:
		double * fcb;
		double * acb;
		int total;
		double foward;
	public:
		CargoShip(){}
		CargoShip(std::string n, double l, int c, double p);
		~CargoShip();
		using Ship::fuel;
		void fuel(int f);
		using Ship::load;
		void load(int t);
};

#endif