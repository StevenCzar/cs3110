/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #1
	Due: 1/30/20
*/
#include <fstream>

using namespace std;

int * allocateArray(int *arr, int *size, double inc);
double calcAvg(int *arr, int size);

int main()
{
	int array[];
	int size;
	double average, inc;
	fstream something, otherthing;
	something.open("nums.txt");
	otherthing.open("out.txt");
	something >> size;

	//validate size
	//if size is outside the boundaries or not a multiple of 50, output error and don't run rest of program
	if((size < 100) || (size > 350) || !(size % 50))
	{
		cout << "Error\n"; 
	}
	else
	{
		something >> inc;
		while(something)
		{
			cout << size << endl;
			array = allocateArray(array, size, inc);
			average = calcAvg(array, size);
			cout << size << " " << average << endl;
			otherthing << size << " " << average << endl;
		}
	}
}

int * allocateArray(int *arr, int *size, double inc)
{
	size += (size*inc);

}

double calcAvg(int *arr, int size)
{
	double avg = 0;
	for(int i=0; i<size; i++)
	{
		avg += arr[i];
	}
	return (avg/size);
}