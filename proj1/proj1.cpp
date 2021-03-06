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
	//declare file i/o variables and open
	ifstream something;
	ofstream otherthing;
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
		//outputs initial size		
		cout << size << endl;
		otherthing << size << endl;
		something >> inc;
		//declare loop control variable
		int i = 0;
		//while reading file...
		while(something)
		{
			//create or increase size of array
			array = allocateArray(array, &size, inc);
			//print size of array
			cout << size << " ";
			otherthing << size << " ";
			//skip init and use for loop such that the counter persists through size increases
			//multiple conditions so loop can terminate via reaching end of size or end of read-in
			for(; ((i < size)&&(something)); i++)
			{
				something >> array[i];
			}
			//if the size is not equal to the counter, first print the total size and then what the array was filled to
			if(i!=size)
			{
				//last run on the for loop causes this value to be larger than expected when reaching EoF
				average = calcAvg(array, i-1);
				cout <<  i-1 << " " << average << endl;
				otherthing << i-1 << " " << average << endl;
			}
			else
			{
				average = calcAvg(array, i);
				cout << average << endl;
				otherthing << average << endl;
			}
		}
	}
	//close files, deallocate array, and exit program
	something.close();
	otherthing.close();
	delete [] array;
	array = NULL;
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
		//delete pointer and set to null
		delete [] arr;
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
//makes a sum and then divides by size of array
double calcAvg(int *arr, int size)
{
	double avg = 0;
	for(int i=0; i<size; i++)
	{
		avg += arr[i];
	}
	return (avg/size);
}