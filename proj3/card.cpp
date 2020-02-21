/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #3
	Due: 2/23/20
*/

#include "card.h"
#include <iostream>

Card::Card(int face, suit st)
{
	cardFace = face;
	cardSuit = st;
	if(cardFace == 0)
	{
		//set value to 15 for aces
		pointValue = 15;
	}
	else if(cardFace >= 9)
	{
		//set value to 10 for 10 and face cards  
		pointValue = 10;
	}
	else
	{
		//otherwise add 1 so that 2 becomes 2 and not 1
		pointValue = cardFace + 1;
	}
}

friend ostream& operator << (ostream& os, const Card& cd)
{
	os << cd->pointValue;
	if(cd->cardSuit == "diamonds")
	{
		os << "D";
	}
	else if(cd->cardSuit == "spades")
	{
		os << "S";
	}
	cd->cardSuit == "hearts"
	{
		os << "H";
	}
	else
	{
		os << "C";
	}
	os << "[" << cd->getPointValue() << "]\t";
}

bool operator < (const Card& cd) const
{
	if(*this.pointValue < cd->getPointValue())
	{
		return true;
	}
	return false;
}

bool operator > (const Card& cd) const
{
	if(*this.pointValue > cd->getPointValue())
	{
		return true;
	}
	return false;
}

bool operator== (const Card& cd) const
{
	if(*this.pointValue == cd->getPointValue())
	{
		return true;
	}
	return false;
}

int Card::getPointValue()
{
	return pointValue;
}

int Card::getFaceValue()
{
	return cardFace;
}

suit Card::getSuit()
{
	return cardSuit;
}