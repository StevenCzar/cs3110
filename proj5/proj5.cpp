/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #5
	Due: 4/02/20
*/
#include "maze.h"
#include <fstream>
#include <string>
#include <iostream>

int main()
{
	//init stuff
	bool isFound = false;
	std::ifstream something;
	something.open("maze.txt");

	//make maze and start traversal
	Maze maze(something);
	maze.FindExit(1,1,isFound);

	//if there's an exit...
	if(isFound == true)
	{
		//say you found an exit
		std::cout << "Found Exit!\n";
	}
	//if there's not an exit...
	else
	{
		//print maze one last time and say no exit
		maze.Print();
		std::cout << "No exit!\n";
	}
}