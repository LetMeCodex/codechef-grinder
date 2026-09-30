#include <bits/stdc++.h> // Includes most standard libraries, as requested

using namespace std; // Allows direct use of names like cin, cout, etc., as requested

// Function to solve a single test case
void solve() {
    int x; // Declare an integer variable x to store the input number
    cin >> x; // Read the value of x from standard input

    // Condition 1: If X is already divisible by 10
    // A number is divisible by 10 if its remainder when divided by 10 is 0.
    // In this case, 0 turns are needed.
    if (x % 10 == 0) {
        cout << 0 << "\n"; // Print 0 followed by a newline character
    } 
    // Condition 2: If X is not divisible by 10, but is divisible by 5
    // This implies X is an odd multiple of 5 (e.g., 5, 15, 25, 35, ...).
    // To make it divisible by 10, it needs to be divisible by both 2 and 5.
    // It already has a factor of 5. Since it's an odd number, it lacks a factor of 2.
    // Multiplying X by 2 once (1 turn) will introduce the factor of 2,
    // making it an even multiple of 5, and thus divisible by 10.
    // Example: If X = 25, after 1 turn it becomes 25 * 2 = 50, which is divisible by 10.
    else if (x % 5 == 0) {
        cout << 1 << "\n"; // Print 1 followed by a newline character
    } 
    // Condition 3: If X is not divisible by 5
    // If X does not have a factor of 5, multiplying it by 2 (which only adds factors of 2)
    // will never introduce a factor of 5. Therefore, it's impossible to make X divisible by 10.
    // Example: If X = 1, 2, 3, 4, 6, 7, 8, 9, etc., it will never become divisible by 5.
    else {
        cout << -1 << "\n"; // Print -1 followed by a newline character
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    cin.tie(NULL); // Prevents cin from flushing cout before each input operation

    int t; // Declare an integer variable t for the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}