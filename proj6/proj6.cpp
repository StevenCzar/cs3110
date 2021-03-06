/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #6
	Due: 4/14/20
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
	std::string select;
	int threshold;
	something.open("input.txt");

	//create blank tree
	WordTree tree;

	//while reading from input.txt...
	while(something)
	{
		//getline arguments are istream, string, and delim char
		//so making the delim an empty space will split up input
		getline(something, word, ' ');
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
		getline(something, select, ' ');

		if(select == "C")
		{
			//get the threshold and call getCounts
			something >> threshold;
			std::cout << "Finding all words with " << threshold << " or more occurances: \n";
			tree.getCounts(threshold);

			//move past newline char
			something.ignore(40, '\n');
		}
		if(select == "F")
		{
			//get the word and call findWord
			something >> word;
			std::cout << "Searching for occurrences of the word '" << word << "'\n";
			tree.findWord(word);

			//move past newline char
			something.ignore(40, '\n');
		}
	}
}