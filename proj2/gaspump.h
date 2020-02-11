#ifndef GASPUMP_H
#define GASPUMP_H

class GasPump {
	private:
		string gas_type;
		double fuel_oh, fuel_cap, ppg, tot_amt_fuel, tot_amt_sales;
		bool turn_away;
		void replenish(GasPump);
	public:
		GasPump(string, double, double);
		string Fuel_type() {return gas_type;}
		double Price() {return ppg;}
		double Ava_Fuel() {return fuel_oh;}
		double Fuel_disp() {return tot_amt_fuel;}
		double Tot_sales() {return tot_amt_sales;}
		void dispenseFuel(double*, double);
};
#endif