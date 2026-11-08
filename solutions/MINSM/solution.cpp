#include <bits/stdc++.h> // Includes iostream, vector, numeric, etc.
using namespace std; // Use standard namespace for convenience

// Function to solve a single test case
void solve() {
    int N; // Length of the array
    cin >> N; // Read N
    
    long long current_gcd_val; // Variable to store the GCD of elements processed so far
    cin >> current_gcd_val; // Read the first element A_1 and initialize current_gcd_val with it
    
    // Iterate through the remaining N-1 elements
    for (int i = 1; i < N; ++i) {
        long long val; // Variable to store the current element being read
        cin >> val; // Read the next element
        // Update current_gcd_val by taking GCD with the new element
        // std::gcd is available in C++17 via <numeric> or <bits/stdc++.h>
        current_gcd_val = std::gcd(current_gcd_val, val); 
    }
    
    // The minimum possible value for each element in the array is the overall GCD (current_gcd_val).
    // We can make all elements equal to this overall GCD.
    // Therefore, the minimum sum is N times the overall GCD.
    long long min_sum = (long long)N * current_gcd_val;
    
    // Output the minimum sum followed by a newline
    cout << min_sum << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T each iteration
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful execution
}