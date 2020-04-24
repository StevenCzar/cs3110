/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #7
	Due: 4/24/20
*/
#include "card.h"
#include "priorityqueue.h"
#include <algorithm>
#include <fstream>


int main()
{
	//make things
	Card heartsDeck[13];
	Card spadesDeck[13];
	PriorityQueue<Card, lessThan<Card>> lowprio;
	PriorityQueue<Card, greaterThan<Card>> highprio;

	std::fstream something;
	int seed;

	//init things
	for(int i = 0; i<13; i++)
	{
		heartsDeck[i] = Card(i, hearts);
		spadesDeck[i] = Card(i, spades);
	}

	something.open("pqseed.txt");
	something >> seed;
	srand(seed);

	//shuffle things
	std::random_shuffle(std::begin(heartsDeck), std::end(heartsDeck));   // hearts is an array name
	std::random_shuffle(std::begin(spadesDeck), std::end(spadesDeck));   // spades is an array name

	//enqueue high priority
	for(int i=0; i<13; i++)
	{
		highprio.enqueue(spadesDeck[i]);
		highprio.print();
	}
	std::cout << "\n";

	//dequeue high priority
	for(int i=0; i<13; i++)
	{
		highprio.dequeue();
		highprio.print();
	}
	std::cout << "Max Heap Empty\n";

	//same as before
	for(int i=0; i<13; i++)
	{
		lowprio.enqueue(heartsDeck[i]);
		lowprio.print();
	}
	std::cout << "\n";

	//same as before
	for(int i=0; i<13; i++)
	{
		lowprio.dequeue();
		lowprio.print();
	}

	std::cout << "Min Heap Empty\n";
}