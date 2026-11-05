#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

// Using namespace std; is common practice in competitive programming for brevity.
using namespace std; 

void solve() {
    long long X, Y; // Use long long for X and Y to be safe, though int would suffice for input values based on constraints.
    cin >> X >> Y;

    long long max_amount = 0; // Initialize max_amount to 0.

    // Iterate through all possible counts of 'add 1000' operations (k).
    // The number of additions k can range from 0 to Y.
    // The remaining (Y - k) operations will be 'double' operations.
    for (long long k = 0; k <= Y; ++k) {
        // Calculate amount after k additions of 1000.
        // Use 1000LL to ensure the multiplication k * 1000 is done using long long arithmetic
        // before adding to X, preventing potential intermediate overflow.
        long long current_amount_after_additions = X + k * 1000LL; 
        
        // Calculate the number of doubling operations remaining.
        long long num_doublings = Y - k;
        
        // Calculate the doubling factor (2 raised to the power of num_doublings).
        // Use 1LL to ensure the bit shift operates on a long long, preventing overflow
        // if num_doublings was large (e.g., > 30 for int).
        long long doubling_factor = 1LL << num_doublings; 
        
        // Calculate the total amount for this specific strategy (k additions, Y-k doublings).
        long long total_amount = current_amount_after_additions * doubling_factor;
        
        // Update the maximum amount found so far.
        max_amount = max(max_amount, total_amount);
    }

    cout << max_amount << "\n"; // Output the maximum amount for the current test case.
}

int main() {
    // Fast I/O setup. Unties cin/cout from C standard streams and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}