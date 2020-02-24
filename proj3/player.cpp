/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #3
	Due: 2/23/20
*/

#include "player.h"

Player::Player(string pname)
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
	if((hand[0] > hand[1])&&(hand[0]>hand[2]))
	{
		hasPlayed[0] = true;
		return hand[0];
	}
	else if((hand[1] > hand[2])&&(hand[1]>hand[0]))
	{
		hasPlayed[1] = true;
		return hand[1];
	}
	else if((hand[2] > hand[1])&&(hand[2] > hand[0]))
	{
		hasPlayed[2] = true;
		return hand[2];
	}
	return hand[0];
}

//draw card from deck array
void Player::drawCard(Deck& dk)
{
	for(int i = 0; i < Max_Cards; i++)
	{
		//check to see which card was just played
		//also make sure deck isn't empty
		if((hasPlayed[i] == true)&&(!(dk.isEmpty())))
		{
			//deal card and set hasPlayed to false
			hand[i] = dk.dealCard();
			hasPlayed[i] = false;
			//exit here so it will alternate on init
			return;
		}
	}
	return;
}

void Player::addScore(Card acard)
{
	score += acard.getPointValue();
	return;
}

int Player::getScore() const
{
	return score;
}

string Player::getName() const
{
	return name;
}

bool Player::emptyHand() const
{
	bool something = true;
	for(int i = 0; i < Max_Cards; i++)
	{
		//check if player has unplayed cards
		if(hasPlayed[i] == false)
		{
			//if they have any unplayed cards, set false
			something = false;
		}
	}
	//return if they have cards or not
	return something;
}

ostream& operator << (ostream& os, const Player& p);
{
	for(int i = 0; i < 3; i++)
	{
		if(hasPlayed[i] == false)
		{
			os << hand[i] << "  ";
		}
		else
		{
			os << "_____  ";
		}
	}
}