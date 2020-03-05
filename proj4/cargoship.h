#ifndef CARGO_SHIP.H
#define CARGO_SHIP
#include <string>

class CargoShip : public Ship
{
	private:
		double * fcb, acb;
		int total;
		double foward;
	public:
		CargoShip(std::string n, double l, int c, double p):Ship(n, l);
		~CargoShip
		using Ship::fuel;
		void fuel(int f);
		using Ship::load;
		void load(int t);
};

#endif