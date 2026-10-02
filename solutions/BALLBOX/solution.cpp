#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N, K;
    cin >> N >> K; // Read the number of balls (N) and boxes (K)

    // Calculate the minimum sum of balls required to satisfy the conditions.
    // To have K distinct positive integers, the smallest possible sum is 1 + 2 + ... + K.
    // This sum is given by the formula K * (K + 1) / 2.
    // We cast K to long long before multiplication to prevent potential integer overflow
    // if K*(K+1) were to exceed the maximum value of an int, even though for K <= 10^4
    // it technically fits. N can be up to 10^9, which fits in int.
    long long min_sum_required = (long long)K * (K + 1) / 2;

    // If the total number of balls N is greater than or equal to the minimum required sum,
    // then it is possible to divide the balls as per the conditions.
    // Otherwise, it is not possible.
    if (N >= min_sum_required) {
        cout << "YES\n"; // Output YES if possible
    } else {
        cout << "NO\n";  // Output NO if not possible
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio library.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}