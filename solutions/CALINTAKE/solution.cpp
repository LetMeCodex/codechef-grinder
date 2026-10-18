#include <bits/stdc++.h> // Includes iostream and other standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables to store the input values.
    int X, Y, Z;

    // Read the three integers X, Y, and Z from standard input.
    cin >> X >> Y >> Z;

    // Calculate the total calories Chef has already consumed.
    // This is the product of the number of sweets (Y) and calories per sweet (Z).
    int consumed_calories = Y * Z;

    // Check if the consumed calories exceed the daily limit X.
    if (consumed_calories > X) {
        // If Chef has exceeded the limit, print -1 as required.
        cout << -1 << "\n";
    } else {
        // If Chef has not exceeded the limit, calculate the remaining calories
        // he can eat by subtracting consumed calories from the limit.
        // Then, print this remaining amount.
        cout << X - consumed_calories << "\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}