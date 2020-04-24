#include "card.h"
#include "priorityqueue.h"
#include <algorithm>

Card heartsDeck[13];
Card spadesDeck[13];
lessThan<Card> less;
greaterThan<Card> great;
PriorityQueue<Card, less> lowprio;
PriorityQueue<Card, great> highprio;

for(int i = 0; i<13; i++)
{
	heartsDeck[i] = Card(i, hearts);
	spadesDeck[i] = Card(i, spades);
}

std::random_shuffle(std::begin(heartsDeck), std::end(heartsDeck));   // hearts is an array name
std::random_shuffle(std::begin(spadesDeck), std::end(spadesDeck));   // spades is an array name

for(int i=0; i<13; i++)
{
	highprio.enqueue(spadesDeck[i]);
	highprio.print();
}

for(int i=0; i<13; i++)
{
	highprio.dequeue(i);
}

for(int i=0; i<13; i++)
{
	lowprio.enqueue(heartsDeck[i]);
	lowprio.print();
}

for(int i=0; i<13; i++)
{
	lowprio.dequeue(i);
}