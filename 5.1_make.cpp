/*

2.  Random Number Guessing Game

Write a program that generates a random number between 1 and 100 and asks the user to guess what the number is.  

If the user's guess is higher than the random number, the program should display "Too high, try again."  

If the user's guess is lower than the random number the program should display "Too low, try again."  

The program should use a do-while loop that repeats until the user guesses the number correctly.  

The program should also employ a while loop that keeps track of the number of guesses made by 

the user and, once the user guesses the number correctly, displays the number of guesses the user made.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    char token = 'g';
    std::srand(std::time(0));
    while (token != 'x') {
        std::cout << "Let's guess a number, eh?\n";
        int number = (rand()%100)+1;
        int guess = 0;
        while(true) {
            // I tested so many ways of doing this and discovered that, unlike python, cin <int>
            // will only buffer <int> and will omit everything else and/or turn it to 0. I left in
            // one of my tries for the message cause I'm stoked it worked.
            while (true) {
                guess = 0;
                std::cout << "Please pick a number from 1-100: ";
                std::cin >> guess;
                if (!static_cast<bool>(guess)) {
                    std::cout << "\nYour entry contained invalid characters. Try again.\n";
                    std::cin.ignore(1000,'\n');
                } else {break;}
            }
            
            if (guess == number){
                break;
            } else if (guess < number) {
                std::cout << "\nToo low. Try again.\n";
            } else if (guess > number) {
                std::cout << "\nToo high. Try again.\n";
            } else {
                std::cout << "\nSomething went wrong. Try again.\n";
            }
            std::cout << "\nGuess: " << guess << "\nNumber: " << number << "\nToken: " << token;
            std::cin.get();
        }
        std::cout << "WAY TO GO! Press any key and enter to play again or 'x' to quit: ";

        // Heres a thing. cin.get take exactly the first char(even whitespace) and cin.ignore
        // ignores (max chars in buffer, until this delimiter). Since the only input that matters 
        // here is anm 'x', I won't worry about dealing with possible leading whitespace in the cin
        std::cin.get(token);
        std::cin.ignore(1000,'\n');
        
    }
    

    return 0;
}