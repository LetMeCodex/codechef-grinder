#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the length of the array
    
    // Edge case: If N is 1, the array already has all elements equal.
    if (n == 1) {
        int val;
        cin >> val; // Read the single element (and discard, as it doesn't affect the answer)
        cout << "Yes\n";
        return; // Move to the next test case
    }
    
    // For N > 1, the first and last elements (A_1 and A_N) cannot be changed
    // because the operation requires 1 < i < N (0-indexed: 0 < i < N-1).
    // This means A[0] and A[N-1] are fixed.
    // All elements must eventually become equal to the minimum value in the initial array.
    // If A[0] or A[N-1] is not equal to this minimum value, it's impossible.
    
    int first_val;
    cin >> first_val; // Read A[0]
    
    int min_val = first_val; // Initialize minimum value found so far
    
    // Read elements from A[1] to A[N-2] (inclusive, 0-indexed)
    // and update min_val.
    // This loop runs N-2 times. If N=2, this loop does not run (i=1 to 0).
    for (int i = 1; i < n - 1; ++i) {
        int current_val;
        cin >> current_val;
        min_val = min(min_val, current_val);
    }
    
    int last_val;
    cin >> last_val; // Read A[N-1]
    min_val = min(min_val, last_val); // Update min_val with the last element
    
    // Check if the first and last elements are equal to the overall minimum.
    if (first_val == min_val && last_val == min_val) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    
    return 0; // Indicate successful execution
}