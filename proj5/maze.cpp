#include "maze.h"
#include <iostream>

Maze::Maze(std::ifstream& input)
{
	//get stuff from file input
	input >> xplor;
	input >> maxRows >> maxCols;

	//fill maze with chars
	for(int i = 0; i < maxRows+2; i++)
	{
		for(int j = 0; j < maxCols+2; j++)
		{
			if(i == 0 || j == 0 || i == maxRows+2 || j == maxCols+2)
			{
				//put X's on the border
				maze[i][j] = 'X';
			}
			//otherwise put the char in the maze
			input >> maze[i][j];
		}
	}
}

//prints the maze... wow
void Maze::Print()
{
	std::cout << "Maze state: \n";
	for(int i = 1; i < maxRows+1; i++)
	{
		for(int j = 1; j < maxCols+1; j++)
		{
			std::cout << maze[i][j];
		}
		std::cout << "\n";
	}
}

//check to find the exit and move to the next space if haven't
void Maze::FindExit(int row, int col, bool& found)
{
	
	//check if you moved onto an x, if so, move back
	if(maze[row][col] == 'X')
	{
		return;
	}
	//print maze state
	Print();
	//say what tile you're exploring
	//if you're exploring tile 1,1, say it is starting tile
	if(row == 1 && col == 1)
	{
		std::cout << "Start position: 1,1\n";
	}
	std::cout << "Exploring " << row << "," << col << "\n";
	//check if you found the exit
	if(maze[row][col] == 'E')
	{
		found = true;
		return;
	}

	//if you make it to this point, it means you have a valid move
	//make the tile you're on a * and then attempt to move
	maze[row][col] = '*';
	//if you haven't found the exit...
	while(found!=true)
	{
		//this makes you check all directions
		for(int i = 0; i < 4; i++)
		{
			//uses string.at to parse through string
			//gets the duple for the next location to move
			std::pair<int,int> move = getMove(xplor.at(i));
			//move to the next space and attempt to find exit
			FindExit(row+move.first, col+move.second, found);
			//if you found the exit previously, keep leaving function
			if(found == true)
			{
				return;
			}
		}
	}
	return;
}

//returns where to go next based on the xplor string
std::pair<int,int> getMove(char dir)
{	std::pair<int,int> move;
	//for all directions, check if it's a valid move, then move
	if(dir == 'N')
	{
		//north is row -1 col 0
		move = std::make_pair(-1, 0);
	}
	if(dir == 'S')
	{
		//south is row +1 col 0
		move = std::make_pair(1, 0);
	}
	if(dir == 'W')
	{
		//west is row 0 col -1
		move = std::make_pair(0, -1);
	}
	if(dir == 'E')
	{
		//east is row 0 col +1
		move = std::make_pair(0, 1);
	}
	return move;
}