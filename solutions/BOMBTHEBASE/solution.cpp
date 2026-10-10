#include <bits/stdc++.h> // Standard header for competitive programming in C++. Includes iostream, vector, algorithm, etc.

// Using namespace std; is a common practice in competitive programming to avoid repeatedly typing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N; // Number of houses
    long long X; // Attack strength of the bomb. Using long long for safety, though int (32-bit) would suffice for 10^9.
    cin >> N >> X;

    int max_destroyed_houses = 0; // This variable will store the maximum number of houses that can be destroyed.
                                  // Initialized to 0, in case no house can be destroyed.

    // Iterate through each house from 1 to N (using 0-based indexing for array A, so i from 0 to N-1).
    for (int i = 0; i < N; ++i) {
        long long A_i; // Defence strength of the i-th house. Using long long for safety.
        cin >> A_i;

        // Check if the current house (i+1) can be destroyed by the bomb.
        // A house is destroyed if its defence A_i is strictly less than the bomb's attack strength X.
        if (A_i < X) {
            // If house (i+1) can be destroyed, then according to the problem statement,
            // all houses with indices j such that 1 <= j < (i+1) also get destroyed.
            // This means houses 1, 2, ..., (i+1) are all destroyed.
            // The total number of destroyed houses would be (i+1).
            // Since we want to find the MAXIMUM number of houses destroyed,
            // and we are iterating from the first house to the last,
            // any time we find a house (i+1) that can be destroyed,
            // it means we can potentially destroy (i+1) houses.
            // By continuously updating max_destroyed_houses with (i+1),
            // the final value will be the largest (i+1) for which A_i < X.
            max_destroyed_houses = i + 1;
        }
    }

    // Output the maximum number of houses that can be destroyed for this test case.
    cout << max_destroyed_houses << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}