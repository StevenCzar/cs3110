/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #3
	Due: 2/23/20
*/

#include "card.h"
#include "deck.h"
#include <iostream>
#include <algorithm>

Deck::Deck()
{
	//fill theDeck with cards
	int j = 0;
	for(int i=0; i<13; i++)
	{
		theDeck[j] = Card(i, clubs);
		j++;
	}
	for(int i=0; i<13; i++)
	{
		theDeck[j] = Card(i, hearts);
		j++;
	}
	for(int i=0; i<13; i++)
	{
		theDeck[j] = Card(i, spades);
		j++;
	}
	for(int i=0; i<13; i++)
	{
		theDeck[j] = Card(i, diamonds);
		j++;
	}
	//set top card to be the first in array
	topCard = 0;
}

Card Deck::dealCard()
{
	//move top card to next
	topCard++;
	//returns the 'card on top of the new top card'
	return theDeck[topCard-1];

}

void Deck::Shuffle()
{
	//use random_shuffle
	std::random_shuffle(std::begin(theDeck),std::end(theDeck));
	return;
}

bool Deck::isEmpty()
{
	//if the top card is now past the size...
	if(topCard==numCards)
	{
		return true;
	}
	return false;
}

std::ostream& Deck::operator << (std::ostream& os, const Deck& dk)
{
	for(int j = 0; j < 4; j++)
	{
		for(int i = 0; i < 13; i++)
		{
			std::cout << dk.theDeck[i].operator<<;
		}
		std::cout << std::endl;
	}
	return os;
}