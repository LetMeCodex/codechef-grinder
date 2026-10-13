#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement's "Input Format" section specifies:
    // "The first and only line of input contains a single integer X."
    // This indicates that there is only one test case per execution.
    // General instructions about multiple test cases (e.g., `int t; cin >> t; while(t--)`)
    // are overridden by the specific input format for this problem.

    int X; // Declare an integer variable to store the input X
    cin >> X; // Read the value of X from standard input

    // The problem states that all even-numbered channels stopped working.
    // This means only odd-numbered channels are still working.
    // We need to count the number of odd integers from 1 up to X (inclusive).

    // Let's analyze the count of odd numbers:
    // If X is an even number (e.g., X = 2, 4, 6, ..., 100):
    // The odd numbers are 1, 3, 5, ..., X-1.
    // The count of these numbers is X / 2.
    // For example, if X=100, odd numbers are 1, 3, ..., 99. Count = 100 / 2 = 50.

    // If X is an odd number (e.g., X = 1, 3, 5, ..., 5):
    // The odd numbers are 1, 3, 5, ..., X.
    // The count of these numbers is (X + 1) / 2.
    // For example, if X=5, odd numbers are 1, 3, 5. Count = (5 + 1) / 2 = 3.

    // A single formula that works for both even and odd X using integer division is (X + 1) / 2:
    // If X is even (X=2k): (2k + 1) / 2 = k (integer division). This is X/2.
    // If X is odd (X=2k+1): ((2k+1) + 1) / 2 = (2k + 2) / 2 = k + 1 (integer division). This is (X+1)/2.

    int working_channels = (X + 1) / 2;

    // Print the calculated number of working channels, followed by a newline character.
    cout << working_channels << "\n";

    return 0; // Indicate successful program execution
}