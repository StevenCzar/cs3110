#include "card.h"
#include "priorityqueue.h"

Card hearts[13], spades[13];
Priorityqueue plswork;

for(int i = 0; i<13; i++)
{
	hearts[i] = Card(i, hearts);
	spades[i] = Card(i, spades);
}

std::random_shuffle(std::begin(hearts), std::end(hearts));   // hearts is an array name
std::random_shuffle(std::begin(spades), std::end(spades));   // spades is an array name

for(i=0; i<13; i++)
{
	plswork.enqueue(spades[i]);
	plswork.print();
}

for(i=0; i<13; i++)
{
	plswork.dequeue(i);
}

for(i=0; i<13; i++)
{
	plswork.enqueue(hearts[i]);
	plswork.print();
}
