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
	void dequeue()
	{
		std::cout << "Dequeued " << myVec[0] << '\t';
		myVec[0] = myVec[size-1];
		myVec.pop_back();
		size--;
		heapDown(0);
	}
	void enqueue(T card)
	{
		//increment size first so element 1 is 1 for tree math 
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
		if(index*2+1 <= size-1 && compare.comparison(myVec[index], myVec[index*2+1]))
		{
			holder = index*2+1;
		}
		else
		{
			holder = index;
		}
		if(index*2+2 <= size-1 && compare.comparison(myVec[holder],myVec[index*2+2]))
		{
			holder = index*2+2;
		}
		if(holder != index)
		{
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
