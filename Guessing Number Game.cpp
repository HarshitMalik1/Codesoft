#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int randomNumber = std::rand() % 100 + 1;
    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Guessing Game!" << std::endl;

    do {
        std::cout << "Enter your guess (between 1 and 100): ";
        std::cin >> userGuess;
        attempts++;
        if (userGuess > randomNumber)
            std::cout << "Too high! Try again." << std::endl;
        else if (userGuess < randomNumber)
            std::cout << "Too low! Try again." << std::endl;
        else
            std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << std::endl;
    } while (userGuess != randomNumber);

    return 0;
}
