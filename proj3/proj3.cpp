/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #3
	Due: 2/23/20
*/

#include "player.h"
#include "card.h"
#include "deck.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
	//start on turn 1
	int turn = 1;
	//init cards for assignment later
	Card p1Card, p2Card;
	int p1Suit, p2Suit;

	//read in names and instantiate players
	string name = "";
	int seed;
	ifstream something;
	//for file output stuff
	ostream os;
	something >> name;
	Player p1(name);
	name = "";
	something >> name;
	Player p2(name);

	//get and set random seed
	something >> seed;
	srand(seed);

	//init deck
	Deck deck;

	//print deck
	os << deck;

	//now shuffle then print again
	deck.Shuffle();
	os << deck;

	//draw 3 cards for each player
	for(int i = 0; i < 3; i++)
	{
		p1.drawCard(deck);
		p2.drawCard(deck);
	}

	//now play
	while(!deck.isEmpty())
	{
		//pre-turn
		//print turn#, player name, cards, and score
		std::cout << turn << ")  ";
		std::cout << p1.getName() << "  ";
		os << p1;
		std::cout << "(" << p1.getScore() << ") - ";
		std::cout << p2.getName() << "  ";
		os << p2;
		std::cout << "(" << p2.getScore() << ")\n";

		//now play
		p1Card = p1.playCard();
		p2Card = p2.playCard();

		if(p1Card > p2Card)
		{
			p1.addScore(p1Card);
			p1.addScore(p2Card);
		}
		else if(p1Card < p2Card)
		{
			p2.addScore(p1Card);
			p2.addScore(p2Card);
		}
		//now check suits
		else
		{
			//god why did i do this
			if(p1Card.getSuit == diamonds)
			{
				p1Suit = 4;
			}
			else if(p1Card.getSuit == spades)
			{
				p1Suit = 3;
			}
			else if(p1Card.getSuit == spades)
			{
				p1Suit = 2;
			}
			else
			{
				p1Suit = 1;
			}
			//make it stop
			if(p2Card.getSuit == diamonds)
			{
				p2Suit = 4;
			}
			else if(p2Card.getSuit == spades)
			{
				p2Suit = 3;
			}
			else if(p2Card.getSuit == spades)
			{
				p2Suit = 2;
			}
			else
			{
				p2Suit = 1;
			}

			//finally over
			if(p1Suit > p2Suit)
			{
				p1.addScore(p1Card);
				p1.addScore(p2Card);
			}
			else
			{
				p2.addScore(p1Card);
				p2.addScore(p2Card);
			}
		}
		
		//post-turn print
		std::cout << turn << ")  ";
		std::cout << p1.getName() << "  ";
		os << p1;
		std::cout << "(" << p1.getScore() << ") - ";
		std::cout << p2.getName() << "  ";
		os << p2;
		std:cout << "(" << p2.getScore() << ")\n";
		//draw back to 3
		p1.drawCard(deck);
		p2.drawCard(deck);
	}
	//end of game printing now 
	if(p1.getScore() > p2.getScore())
	{
		std::cout << "Winner: " << p1.getName() << " " << p1.getScore() << std::endl; 
	}
	else if(p1.getScore() < p2.getScore())
	{
		std::cout << "Winner: " << p2.getName() << " " << p2.getScore() << std::endl; 		
	}
	else
	{
		std::cout << "Tie " << p1.getScore() << std::endl;
	}
}