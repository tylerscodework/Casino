#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    cout << "\n\n\n\n-------------------------WELCOME TO TYLERS CASINO-------------------------\n\n\n" << endl;
    cout << "-------------------------RULES-------------------------" << endl;
    cout << "1) Don't suck\n";
    cout << "2) Make sure to check your remaining balance before each bet\n";
    cout << "3) If you have a gambling problem please call 888-GAMBLINGPROB\n\n\n";
    cout << "-------------------------GOOD LUCK;)-------------------------\n\n\n";

    struct
    {
        string first_name, last_name;
        int balance, end_balance, bet_amount, num_guess, num_gen, n;
        char response;
    } myStructure;

    // player name
    cout << "Please enter your first name: ";
    cin >> myStructure.first_name;

    cout << "\nPlease enter your last name: ";
    cin >> myStructure.last_name;
    cout << "Welcome, " << myStructure.first_name << " " << myStructure.last_name << "!" << endl;

    // ask for starting balance
    cout << "\nPlease enter your starting balance: $";
    cin >> myStructure.balance;

    do
    {
        start:
        // ask for there bet amount
        cout << "\nPlease enter your bet amount to play: $";
        cin >> myStructure.bet_amount;

        if (myStructure.bet_amount > myStructure.balance)
        {
            cout << "\nYou don't have enough funds for this bet!" << endl;
            goto start;
        }

        // ask for there number guess (1-25)
        cout << "\nGuess a number! (1 - 20): ";
        cin >> myStructure.num_guess;

        // generate random number (1-25)
        myStructure.n = 20;

        for (int i = 0; i <= 20; ++i)
        {
            myStructure.n = rand() % 20;
            break;
        }

        if (myStructure.num_guess == myStructure.n)
        {
            // display if they win or lose
            cout << "\nYou win!\n" << endl;
            myStructure.balance = myStructure.balance + myStructure.bet_amount;
            cout << myStructure.balance << endl;
        }
        else if (myStructure.num_guess != myStructure.n)
        {
            // display if they win or lose
            cout << "\nYou lost :(\n" << endl;
            cout << "The winning number was " << myStructure.n << "\n" << endl;
            myStructure.balance = myStructure.balance - myStructure.bet_amount;
        }
        else
        {
            // display if they win or lose
            cout << "Sorry, there was a error" << endl;
        }
        // display there remaining balance
        cout << "\nYour remaining balance is: "
             << "$" << myStructure.balance << endl;

        if(myStructure.balance == 0){
            cout << "\nYou have no more money to play:(\n" << endl;
            break;
        }

        // ask if they want to play again
        cout << "\nWould you like to play again? y/n" << endl;
        cin >> myStructure.response;


        } while (myStructure.response == 'Y' || myStructure.response == 'y');

        cout << "Thanks for playing!" << endl;

    return 0;
}