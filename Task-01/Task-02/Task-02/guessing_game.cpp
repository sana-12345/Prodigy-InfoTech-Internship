#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));               // Seed for random number
    int number = rand() % 100 + 1; // Random number between 1 and 100
    int guess, attempts = 0;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "Guess a number between 1 and 100" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > number) {
            cout << "Too high! Try again." << endl;
        } else if (guess < number) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number correctly." << endl;
            cout << "Number of attempts: " << attempts << endl;
        }
    } while (guess != number);

    cout << "\nPRODIGY INFOTECH" << endl;
    return 0;
}
