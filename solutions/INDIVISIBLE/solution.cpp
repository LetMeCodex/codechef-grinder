#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B, C;
    // Read the three integers for the current test case
    cin >> A >> B >> C;

    // Iterate through possible values of K.
    // K must be a positive integer strictly less than 100, so K ranges from 1 to 99.
    // K=1 always divides any positive integer, so it can never satisfy the condition.
    // Thus, we can start checking from K=2.
    for (int K = 2; K < 100; ++K) {
        // Check if K does not divide A AND K does not divide B AND K does not divide C
        if (A % K != 0 && B % K != 0 && C % K != 0) {
            // If all conditions are met, K is a valid answer.
            // Print K followed by a newline character.
            // Then, return from the function as any valid K is acceptable and we found one.
            cout << K << "\n";
            return;
        }
    }
    // The problem statement guarantees that a valid K will always exist under the given constraints.
    // Therefore, the loop will always find a K and return, so this line should theoretically not be reached.
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio library,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}