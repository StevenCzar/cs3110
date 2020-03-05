#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include <string>

class CruiseShip : public Ship
{
	private:
		double luxury, upper_deck, lower_deck;
		int num_luxury, num_upper, num_lower;
	public:
		CruiseShip(std::string n, double f, double, double, double):Ship(n,f);
		using Ship::sail;
		void sail();
		using Ship::load;
		void load(int);
};

#endif