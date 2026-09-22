#include <bits/stdc++.h> // Includes common headers like iostream

// Use the standard namespace to avoid writing std:: before standard library elements
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables to store Bob's money (X), cost of apples (A), and cost of oranges (B).
    // According to constraints (1 <= X, A, B <= 10^5), 'int' is sufficient.
    int X, A, B;

    // Read Bob's money from the first line of input.
    cin >> X;

    // Read the costs of apples and oranges from the second line of input.
    cin >> A >> B;

    // Calculate the total cost required to buy 1 kg of apples and 1 kg of oranges.
    int total_cost_for_both = A + B;

    // Check if Bob has enough money (X) to cover the total cost.
    if (X >= total_cost_for_both) {
        // If Bob has enough money, print "Yes".
        cout << "Yes\n";
    } else {
        // Otherwise, Bob does not have enough money, print "No".
        cout << "No\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}