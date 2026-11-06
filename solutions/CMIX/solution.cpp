#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

using namespace std; // Standard namespace for convenience

void solve() {
    int N;
    cin >> N;
    
    // Using long long for V and A to be absolutely safe, though int would suffice for values up to 1000.
    // The product A[i] * V[j] can be up to 1000 * 1000 = 1,000,000.
    // The sum (A[i] * V[j]) + (V[i] * A[j]) can be up to 2,000,000.
    // These fit in a standard 32-bit signed int (max ~2*10^9).
    // However, using long long for the result 'current_strength' and 'max_strength' is good practice
    // to prevent overflow if intermediate products exceed int limits, or if constraints were slightly larger.
    vector<long long> V(N); // Vector to store volatilities
    vector<long long> A(N); // Vector to store strengths
    
    // Read spell data
    for (int i = 0; i < N; ++i) {
        cin >> V[i] >> A[i];
    }
    
    long long max_strength = 0; // Initialize max_strength to 0. All combined strengths will be positive.
    
    // Iterate through all unique pairs of spells (i, j) where i < j
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // Calculate combined strength for spells i and j
            long long current_strength = (A[i] * V[j]) + (V[i] * A[j]);
            
            // Update max_strength if current_strength is greater
            max_strength = max(max_strength, current_strength);
        }
    }
    
    // Output the maximum strength for the current test case
    cout << max_strength << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }
    
    return 0; // Indicate successful execution
}