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