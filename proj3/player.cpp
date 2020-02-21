/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #3
	Due: 2/23/20
*/

#include "player.h"

Player::Player(string pname="unknown")
{
	name = pname;
	score = 0;
	//dummy init for card draw
	for(int i = 0; i < Max_Cards; i++)
	{
		hasPlayed[i] = true;
	}
}

Card Player::playCard()
{
	//compare cards 1-2, 2-3, and 1-3, play highest value
	
	//remove played card by...
	//setting hasPlayed to true
	hasPlayed[i] = true;
}

//draw card from deck array
void Player::drawCard(Deck& dk)
{
	for(int i = 0; i < Max_Cards; i++)
	{
		//check to see which card was just played
		//also make sure deck isn't empty
		if((hasPlayed[i] == true)&&(!(dk->isEmpty())))
		{
			//deal card and set hasPlayed to false
			hand[i] = dk->dealCard();
			hasPlayed[i] = false;
			//exit here so it will alternate on init
			return;
		}
	}
}

void Player::addScore(Card acard)
{
	score += acard.getPointValue();
	return;
}

int Player::getScore()
{
	return score;
}

string Player::getName()
{
	return name;
}

bool Player::emptyHand()
{
	for(int i = 0; i < Max_Cards; i++)
	{
		//check if player has unplayed cards
		if(hasPlayed[i] == false)
		{
			something = false;
		}
	}
	//otherwise hand is empty
	return true;
}