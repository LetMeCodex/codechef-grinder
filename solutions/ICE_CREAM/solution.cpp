#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables X and Y to store the input values.
    // X: cost of one ice cream
    // Y: money Chef has
    int X, Y;

    // Read the two space-separated integers from standard input.
    // According to the problem statement, this is the only line of input.
    cin >> X >> Y;

    // Calculate the total cost required to buy two ice creams.
    // Each ice cream costs X, so two ice creams will cost 2 * X.
    // Given constraints (1 <= X <= 100), 2 * X will be at most 200,
    // which fits comfortably within an 'int' type, so no overflow issues.
    int total_cost_for_two = 2 * X;

    // Check if Chef has enough money (Y) to cover the total cost.
    // If Y is greater than or equal to total_cost_for_two, Chef can buy them.
    if (Y >= total_cost_for_two) {
        // If Chef can buy, print "YES".
        // Using "\n" for a newline character is generally preferred over std::endl
        // in competitive programming for performance reasons, as std::endl also flushes the buffer.
        cout << "YES\n";
    } else {
        // Otherwise, Chef does not have enough money, so print "NO".
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}