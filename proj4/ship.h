#ifndef SHIP_H
#define SHIP_H
#include <string>

class Ship
{
	protected:
		std::string name;
		double gas;
	public:
		Ship(){};
		Ship(std::string, double);
		void fuel();
		virtual void sail();
		virtual void load(int) = 0;
};

#endif