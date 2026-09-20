#include <bits/stdc++.h> // Includes common standard libraries like iostream

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y;
    // Read the tastiness of one bar of chocolate (X) and one piece of candy (Y)
    cin >> X >> Y;

    // Calculate the total tastiness for a packet of chocolate
    // One packet contains 2 bars, each with tastiness X.
    int chocolate_tastiness = 2 * X;

    // Calculate the total tastiness for a packet of candy
    // One packet contains 5 pieces, each with tastiness Y.
    int candy_tastiness = 5 * Y;

    // Compare the total tastiness values to decide which packet is better
    if (chocolate_tastiness > candy_tastiness) {
        // If chocolate packet is tastier
        cout << "Chocolate\n";
    } else if (candy_tastiness > chocolate_tastiness) {
        // If candy packet is tastier
        cout << "Candy\n";
    } else {
        // If both packets have the same tastiness
        cout << "Either\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}