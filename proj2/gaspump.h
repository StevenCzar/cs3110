/* 	Steven Czarnecki
	CSCI 3110 - 001
	Project #2
	Due: 2/11/20
*/
#ifndef GASPUMP_H
#define GASPUMP_H

#include <string>

class GasPump {
	private:
		std::string gas_type;
		double fuel_oh, fuel_cap, ppg, tot_amt_fuel, tot_amt_sales;
		bool turn_away;
		void replenish();
	public:
		GasPump(std::string, double, double);
		std::string Fuel_type() {return gas_type;}
		double Price() {return ppg;}
		double Ava_Fuel() {return fuel_oh;}
		double Fuel_disp() {return tot_amt_fuel;}
		double Tot_sales() {return tot_amt_sales;}
		void dispenseFuel(double*, double);
};
#endif