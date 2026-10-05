#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace, as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y;
    // Read the number of ones (X) and twos (Y)
    cin >> X >> Y;

    // A string to build the palindrome
    string result = "";
    // Reserve space to avoid reallocations. For max length 10, this is a minor optimization.
    result.reserve(X + Y); 

    // The strategy to form the smallest palindrome is to place '1's first
    // in the left half, followed by '2's.
    // Since X and Y are even, the total length (X+Y) is also even.
    // The palindrome will be formed by a left half and its reverse.
    // If the left half uses X/2 ones and Y/2 twos, the total will be X ones and Y twos.

    // 1. Append X/2 ones to form the initial part of the left half
    for (int i = 0; i < X / 2; ++i) {
        result += '1';
    }

    // 2. Append Y/2 twos to complete the left half
    for (int i = 0; i < Y / 2; ++i) {
        result += '2';
    }

    // Now, append the reverse of the left half.
    // The reverse of (X/2 ones followed by Y/2 twos) is (Y/2 twos followed by X/2 ones).

    // 3. Append Y/2 twos for the first part of the right half (mirroring the '2's from left half)
    for (int i = 0; i < Y / 2; ++i) {
        result += '2';
    }

    // 4. Append X/2 ones for the second part of the right half (mirroring the '1's from left half)
    for (int i = 0; i < X / 2; ++i) {
        result += '1';
    }

    // Output the constructed palindrome followed by a newline
    cout << result << "\n";
}

int main() {
    // Enable fast I/O operations as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve();
    }

    return 0;
}