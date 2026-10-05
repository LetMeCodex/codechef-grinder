#include <bits/stdc++.h> // Required header

// Required namespace
using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement specifies: "The first and only line contains a single integer X".
    // This indicates a single test case, not multiple test cases.
    // Therefore, no loop for 't' test cases is needed.

    int X; // Declare an integer variable to store the price of the cake
    cin >> X; // Read the price X from standard input

    int effective_amount; // Declare an integer variable to store the calculated effective amount

    // Apply Chef's cashback policy:
    // If the purchase amount (X) is at least 200 rupees, a 50 rupee discount is applied.
    if (X >= 200) {
        effective_amount = X - 50; // Calculate the amount after discount
    } else {
        // If the purchase amount is less than 200 rupees, no discount is applied.
        effective_amount = X; // The effective amount is the original price
    }

    // Output the effective amount paid by the customer, followed by a newline character.
    cout << effective_amount << "\n";

    return 0; // Indicate successful program execution
}