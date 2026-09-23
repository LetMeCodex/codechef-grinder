#include <iostream> // Required for standard input/output operations (cin, cout)
// #include <bits/stdc++.h> is a common header in competitive programming
// that includes most standard library headers.
// For this specific problem, iostream is sufficient.

// Using the entire std namespace as requested by problem instructions.
using namespace std;

void solve() {
    int X, Y; // Declare two integer variables for Chef's rating X and problem difficulty Y
    cin >> X >> Y; // Read the values of X and Y from standard input

    // The recommended practice is to solve problems with difficulty Y
    // such that Y is in the range [X, X + 200].
    // This means two conditions must be met:
    // 1. Y must be greater than or equal to X (Y >= X)
    // 2. Y must be less than or equal to X + 200 (Y <= X + 200)
    if (Y >= X && Y <= X + 200) {
        // If both conditions are true, Chef is following the recommended practice.
        cout << "YES\n";
    } else {
        // Otherwise, Chef is not following the recommended practice.
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        solve(); // Call the solve function to handle each test case
    }

    return 0; // Indicate successful program execution
}