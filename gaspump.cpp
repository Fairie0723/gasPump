

//preprocessor directives
#include "gaspump.h"
#include <iostream>


//Name: Constructor GasPump
//Purpose: to allow the private data members to be used
GasPump::GasPump(std::string fuel, double price)
{
    this->gasType = fuel;
    this->pricePerGallon = price;
    totalFuelDispensed = 0;
    totalMoneyEarned = 0;

    
}
//Function name: dispenseFuel
//Purpose: to take in the amount of money the user is spending
//         divide it by the price per gallon to get the amount of
//         gallons pumped. It also keeps a running total of the total
//         fuel dispensed and total money earned.
double GasPump::dispenseFuel(double purchaseAmount)
{
    //convert purchase amount to gallons of fuel
    double gallons = (purchaseAmount / pricePerGallon);

    //Accumulates total fuel dispensed
    totalFuelDispensed += gallons;

    //Accumulates total revenue collected
    totalMoneyEarned += purchaseAmount;

    //Returns the number of gallons vehicle received (double)
    return gallons;
}

