#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Use the standard namespace

void solve() {
    int N, K;
    cin >> N >> K;

    // The condition S_i != S_{i+1} means the string must alternate between '0' and '1'.
    // There are two possible patterns for such a string:
    // 1. Starts with '0': S = "010101..."
    // 2. Starts with '1': S = "101010..."

    // Let's analyze the number of '1's (which is K) for each pattern.

    // Pattern 1: String starts with '0' (e.g., "0", "01", "010", "0101", "01010")
    // The number of '1's in this pattern is floor(N/2).
    // In C++ integer division, N / 2 computes floor(N/2) for positive N.
    int k_if_starts_with_0 = N / 2;

    // Pattern 2: String starts with '1' (e.g., "1", "10", "101", "1010", "10101")
    // The number of '1's in this pattern is ceil(N/2).
    // In C++ integer arithmetic, ceil(N/2) for positive N can be calculated as (N + 1) / 2.
    int k_if_starts_with_1 = (N + 1) / 2;

    // A valid binary string exists if and only if the given K matches one of these two possible counts of '1's.
    if (K == k_if_starts_with_0 || K == k_if_starts_with_1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}