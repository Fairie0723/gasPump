

//must include #include guards
#ifndef GASPUMP_H
#define GASPUMP_H

#include <iostream>
//Class Name: GasPump
//Purpose: to provide security, and objects to the program
class GasPump
{
private:
//A string containing the type of gas the gas pump holds
std::string gasType;
//A double that holds the price per gallon
double pricePerGallon;
//A double representing the total amount of fuel dispensed (all purchases)
double totalFuelDispensed;
//A double that stores the total amount of money collected (all purchases)
double totalMoneyEarned;


//Must have these public members
public:
GasPump(std::string, double);
//An inline accessor function that returns a standard string for the pump’s fuel type
 std::string getDispenseFuel() const
    { return gasType; }
//An inline accessor function that returns a double for the pump’s fuel price per gallon
double getFuelPerGallon() const
    { return pricePerGallon; }
//An inline accessor function that returns the total amount of fuel dispensed (all purchases)
    double getTotalFuelDispensed() const
    { return totalFuelDispensed; }
//An inline accessor function that returns the total amount of revenue collected (all purchases)
double getTotalRevenueEarned() const
    { return totalMoneyEarned; }
//A function dispenseFuel, that dispenses fuel to vehicles.
double dispenseFuel(double);



};


//#include guards
#endif