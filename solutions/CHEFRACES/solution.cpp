#include <bits/stdc++.h> // Required header for competitive programming

// Required namespace
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y, A, B;
    // Read the four integers for Chef's races (X, Y) and Rival's races (A, B)
    cin >> X >> Y >> A >> B;

    int gold_medals = 0; // Initialize counter for gold medals

    // Check if Chef can win race X
    // Chef wins race X if the arch-rival is not participating in race X
    // This means X must not be A AND X must not be B
    if (X != A && X != B) {
        gold_medals++; // If Chef can win, increment the medal count
    }

    // Check if Chef can win race Y
    // Chef wins race Y if the arch-rival is not participating in race Y
    // This means Y must not be A AND Y must not be B
    if (Y != A && Y != B) {
        gold_medals++; // If Chef can win, increment the medal count
    }

    // Print the total number of gold medals Chef can win for this test case
    cout << gold_medals << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
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