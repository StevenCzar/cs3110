#include <time.h>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <forward_list>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	clock_t timerStart, timerEnd;
	double average = 0;
	//section for a
	vector<int> vec;
	for(int j = 0; j<5; j++)
	{
		timerStart = clock();

		for(int i = 0; i < 1000000; i++)
		{
			vec.push_back(rand());
		}

		timerEnd = clock();
		
		average += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;
		cout << "Time taken for a: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;
		vec.clear();
	}
	cout << "Average time taken for a: " << average << endl;
	average = 0;

	//section for b
	list<int> ls;
	timerStart = clock();

	for(int i = 0; i < 1000000; i++)
	{
		ls.push_front(rand());
	}

	timerEnd = clock();

	cout << "Time taken for b: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	//section for c
	forward_list<int> fls;
	timerStart = clock();

	for(int i = 0; i < 1000000; i++)
	{
		fls.push_front(rand());
	}

	timerEnd = clock();

	cout << "Time taken for c: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	//section for d-push
	stack<int> stack1;
	timerStart = clock();

	for(int i = 0; i < 1000000; i++)
	{
		stack1.push(rand());
	}

	timerEnd = clock();

	cout << "Time taken for d-push: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	timerStart = clock();
	for(int i = 0; i < 500000; i++)
	{
		stack1.pop();
	}
	timerEnd = clock();

	cout << "Time taken for d-pop: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	//section for e
	stack<int,vector<int>> stack2;
		timerStart = clock();

	for(int i = 0; i < 1000000; i++)
	{
		stack2.push(rand());
	}

	timerEnd = clock();

	cout << "Time taken for e-push: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	timerStart = clock();
	for(int i = 0; i < 500000; i++)
	{
		stack2.pop();
	}
	timerEnd = clock();

	cout << "Time taken for e-pop: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	//section for f
	stack<int,list<int>> stack3;
		timerStart = clock();

	for(int i = 0; i < 1000000; i++)
	{
		stack3.push(rand());
	}

	timerEnd = clock();

	cout << "Time taken for f-push: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	timerStart = clock();
	for(int i = 0; i < 500000; i++)
	{
		stack3.pop();
	}
	timerEnd = clock();

	cout << "Time taken for f-pop: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	//section for g
	queue<int> queue1;
	timerStart = clock();

	for(int i = 0; i < 1000000; i++)
	{
		queue1.push(rand());
	}

	timerEnd = clock();

	cout << "Time taken for g-push: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	timerStart = clock();
	for(int i = 0; i < 500000; i++)
	{
		queue1.pop();
	}
	timerEnd = clock();

	cout << "Time taken for g-pop: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	//section for h
	deque<int> queue2;
	timerStart = clock();

	for(int i = 0; i < 1000000; i++)
	{
		queue2.push_back(rand());
	}

	timerEnd = clock();

	cout << "Time taken for h-push: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	timerStart = clock();
	for(int i = 0; i < 500000; i++)
	{
		queue2.pop_front();
	}
	timerEnd = clock();

	cout << "Time taken for h-pop: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	//section for i
	queue<int,list<int>> queue3;
	timerStart = clock();

	for(int i = 0; i < 1000000; i++)
	{
		queue3.push(rand());
	}

	timerEnd = clock();

	cout << "Time taken for i-push: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

	timerStart = clock();
	for(int i = 0; i < 500000; i++)
	{
		queue3.pop();
	}
	timerEnd = clock();

	cout << "Time taken for i-pop: " << (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC << endl;

}