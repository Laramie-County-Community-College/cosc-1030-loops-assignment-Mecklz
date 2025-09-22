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

char token;

int main(){
    
    std::srand(std::time(0));
    while (token != 'x') {
        std::cout << "Let's guess a number, eh?\n";
        int number = (rand()%100)+1;
        int guess = 0;
        while(true) {
            // I tested so many ways of doing this and finally discovered that, unlike python, cin <int>
            // will only buffer <int> and will set a failed state (thanks ai) if not <int> is entered 
            // and will not re-attempt until its reset. Still feels like cheating. I'll grow up someday.
            while (true) {
                guess = 0;
                std::cout << "\nPlease pick a number from 1-100: ";
                std::cin >> guess;  // Fills input buffer with the guess and a damned \n

                // check to see cin failbit set to 1
                if (std::cin.fail()) {
                    std::cout << "\nYour entry contained invalid characters. Try again.\n";
                    std::cin.clear(); // Sets failbit to 0
                    std::cin.ignore(1000,'\n'); // Clears the buffer
                } else {break;}
            }
            // Number check
            if (guess == number){
                break;
            } else if (guess < number) {
                std::cout << "\nToo low. Try again.\n";
            } else if (guess > number) {
                std::cout << "\nToo high. Try again.\n";
            } else {
                std::cout << "\nSomething went wrong. Try again.\n"; // This was a debug trap that never sprung
            }
            std::cin.ignore(1000,'\n'); // This is to clear the buffer in case ints were entered separated by illegal chars
            
            // Debug lines
            // std::cout << "\nGuess: " << guess << "\nNumber: " << number << "\nToken: " << token;
        }
        std::cout << "WAY TO GO! Press enter to play again or 'x' and enter to quit: ";

        // Heres a thing. cin.get take exactly the first char(even whitespace) and cin.ignore
        // ignores (max chars in buffer, until this delimiter). Since the only input that matters 
        // here is 'x', I won't worry about dealing with possible leading whitespace in the cin
        std::cin.ignore(1000,'\n'); // ALSO CLEARS THE BUFFER
        std::cin.get(token);      
    }
    
    return 0;
}