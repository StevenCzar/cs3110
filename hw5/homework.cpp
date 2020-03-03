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
		vec.clear();
	}
	cout << "Average time taken for a: " << average/5.0 << endl;
	average = 0;

	//section for b
	list<int> ls;
	for(int j = 0; j<5; j++)
	{
		timerStart = clock();

		for(int i = 0; i < 1000000; i++)
		{
			ls.push_front(rand());
		}

		timerEnd = clock();
		average += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;
		ls.clear();
	}
	cout << "Average time taken for b: " << average/5.0 << endl;
	average = 0;
	//section for c
	forward_list<int> fls;
	for(int j = 0; j<5; j++)
	{
		timerStart = clock();

		for(int i = 0; i < 1000000; i++)
		{
			fls.push_front(rand());
		}

		timerEnd = clock();

		average += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;
		fls.clear();
	}
	cout << "Average time taken for c: " << average/5.0 << endl;
	average = 0;
	//section for d-push
	double average2 = 0;
	stack<int> stack1;
	for(int j = 0; j<5; j++)
	{
		timerStart = clock();

		for(int i = 0; i < 1000000; i++)
		{
			stack1.push(rand());
		}

		timerEnd = clock();

		average += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;

		timerStart = clock();
		for(int i = 0; i < 500000; i++)
		{
			stack1.pop();
		}
		timerEnd = clock();

		average2 += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;
		stack1.clear();
	}
	cout << "Average time taken for d-push: " << average/5.0 << endl;
	average = 0;
	cout << "Average time taken for d-pop: " << average2/5.0 << endl;
	average2 = 0;

	//section for e
	stack<int,vector<int>> stack2;
	for(int j = 0; j<5; j++)
	{
		timerStart = clock();

		for(int i = 0; i < 1000000; i++)
		{
			stack2.push(rand());
		}

		timerEnd = clock();

		average += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;

		timerStart = clock();
		for(int i = 0; i < 500000; i++)
		{
			stack2.pop();
		}
		timerEnd = clock();

		average2 += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;
		stack2.clear();
	}
	cout << "Average time taken for e-push: " << average/5.0 << endl;
	average = 0;
	cout << "Average time taken for e-pop: " << average2/5.0 << endl;
	average2 = 0;
	//section for f
	stack<int,list<int>> stack3;
	for(int j = 0; j<5; j++)
	{
		timerStart = clock();

		for(int i = 0; i < 1000000; i++)
		{
			stack3.push(rand());
		}

		timerEnd = clock();

		average += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;

		timerStart = clock();
		for(int i = 0; i < 500000; i++)
		{
			stack3.pop();
		}
		timerEnd = clock();

		average2 += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;
		stack3.clear();
	}
	cout << "Average time taken for f-push: " << average/5.0 << endl;
	average = 0;
	cout << "Average time taken for f-pop: " << average2/5.0 << endl;
	average2 = 0;

	//section for g
	queue<int> queue1;
	for(int j = 0; j<5;j++)
	{
		timerStart = clock();

		for(int i = 0; i < 1000000; i++)
		{
			queue1.push(rand());
		}

		timerEnd = clock();

		average += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;

		timerStart = clock();
		for(int i = 0; i < 500000; i++)
		{
			queue1.pop();
		}
		timerEnd = clock();

		average2 += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;
		queue1.clear();
	}
	cout << "Average time taken for g-push: " << average/5.0 << endl;
	average = 0;
	cout << "Average time taken for g-pop: " << average2/5.0 << endl;
	average2 = 0;
	//section for h
	deque<int> queue2;
	for(int j=0; j<5; j++)
	{
		timerStart = clock();

		for(int i = 0; i < 1000000; i++)
		{
			queue2.push_back(rand());
		}

		timerEnd = clock();

		average1 += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;

		timerStart = clock();
		for(int i = 0; i < 500000; i++)
		{
			queue2.pop_front();
		}
		timerEnd = clock();

		average2 += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;
		queue2.clear();
	}
	cout << "Average time taken for h-push: " << average/5.0 << endl;
	average = 0;
	cout << "Average time taken for h-pop: " << average2/5.0 << endl;
	average2 = 0;
	//section for i
	queue<int,list<int>> queue3;
	for(int j=0; j<5; j++)
	{
		timerStart = clock();

		for(int i = 0; i < 1000000; i++)
		{
			queue3.push(rand());
		}

		timerEnd = clock();

		average += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;

		timerStart = clock();
		for(int i = 0; i < 500000; i++)
		{
			queue3.pop();
		}
		timerEnd = clock();

		average2 += (timerEnd-timerStart)*1.0/CLOCKS_PER_SEC;
		queue3.clear();
	}
	cout << "Average time taken for i-push: " << average/5.0 << endl;
	average = 0;
	cout << "Average time taken for i-pop: " << average2/5.0 << endl;
	average2 = 0;
}