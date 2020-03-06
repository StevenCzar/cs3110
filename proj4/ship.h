/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #4
	Due: 3/06/20
*/
#ifndef SHIP_H
#define SHIP_H
#include <string>

class Ship
{
	protected:
		std::string name;
		double gas;
	public:
		//idk how to make it work without the default constructor...
		Ship(){}
		Ship(std::string, double);
		void fuel();
		virtual void sail();
		//pure virtual function for abstract class
		virtual void load(int) = 0;
};

#endif