#include "card.h"
#include "priorityqueue.h"
#include <algorithm>


int main()
{
	Card heartsDeck[13];
	Card spadesDeck[13];
	PriorityQueue<Card, lessThan<Card>> lowprio;
	PriorityQueue<Card, greaterThan<Card>> highprio;

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
	std::cout << "\n";

	for(int i=0; i<13; i++)
	{
		highprio.dequeue();
		highprio.print();
	}
	std::cout << "Max Heap Empty\n";

	for(int i=0; i<13; i++)
	{
		lowprio.enqueue(heartsDeck[i]);
		lowprio.print();
	}
	std::cout << "\n";

	for(int i=0; i<13; i++)
	{
		lowprio.dequeue();
		lowprio.print();
	}
	
	std::cout << "Min Heap Empty\n";
}