#include "maze.h"
#include <fstream>
#include <string>
#include <iostream>

int main()
{
	bool isFound = false;
	std::ifstream something;
	something.open("maze.txt");

	Maze maze(something);
	maze.FindExit(1,1,isFound);

	if(isFound == true)
	{
		std::cout << "Found Exit!\n";
	}
	else
	{
		maze.Print();
		std::cout << "No exit!\n";
	}
}