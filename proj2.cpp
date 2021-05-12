
#include <iostream>
#include "gaspump.h"
#include <fstream>

//Function Name: Main
//Purpose: the driver function
int main()
{
    int randSeed, numOfVehicles;
    std::string fuel;
    double price;
    std::ifstream inFile; //Read from gas.txt
    inFile.open("gas.txt"); //Read from gas.txt

    GasPump *gasPumpPtr[3]; // Declare an array of pointers to 3 GasPump objects

    if(inFile) //if file is open
    {
        inFile >> randSeed >> numOfVehicles; //read in random seed, number of vehicles

        for (int i = 0; i < 3; i++)
        {
            inFile >> fuel >> price;
            gasPumpPtr[i] = new GasPump(fuel, price);
        }



        srand(randSeed); //generate random number

        std::cout << std::fixed; //set these for output to be formatted properly
        std::cout.precision(2);
        //for loop for the number of vehicles to be simulated - one vehicle per iteration:
        for (int i = 0; i < numOfVehicles ; i++)
        {
            //draw a random integer with rand and mod it by 3.
            int index = rand() % 3;

            //select random values from [25,50], increments of 5
            //by drawing random int, % 6, * result by 5, then add 25
            int randValue = (((rand() % 6) * 5) + 25);

            //Use the pointer at the index to invoke the dispenseFuel function in the appropriate pump
            //Output // Vehicle #, fuel type, price per gallon, purchase amount, gallons received.
            std::cout << (i + 1) << " " <<
                      gasPumpPtr[index]->getDispenseFuel() << " " <<
                      gasPumpPtr[index]->getFuelPerGallon() << " " << (double)randValue << " " <<
                      gasPumpPtr[index]->dispenseFuel(randValue) << std::endl;
        }
        //Upon exiting the loop, output the total fuel dispensed and total revenue collected for each pump (in order)
        for (auto & i : gasPumpPtr)
        {
            std::cout << i->getDispenseFuel() << " " <<
                      i->getTotalFuelDispensed() << " " <<
                      i->getTotalRevenueEarned() << std::endl;

        }

        std::cout << std::endl; //prints out new line
    }

    inFile.close(); //close the file
    return 0;
}
