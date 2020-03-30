#include "maze.h"
#include <fstream>
#include <string>

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
		std::cout << "No exit!\n";
	}
}