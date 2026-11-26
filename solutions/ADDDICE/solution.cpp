#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;     // Uses the standard namespace

// Function to solve a single test case
void solve() {
    int X; // Declare an integer variable X to store the first dice roll
    cin >> X; // Read the value of X from standard input

    // The sum of both dice must be 9.
    // If the first die shows X, the second die must show Y = 9 - X.
    // A standard die has faces numbered from 1 to 6.
    // So, Y must be between 1 and 6 (inclusive).
    //
    // Condition 1: Y >= 1  =>  9 - X >= 1  =>  8 >= X  =>  X <= 8
    // Condition 2: Y <= 6  =>  9 - X <= 6  =>  3 <= X
    //
    // Combining these, for Y to be a valid die roll, X must satisfy 3 <= X <= 8.
    // The problem constraints state that 1 <= X <= 6.
    //
    // The intersection of the range [1, 6] (from problem constraints)
    // and [3, 8] (from our derived conditions) is [3, 6].
    //
    // Therefore, if X is 3, 4, 5, or 6, it is possible. Otherwise (if X is 1 or 2), it is not.
    // This condition simplifies to checking if X is greater than or equal to 3.

    if (X >= 3) {
        cout << "Yes\n"; // If X is 3 or more, it's possible for the second die to make the sum 9.
    } else {
        cout << "No\n"; // If X is 1 or 2, the required second die roll (8 or 7) is not possible.
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement "The first and only line of each test case contains a single integer X."
    // implies there is only ONE test case, and X is on that line.
    // It does NOT imply reading 't' first for multiple test cases.
    // The previous attempt incorrectly assumed multiple test cases by reading 't'.
    // Removing the 't' variable and the loop.
    solve(); // Call the solve function for the single test case

    return 0; // Indicate successful execution
}