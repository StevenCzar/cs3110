/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #7
	Due: 4/24/20
*/

#include "card.h"
#include <iostream>

using std::ostream;

Card::Card(int face, suit st)
{
	cardFace = face+1;
	cardSuit = st;
}

std::ostream& operator << (std::ostream& os, const Card& cd)
{
	if(cd.cardFace == 1)
	{
		os << "A";
	}
	else if(cd.cardFace == 11)
	{
		os << "J";
	}
	else if(cd.cardFace == 12)
	{
		os << "Q";
	}
	else if(cd.cardFace == 13)
	{
		os << "K";
	}
	else
	{
		os << cd.cardFace;
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
	os << "[" << cd.cardFace << "]  ";

	return os;
}

bool Card::operator <= (const Card& cd) const
{
	if(cardFace <= cd.getFaceValue())
	{
		return true;
	}
	return false;
}

bool Card::operator >= (const Card& cd) const
{
	//check this first
	if(cardFace >= cd.getFaceValue())
	{
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