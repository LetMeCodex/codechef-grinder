#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use standard namespace

// Function for fast I/O
void fast_io() {
    ios_base::sync_with_stdio(false); // Untie C-style I/O from C++ streams
    cin.tie(NULL);                     // Untie cin from cout
}

void solve() {
    int n;
    cin >> n; // Read the number of table legs
    vector<int> w(n); // Vector to store leg strengths. int is sufficient for individual W_i.
    for (int i = 0; i < n; ++i) {
        cin >> w[i]; // Read each leg strength
    }

    sort(w.begin(), w.end()); // Sort the leg strengths in non-decreasing order

    long long max_possible_weight = 0; // Initialize maximum possible weight to 0.
                                       // Use long long to prevent overflow, as N*W_i can be up to 2e9.

    // Iterate through each leg strength to consider it as the minimum strength in a subset
    for (int i = 0; i < n; ++i) {
        // If w[i] is chosen as the minimum strength leg,
        // we should include all legs with strength >= w[i] to maximize the total weight.
        // Since 'w' is sorted, these legs are w[i], w[i+1], ..., w[n-1].
        // The number of such legs is (n - i).
        long long current_legs_count = n - i;
        long long current_min_strength = w[i]; // Casts int to long long for multiplication
        
        // Calculate the total weight this specific configuration can bear
        long long current_possible_weight = current_legs_count * current_min_strength;
        
        // Update the overall maximum possible weight
        max_possible_weight = max(max_possible_weight, current_possible_weight);
    }
    
    cout << max_possible_weight << "\n"; // Output the result for the current test case
}

int main() {
    fast_io(); // Call the fast I/O function
    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Solve the current test case
    }
    return 0; // Indicate successful execution
}