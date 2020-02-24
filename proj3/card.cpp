/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #3
	Due: 2/23/20
*/

#include "card.h"
#include <iostream>

using std::ostream;

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

std::ostream& operator << (std::ostream& os, const Card& cd)
{
	if(cd.pointValue == 15)
	{
		os << "A";
	}
	else if(cd.cardFace == 10)
	{
		os << "J";
	}
	else if(cd.cardFace == 11)
	{
		os << "Q";
	}
	else if(cd.cardFace == 12)
	{
		os << "K";
	}
	else
	{
		os << cd.pointValue;
	}

	if(cd.cardSuit == diamonds)
	{
		os << "D";
	}
	else if(cd.cardSuit == spades)
	{
		os << "S";
	}
	else if(cd.cardSuit == hearts)
	{
		os << "H";
	}
	else
	{
		os << "C";
	}
	os << "[" << cd.getPointValue() << "]  ";

	return os;
}

bool Card::operator < (const Card& cd) const
{
	if(cardFace < cd.getFaceValue())
	{
		if(cardFace==0)
		{
			return false;
		}
		return true;
	}
	return false;
}

bool Card::operator > (const Card& cd) const
{
	//check this first
	if(cardFace > cd.getFaceValue())
	{
		//check ace
		if(cd.getFaceValue()==0)
		{
			return false;
		}
		return true;
	}
	return false;
}

bool Card::operator== (const Card& cd) const
{
	if(pointValue == cd.getPointValue())
	{
		return true;
	}
	return false;
}

int Card::getPointValue() const
{
	return pointValue;
}

int Card::getFaceValue() const
{
	return cardFace;
}

suit Card::getSuit() const
{
	return cardSuit;
}