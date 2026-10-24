#include <bits/stdc++.h> // Standard header for competitive programming, includes iostream, algorithm, etc.

// Using the standard namespace as per problem instructions.
using namespace std;

// Function to solve a single test case.
void solve() {
    int N; // Number of bags
    int X; // Maximum limit of coins on each bag
    int C; // Cost of performing one operation

    // Read N, X, C for the current test case.
    cin >> N >> X >> C;

    long long total_max_value = 0; // Variable to store the sum of maximum values.
                                   // Using long long to prevent potential overflow,
                                   // though for given constraints (N*X <= 100*100 = 10000),
                                   // int would likely suffice on most systems.

    // Calculate the threshold value.
    // If we perform an operation on a bag, its coins become X, and we pay C.
    // So, the net value contributed by that bag to the objective function is X - C.
    // If we don't perform an operation, the bag contributes A_i.
    // We choose the option that yields a higher value.
    int operation_net_value = X - C;

    // Iterate through each bag.
    for (int i = 0; i < N; ++i) {
        int A_i; // Coins in the i-th bag
        cin >> A_i; // Read the coins in the current bag.

        // For each bag, we decide whether to perform an operation or not.
        // If we perform an operation, the bag contributes 'operation_net_value' (X - C).
        // If we don't perform an operation, the bag contributes 'A_i'.
        // We pick the maximum of these two options for each bag.
        total_max_value += max(A_i, operation_net_value);
    }

    // Output the total maximum value for the current test case.
    cout << total_max_value << "\n";
}

// Main function to handle multiple test cases.
int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}