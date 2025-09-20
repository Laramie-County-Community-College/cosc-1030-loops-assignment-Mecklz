/*
https://github.com/Laramie-County-Community-College/cosc-1030-loops-assignment-Mecklz.git

Complete the following programs; when finished take a screen capture of the output from your running program and package it with your .cpp file. Submit a zipped folder with your work.

1.  Apartment Building

A brand new 16 floor apartment building is wrapping up construction and it is time for the building to start bringing in residents. Each floor can hold a maximum of 6 residents (it's a really pricey building).

Set up a loop to display the number of each floor, and ask the user how many apartments are occupied. Do not accept numbers greater than 6 for the number of occupied apartments.

When the loop is complete have it total up the number of occupied apartments (this should be a running total throughout the loops iterations).

Display the total number of rooms, the number of occupied rooms, the number of unoccupied rooms, and the percentage of occupied rooms, all with appropriate labels and spacing.

NOTE: It is traditional that American buildings do not have a 13th floor!  The loop should skip the entire 13th iteration.

INPUT VALIDATION: Remember not to accept numbers less than 0 or greater than 6 for the number of occupied rooms per floor.

 

2.  Random Number Guessing Game

Write a program that generates a random number between 1 and 100 and asks the user to guess what the number is.  

If the user's guess is higher than the random number, the program should display "Too high, try again."  

If the user's guess is lower than the random number the program should display "Too low, try again."  

The program should use a do-while loop that repeats until the user guesses the number correctly.  

The program should also employ a while loop that keeps track of the number of guesses made by the user and, once the user guesses the number correctly, displays the number of guesses the user made.

*/
#include <iostream>
#include <vector>
#include <iomanip>

int main(){

    // Declare variables
    int floor = 1;
    int occupants = -1;
    int totalOccup = 0;
    std::vector<int> perFloor;

    // Initiate crazy good POR title
    std::cout << "SUPER UBER APARTMENT POINT OF RENTAL" << std::endl << std::endl;

    // Loop user input
    for (floor; floor < 17; floor ++) {

        // Wayside school condition
        if (floor == 13){
            floor ++;
        }

        // This ended up being my first condition (0 > occupants > 6). I hope it works.
        // lol it didn't.
        while (true) {
           std::cout << "Please enter the number of occupants on floor " << floor << ": ";
            std::cin >> occupants;
           if (occupants < 7 and occupants > -1){
            break;
           };
           else{
            std::cout << "\nThere are only 6 rooms per floor.\n";
           }
        }
        // Loading a vector with the occupied amounts with indexes representing each floor
        perFloor.push_back(occupants);
        totalOccup += occupants;
// Display the total number of rooms, the number of occupied rooms, the number of unoccupied rooms, and the percentage of occupied rooms, all with appropriate labels and spacing.
    }
    std::cout << "There are 90 rooms in this building of which " << totalOccup << " rooms are occupied." << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "That means your property is at " << ((static_cast<double>(totalOccup)/90)*100) << "\% occupancy. ";
    std::cout << "\n\n Please press enter to terminate.";
    // std::cin >> occupants;

    return 0;
}
    
