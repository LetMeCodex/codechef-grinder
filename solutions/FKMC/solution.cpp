#include <bits/stdc++.h> // Includes most standard libraries, as requested

// Using the standard namespace as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the length of the string
    string s;
    cin >> s; // Read the binary string

    int total_ones = 0; // Stores the count of '1's initially present in the string
    int max_consecutive_zeros = 0; // Stores the maximum length of a contiguous block of '0's found
    int current_consecutive_zeros = 0; // Stores the length of the current contiguous block of '0's

    // Iterate through the string to count '1's and find the longest block of '0's
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            total_ones++; // Increment count of '1's
            // If a '1' is encountered, it breaks any ongoing sequence of '0's.
            // So, reset the current consecutive zeros count.
            current_consecutive_zeros = 0;
        } else { // s[i] == '0'
            current_consecutive_zeros++; // Increment current consecutive zeros count
            // Update the maximum consecutive zeros found so far
            max_consecutive_zeros = max(max_consecutive_zeros, current_consecutive_zeros);
        }
    }

    // The maximum number of days Alice will be marked present is the sum of:
    // 1. Days she was already present (total_ones).
    // 2. Days she can convert from absent to present using one operation (max_consecutive_zeros).
    cout << total_ones + max_consecutive_zeros << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from being flushed before each cin operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}