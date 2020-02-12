#include "gaspump.h"
#include <iostream>
//constructor to set gaspump init values
GasPump::GasPump(std::string s, double cap, double price)
{
	gas_type = s;
	fuel_cap = cap;
	ppg = price;
	turn_away = false;
	fuel_oh = fuel_cap;
	tot_amt_fuel = 0;
	tot_amt_sales = 0;
}

//puts fuel onhand back to the cap
void GasPump::replenish()
{
	fuel_oh = fuel_cap;
}

//Dispenses fuel and determines if it needs to refuel
void GasPump::dispenseFuel(double *a, double amt)
{
	std::cout << tot_amt_sales << std::endl;
	//convert to amount of gallons
	amt = amt/ppg;
	//if the pump is not replenishing...
	if(turn_away)
	{
		replenish();
		turn_away = false;
	}	
	//if the pump is replenishing, allow next customer to go
	else
	{
		//if the amount is greater than onhands...
		if(amt > fuel_oh)
		{
			a[0] = amt*ppg;
			//give them the rest
			amt = fuel_oh;
			a[1] = amt*ppg;
			fuel_oh = 0;
			//update pump stats
			tot_amt_fuel += amt;
			tot_amt_sales += (amt*ppg);
		}
		//if the amount is within onhands
		else
		{
			a[0] = amt*ppg;
			a[1] = amt*ppg;
			//give them the amount they want
			fuel_oh -= amt;
			//update pump stats
			tot_amt_fuel += amt;
			tot_amt_sales += (amt*ppg);
		}
		//check to see if it needs to be replenished
		if(fuel_oh < (fuel_cap*.10))
		{
			a[0] = amt*ppg;
			a[1] = 0;
			replenish();
			turn_away = true;
		}
	}
}