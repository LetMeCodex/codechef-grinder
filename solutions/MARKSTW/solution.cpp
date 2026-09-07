#include <iostream> // Specific include for cin/cout, instead of bits/stdc++.h
// #include <bits/stdc++.h> // Can still use this, but iostream is more precise for this problem
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y;
    // Read Alice's score (X) and Bob's score (Y)
    cin >> X >> Y;

    // Alice is happy if her score X is at least twice Bob's score Y.
    // This condition can be written as X >= 2 * Y.
    if (X >= 2 * Y) {
        // If the condition is met, Alice is happy.
        cout << "Yes\n";
    } else {
        // Otherwise, Alice is not happy.
        cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // According to the problem statement's "Input Format",
    // there is only one test case per execution.
    // We do NOT read a 't' for the number of test cases.
    solve(); // Call the solve function once for the single test case

    return 0; // Indicate successful execution
}