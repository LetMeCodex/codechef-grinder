#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace as requested by the problem statement
using namespace std;

void solve() {
    // Declare variables to store the input values.
    // Using 'long long' to be absolutely safe against potential integer overflow,
    // although for the given constraints (A, B, X, Y <= 1000),
    // their products (up to 1000 * 1000 = 1,000,000) would fit within a standard 'int'.
    long long A, B, X, Y;

    // Read the four space-separated integers for the current test case.
    cin >> A >> B >> X >> Y;

    // Calculate the total power required by Chefland over B years.
    // This is A units per year multiplied by B years.
    long long required_power = A * B;

    // Calculate the total power that can be generated from the available Helium-3.
    // This is X grams multiplied by Y units per gram.
    long long available_power = X * Y;

    // Check if the available power is sufficient to meet the required power.
    // The project gets funded if available_power is greater than or equal to required_power.
    if (available_power >= required_power) {
        // If sufficient, print "Yes".
        cout << "Yes\n";
    } else {
        // Otherwise, print "No".
        cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}