#include <bits/stdc++.h> // Includes most standard libraries

// It's common practice in competitive programming to use the entire std namespace
// to avoid repeatedly typing std::.
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the permutation
    
    // Declare a vector to store the permutation P
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i]; // Read elements of the permutation
    }

    int balanced_positions_count = 0; // Initialize counter for balanced positions

    // Iterate through each position i from 0 to N-1
    for (int i = 0; i < N; ++i) {
        int current_val = P[i]; // The value at the current position
        
        // Calculate L_i: number of elements smaller than P_i to its left
        int L_i = 0;
        // Iterate through elements to the left of P[i] (indices 0 to i-1)
        for (int j = 0; j < i; ++j) {
            if (P[j] < current_val) {
                L_i++; // Increment if P[j] is smaller
            }
        }
        
        // Calculate R_i: number of elements greater than P_i to its right
        int R_i = 0;
        // Iterate through elements to the right of P[i] (indices i+1 to N-1)
        for (int j = i + 1; j < N; ++j) {
            if (P[j] > current_val) {
                R_i++; // Increment if P[j] is greater
            }
        }
        
        // Check if L_i equals R_i
        if (L_i == R_i) {
            balanced_positions_count++; // If equal, increment the count
        }
    }
    
    // Print the total count of balanced positions for this test case
    cout << balanced_positions_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}