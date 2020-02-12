#include "gaspump.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//create array of pointers for pumps
	GasPump *pump[3];
	string s;
	int seed, num_cars;
	double capacity, cost, percentage[3];
	//read in data
	ifstream something;
	cout << "what";
	something.open("gas.txt");
	cout << " about here?";
	cin >> seed >> num_cars;
	cout << seed << endl << num_cars << endl;
	for(int j=0; j<3; j++)
	{
		cin >> s >> capacity >> cost >> percentage[j];
		cout << s << " " << capacity << " " << cost << " " << percentage[j] << endl;
		pump[0] = new GasPump(s,capacity,cost);
	}
	//declare car array for dispenseFuel
	double car[2];
	int index;
	//set random seed
	srand(seed);
	//lets try this
	for(int i=0; i<num_cars; i++)
	{
		//reusing variables is bad but oh well
		cost = (((rand()%6)*5)+30);
		capacity = (double)rand()/RAND_MAX;
		//if the value is in q1
		if(capacity <= percentage[3])
		{
			index = 2;
		}
		//if the value is in q2
		else if((capacity > percentage[3])&&(capacity <= (percentage[2]+percentage[3])))
		{
			index = 1;
		}
		//if the value is in q3
		else
		{
			index = 0;
		}
		//dispense the fuel and print the results
		pump[index]->dispenseFuel(car,cost);
		cout << i+1 << " " << pump[index]->Fuel_type() << " " << pump[index]->Price() << " " << car[0] << " " << car[1] << " " << car[1]*pump[index]->Price() << " " << pump[index]->Ava_Fuel() << endl;
	}
	return 0;
}
