/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #7
	Due: 4/24/20
*/
#include "card.h"
#include <vector>

template <typename T, typename C>
class PriorityQueue
{
public:
	PriorityQueue()
	{
		myVec.resize(50);
		size = 0;
	}
	//remove the front element and move everything around
	void dequeue()
	{
		std::cout << "Dequeued " << myVec[0] << '\t';
		myVec[0] = myVec[size-1];
		myVec.pop_back();
		size--;
		heapDown(0);
	}
	//add element to the bottom and move it around some
	void enqueue(T card)
	{ 
		std::cout << "Enqueued " << card << '\t';
		myVec[size] = card;
		size++;
		heapUp(size-1);	
	}
	bool empty()
	{
		if(myVec.empty())
		{
			return true;
		}
		return false;
	}
	void print()
	{
		for(int i = 0; i < size; i++)
		{
			std::cout << myVec[i] << " ";
		}
		std::cout << "\n";
	}
private:
	std::vector<T> myVec;
	C compare;
	int size;
	void heapUp(int index)
	{
		T holder;
		//integer math ensures that it will work
		if(index!=0 && compare.comparison(myVec[index],myVec[(index-1)/2]))
		{
			//swap and move up the ladder
			holder = myVec[(index-1)/2];
			myVec[(index-1)/2] = myVec[index];
			myVec[index] = holder;
			heapUp((index-1)/2);
		}
	}

	void heapDown(int index)
	{	
		int holder;
		T holding;
		//check left child availability and comparison
		if(index*2+1 <= size-1 && compare.comparison(myVec[index*2+1], myVec[index]))
		{
			//if comparison is true, mark compared value for next comparison
			holder = index*2+1;
		}
		else
		{
			//otherwise mark compared value as being opposite 
			holder = index;
		}
		//check right child availability and comparison
		if(index*2+2 <= size-1 && compare.comparison(myVec[index*2+2],myVec[holder]))
		{
			//if comparison is true, mark value
			holder = index*2+2;
		}
		//if no comparisons are true or if there are no children...
		if(holder != index)
		{
			//swap and move to next
			holding = myVec[holder];
			myVec[holder] = myVec[index];
			myVec[index] = holding;
			heapDown(holder);	
		}
	}
};

template <typename T>
class lessThan
{
public:
	bool comparison(T first, T second){return(first<=second);}
};

template <typename T>
class greaterThan
{
public:
	bool comparison(T first, T second){return(first>=second);}
};
