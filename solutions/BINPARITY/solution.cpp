#include <bits/stdc++.h> // Includes everything, including iostream and built-in functions

// Using the standard namespace as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the integer N

    // Calculate the sum of binary digits (population count) using __builtin_popcount.
    // This function efficiently counts the number of set bits (1s) in the binary representation of n.
    int sum_binary_digits = __builtin_popcount(n);

    // Check the parity of the sum of binary digits
    if (sum_binary_digits % 2 == 0) {
        // If the sum is even, output "EVEN"
        cout << "EVEN\n";
    } else {
        // If the sum is odd, output "ODD"
        cout << "ODD\n";
    }
}

int main() {
    // Enable fast I/O operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}