#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
#include <vector>

using namespace std;

void guess(int N)
{
    int number, guess, numberofguess = 0;
    string name;
    // Seed the random number generator with the current time
    srand(time(nullptr));

    number = rand() % N;

    cout << "============================================  SIMPLE NUMBER GUESSING GAME  =============================================" << endl << endl;
    cout << "                                  *** A Project By : PEASH DAS RUDRA, CSE NUBTK ***" << endl << endl << endl << endl;
    cout << "WELCOME To The NUMBER GUESSING GAME..." << endl << endl << endl;
    cout << "Please Enter Your Name to Continue : "<< endl;

            cin >> name;
            cout << endl;

    cout << name << ", You Have to Guess the Correct Number in Lowest Possible Attempts. Remember You HAVE 5 ATTEMPTS ONLY !!!"<< endl << endl << endl;
    cout << "3...2...1... LETS PLAY "<< endl << endl << endl;
    cout << "Guess a number between 1 and " << N << "." << endl;

    do {
        if (numberofguess > 5) {
            cout << "\nBETER LUCK NEXT TIME " << name <<":)" << endl;
            cout << "The Correct Number Was " << number << endl;
            break;
        }

        cin >> guess;

        if (guess > number) {
            cout << "Lower number please!" << endl;
            numberofguess++;
        }
        else if (number > guess) {
            cout << "Higher number please!" << endl;
            numberofguess++;
        }
        else {
            cout << endl << endl << "CONGRATULATIONS " << name <<" !!! The Correct Number is " << number << endl;
            cout << "You guessed the number in " << numberofguess << " attempts!" << endl;

        }

    } while (guess != number);
}

int main()
{
    int N = 100;

    guess(N);

    return 0;
}

