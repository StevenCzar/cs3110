/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #6
	Due: 4/02/20
*/
#include "wordtree.h"
#include <fstream>
#include <istream>
#include <string>
#include <iostream>
#include <algorithm>


int main()
{
	//init
	std::ifstream something;
	std::string word;
	char select;
	int threshold;
	something.open("input.txt");

	//create blank tree
	WordTree tree;

	//while reading from input.txt...
	while(something)
	{
		//getline arguments are string, max bit size, char delim
		//so making the delim an empty space will split up input
		std::something.getline(word, 256, ' ');
		//convert to lowercase
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		//add word to tree
		tree.addWord(word);
	}
	//initial output
	std::cout << "word tree built and loaded\n\n";
	//now begin 2nd file read
	something.close();
	something.open("queries.txt");

	//while reading from queries.txt...
	while(something)
	{
		//read char and move past the space
		something.get(select);
		something.ignore(40, ' ');

		if(select == 'C')
		{
			//get the threshold and call getCounts
			something >> threshold;
			std::cout << "Finding all words with " << threshold << " or more occurances: \n";
			tree.getCounts(threshold);
		}
		else if(select == 'F')
		{
			//get the word and call findWord
			something >> word;
			std::cout << "Searching for occurrences of the word '" << word << "'\n";
			tree.findWord(word);
		}
		else
		{
			//error message
			std::cout << "Dunno how you got here but there's an invalid selection\n\n";
		}
	}
}