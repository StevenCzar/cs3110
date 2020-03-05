#ifndef CARGO_SHIP_H
#define CARGO_SHIP_H
#include <string>

class CargoShip : public Ship
{
	private:
		double * fcb, acb;
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