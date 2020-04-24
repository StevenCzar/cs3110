#include "card.h"
#include "priorityqueue.h"
#include <algorithm>

Card heartsDeck[13];
Card spadesDeck[13];
PriorityQueue<Card> plswork;

for(int i = 0; i<13; i++)
{
	heartsDeck[i] = Card(i, hearts);
	spadesDeck[i] = Card(i, spades);
}

std::random_shuffle(std::begin(heartsDeck), std::end(heartsDeck));   // hearts is an array name
std::random_shuffle(std::begin(spadesDeck), std::end(spadesDeck));   // spades is an array name

for(int i=0; i<13; i++)
{
	plswork.enqueue(spadesDeck[i]);
	plswork.print();
}

for(int i=0; i<13; i++)
{
	plswork.dequeue(i);
}

for(int i=0; i<13; i++)
{
	plswork.enqueue(heartsDeck[i]);
	plswork.print();
}
