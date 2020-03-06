/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #4
	Due: 3/06/20
*/
#include "ship.h"
#include <iostream>

//easy constructor
Ship::Ship(std::string n, double f)
{
	name = n;
	gas = f;
}

//print the name and fuel amount
void Ship::fuel()
{
	std::cout << name << " " << gas << std::endl;
}

//set sail
void Ship::sail()
{
	std::cout << name << " sailing" << std::endl;
}