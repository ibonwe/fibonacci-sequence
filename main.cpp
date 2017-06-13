#include <iostream>
using namespace std;

/**
 * The purpose of this struct is to define an invalid fibonacci amount exception
 *
 * @author Chad Petersen
 */
struct InvalidFibonacciAmount : public exception {
    const char * message() const throw() {
        return "An invalid amount of fibonacci numbers requested";
    }
};

/**
 * The purpose of this method is to display a given amount of numbers
 * that are within the fibonacci sequence.
 *
 * @author Chad Petersen
 * @param  int amount An amount of fibonacci numbers
 */
void fibonacciSequence(int amount) {
    if (amount < 1 || amount > 45)
        throw InvalidFibonacciAmount();

    int fibonacci[] = {0, 1};

    for (int i = 0; i < amount - 1; i++) {
        fibonacci[i%2] = fibonacci[0] + fibonacci[1];

        cout << fibonacci[!(i%2)] << ", ";
    }

    cout << max(fibonacci[0], fibonacci[1]) << endl;
}

/**
 * The purpose of this method is to manage user input in order to
 * determine the amount fibonacci numbers to display.
 *
 * @author Chad Petersen
 * @return Execution status code
 */
int main() {
    int amount;

    while (true) {
        cout << "Please enter an amount of fibonacci numbers to view: ";

        try {
            if (!(cin >> amount)) {
                throw InvalidFibonacciAmount();
            }

            fibonacciSequence(amount);
        } catch (InvalidFibonacciAmount& exception) {
            cout << exception.message() << endl;
        }

        cin.clear();
        cin.ignore();
    }

    return 0;
}
