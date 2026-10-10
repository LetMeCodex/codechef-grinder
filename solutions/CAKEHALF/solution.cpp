#include <bits/stdc++.h> // Includes all standard libraries as per problem instructions

// Use the entire std namespace as requested by problem instructions.
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B;
    cin >> A >> B; // Read Alice's and Bob's initial slices

    int total_eaten_slices = 0; // Initialize total slices eaten by Charlie

    // Continue the process as long as Alice and Bob have different numbers of slices
    while (A != B) {
        if (A > B) {
            // Alice has more slices. Charlie eats half of Alice's slices, rounded up.
            // (X + 1) / 2 calculates ceil(X / 2.0) using integer division for positive X.
            int slices_to_eat = (A + 1) / 2;
            total_eaten_slices += slices_to_eat; // Add to total eaten
            A -= slices_to_eat; // Update Alice's slices
        } else { // B > A
            // Bob has more slices. Charlie eats half of Bob's slices, rounded up.
            int slices_to_eat = (B + 1) / 2;
            total_eaten_slices += slices_to_eat; // Add to total eaten
            B -= slices_to_eat; // Update Bob's slices
        }
    }

    // Output the total slices Charlie ate for this test case
    cout << total_eaten_slices << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}