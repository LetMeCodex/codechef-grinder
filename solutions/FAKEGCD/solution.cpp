#include <bits/stdc++.h> // Required header for competitive programming on CodeChef

// Use the standard namespace as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read N for the current test case

    // The problem asks for a permutation A of values from 1 to N
    // such that gcd([1+A_1, 2+A_2, ..., N+A_N]) > 1.
    //
    // A simple and effective strategy is to make all terms (i + A_i) even.
    // If all terms are even, their GCD will be at least 2, which satisfies the condition (> 1).
    //
    // For (i + A_i) to be even, i and A_i must have the same parity.
    // That is, if i is odd, A_i must be odd.
    // If i is even, A_i must be even.
    //
    // The simplest permutation that achieves this is A_i = i for all i from 1 to N.
    // This is a valid permutation of values from 1 to N.
    //
    // With A_i = i, the terms become (i + A_i) = (i + i) = 2*i.
    // The sequence is [2*1, 2*2, 2*3, ..., 2*N].
    // All elements in this sequence are even.
    // The GCD of this sequence is gcd([2, 4, 6, ..., 2N]) = 2 * gcd([1, 2, 3, ..., N]).
    // Since 1 is present in [1, 2, 3, ..., N], gcd([1, 2, 3, ..., N]) = 1.
    // Therefore, gcd([2, 4, 6, ..., 2N]) = 2 * 1 = 2.
    // Since 2 > 1, this permutation satisfies the condition.
    //
    // The problem states that any valid permutation is acceptable.
    // Thus, printing 1 2 ... N is a correct and optimal solution.

    for (int i = 1; i <= N; ++i) {
        // Print the current number i.
        // Add a space after it unless it's the last number in the sequence.
        cout << i << (i == N ? "" : " ");
    }
    cout << "\n"; // Print a newline character after each test case's output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded).
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}