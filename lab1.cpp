/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #1
	Due: 1/30/20
*/
#include <fstream>
#include <iostream>

using namespace std;

int * allocateArray(int *arr, int *size, double inc);
double calcAvg(int *arr, int size);

int main()
{
	int *array = NULL;
	int size;
	double average, inc;
	fstream something, otherthing;
	something.open("nums.txt");
	otherthing.open("out.txt");
	something >> size;

	//validate size
	//if size is outside the boundaries or not a multiple of 50, output error and don't run rest of program
	if((size < 100) || (size > 350) || (size % 50))
	{
		cout << "Error\n"; 
	}
	else
	{
		something >> inc;
		//declare loop control variable
		int i = 0;
		while(something)
		{
			array = allocateArray(array, &size, inc);
			//skip init and use for loop such that the counter persists through size increases
			//multiple conditions so loop can terminate via reaching end of size or end of read-in
			for(; ((i < size)&&(something)); i++)
			{
				something >> array[i];
			}
			//if the size is not equal to the counter, first print the total size and then what the array was filled to
			if(i!=size)
			{
				cout << size << " ";
				otherthing << size << " ";
			}
			average = calcAvg(array, i);
			cout << i << " " << average << endl;
			otherthing << i << " " << average << endl;
		}
	}
	return 0;
}

//allocates space for a new array, copies/deletes the old array if there, returns pointer to new array
int * allocateArray(int *arr, int *size, double inc)
{
	//if array is pointing to something, increase size, allocate new array, copy old array over, then delete old array
	if(arr != NULL)
	{
		*size += (*size*inc);
		int *p = new int[*size];
		for(int i = 0; i < *size; i++)
		{
			p[i] = arr[i];
		}
		delete arr;
		arr = NULL;
		return p;
	}
	//if array is null, allocate new array using initial size
	else
	{
		int *p = new int[*size];
		return p;
	}	
}

//calculates the average from each index in the array
double calcAvg(int *arr, int size)
{
	double avg = 0;
	for(int i=0; i<size; i++)
	{
		avg += arr[i];
	}
	return (avg/size);
}