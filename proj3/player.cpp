/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #3
	Due: 2/23/20
*/

#include "player.h"
#include <string>

Player::Player(std::string pname)
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
	//oh no here i go making it difficult again
	int h1Suit, h2Suit;
	//if A > B ...
	if(hand[0] > hand[1])
	{
		//comp A-C
		if(hand[0] > hand[2])
		{
			//play A
			hasPlayed[0] = true;
			return hand[0];
		}
		else if(hand[0] < hand[2])
		{
			//play C
			hasPlayed[2] = true;
			return hand[2];
		}
		else
		{
			//comp A-C suit
			if(hand[0].getSuit() == diamonds)
			{
				h1Suit = 4;
			}
			else if(hand[0].getSuit() == spades)
			{
				h1Suit = 3;
			}
			else if(hand[0].getSuit() == hearts)
			{
				h1Suit = 2;
			}
			else
			{
				h1Suit = 1;
			}
			//make it stop
			if(hand[2].getSuit() == diamonds)
			{
				h2Suit = 4;
			}
			else if(hand[2].getSuit() == spades)
			{
				h2Suit = 3;
			}
			else if(hand[2].getSuit() == hearts)
			{
				h2Suit = 2;
			}
			else
			{
				h2Suit = 1;
			}

			//finally over
			if(h1Suit > h2Suit)
			{
				//play A
				hasPlayed[0] = true;
				return hand[0];
			}
			else
			{
				//play C
				hasPlayed[2] = true;
				return hand[2];
			}
		}
	}
	else if(hand[0] < hand[1])
	{
		//comp B-C
		if(hand[1] > hand[2])
		{
			//play B
			hasPlayed[1] = true;
			return hand[1];
		}
		else if(hand[1] < hand[2])
		{
			//play C
			hasPlayed[2] = true;
			return hand[2];
		}
		else
		{
			//comp B-C suit
			if(hand[1].getSuit() == diamonds)
			{
				h1Suit = 4;
			}
			else if(hand[1].getSuit() == spades)
			{
				h1Suit = 3;
			}
			else if(hand[1].getSuit() == hearts)
			{
				h1Suit = 2;
			}
			else
			{
				h1Suit = 1;
			}
			//make it stop
			if(hand[2].getSuit() == diamonds)
			{
				h2Suit = 4;
			}
			else if(hand[2].getSuit() == spades)
			{
				h2Suit = 3;
			}
			else if(hand[2].getSuit() == hearts)
			{
				h2Suit = 2;
			}
			else
			{
				h2Suit = 1;
			}

			//finally over
			if(h1Suit > h2Suit)
			{
				//play B
				hasPlayed[1] = true;
				return hand[1];
			}
			else
			{
				//play C
				hasPlayed[2] = true;
				return hand[2];
			}
		}
	}
	else
	{
		//comp A-C
		if(hand[0] > hand[2])
		{
			//comp A-B suit
			if(hand[0].getSuit() == diamonds)
			{
				h1Suit = 4;
			}
			else if(hand[0].getSuit() == spades)
			{
				h1Suit = 3;
			}
			else if(hand[0].getSuit() == hearts)
			{
				h1Suit = 2;
			}
			else
			{
				h1Suit = 1;
			}
			//make it stop
			if(hand[1].getSuit() == diamonds)
			{
				h2Suit = 4;
			}
			else if(hand[1].getSuit() == spades)
			{
				h2Suit = 3;
			}
			else if(hand[1].getSuit() == hearts)
			{
				h2Suit = 2;
			}
			else
			{
				h2Suit = 1;
			}

			//finally over
			if(h1Suit > h2Suit)
			{
				//play A
				hasPlayed[0] = true;
				return hand[0];
			}
			else
			{
				//play B
				hasPlayed[1] = true;
				return hand[1];
			}
		}
		else if(hand[0] < hand[2])
		{
			//play C
			hasPlayed[2] = true;
			return hand[2];
		}
		else
		{
			//all suits are the same god help you
			//not trying this just play the first card
			hasPlayed[0] = true;
			return hand[0];
		}
	}
	//if this doesn't work somehow... just play first card
	hasPlayed[0] = true;
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

ostream& operator << (ostream& os, const Player& p)
{
	for(int i = 0; i < 3; i++)
	{
		if(p.hasPlayed[i] == false)
		{
			os << p.hand[i] << "  ";
		}
		else
		{
			os << "_____  ";
		}
	}
	return os;
}