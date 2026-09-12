#include <iostream> // Required for standard input/output operations

// It's common in competitive programming to include <bits/stdc++.h>
// which is a precompiled header that includes most standard library headers.
// For this problem, <iostream> is sufficient.
// using namespace std; // This line is often used to avoid typing std:: repeatedly.
                      // For clarity and best practice, I'll use std:: prefix.

// Function to solve a single test case
void solve() {
    int A, B, C;
    // Read the three side lengths for the current test case
    std::cin >> A >> B >> C;

    // A triangle is scalene if all three sides are distinct.
    // The problem guarantees that the sides are given in non-decreasing order: A <= B <= C.
    //
    // If A, B, and C are distinct, it means A < B < C.
    // This implies two conditions must hold:
    // 1. A is not equal to B (A != B)
    // 2. B is not equal to C (B != C)
    //
    // If both A != B AND B != C are true, then A < B and B < C, which means A < B < C.
    // In this case, all three sides are distinct, and the triangle is scalene.
    //
    // If either A == B or B == C (or both), then at least two sides are equal,
    // and the triangle is not scalene.
    if (A != B && B != C) {
        std::cout << "YES\n"; // Output YES if scalene
    } else {
        std::cout << "NO\n";  // Output NO otherwise
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded)
    // on problems with large inputs, though for T=100 and small integers, it's not strictly
    // necessary but good practice.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    // Read the number of test cases
    std::cin >> T;
    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful execution
}