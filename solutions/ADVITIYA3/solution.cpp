#include <bits/stdc++.h> // Includes iostream, algorithm, limits, etc.

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    long long N, K; // N: number of cookie jars, K: number of children
    cin >> N >> K;
    
    // Initialize min_wasted_cookies to a very large value.
    // This ensures any valid remainder (0 to K-1) will be smaller.
    long long min_wasted_cookies = numeric_limits<long long>::max();
    
    // Flag to track if we found at least one jar from which distribution is possible.
    bool possible_distribution_found = false;
    
    // Iterate through each of the N cookie jars
    for (int i = 0; i < N; ++i) {
        long long A_i; // Number of cookies in the i-th jar
        cin >> A_i;
        
        // Condition: Each child must receive at least 1 cookie.
        // This implies that the total cookies in the jar (A_i) must be at least K.
        if (A_i >= K) {
            // If A_i >= K, it's possible to distribute cookies.
            // Each child receives A_i / K cookies (integer division).
            // The number of cookies wasted is the remainder: A_i % K.
            long long current_wasted = A_i % K;
            
            // Update the minimum wasted cookies found so far
            min_wasted_cookies = min(min_wasted_cookies, current_wasted);
            
            // Mark that we have found at least one possible distribution
            possible_distribution_found = true;
        }
    }
    
    // After checking all jars, output the result
    if (possible_distribution_found) {
        cout << min_wasted_cookies << "\n";
    } else {
        // If no jar allowed for a valid distribution, print -1
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }
    
    return 0;
}